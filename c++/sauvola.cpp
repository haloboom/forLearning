#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv/cv.h>
using namespace cv;
using namespace std;
Mat Sauvola(Mat& gray_img,int R,float K,int W);
int main(int argc , char** argv)
{
	cout<<"Using OpenCV3!\n";
	Mat canny,cmb;
	Mat mat = cv::imread(argv[1],0);
	imshow("gray",mat);
	canny.create(mat.size(),mat.type());
	cv::Canny(mat,canny,40,120);
	for(int i=0;i<canny.rows;++i)
	{
		unsigned char* ptr = canny.ptr<uchar>(i);
		for(int j=0;j<canny.cols;++j)
		{
			if(!ptr[j])
				ptr[j]=255;	
			else
				ptr[j]=0;
		}
	}
	imshow("canny",canny);
	Mat	img = Sauvola(mat,128,0.34,51);
	imshow("sauvola",img);
	addWeighted(canny,0.5,img,0.5,0.0,cmb);
	for(int i=0;i<cmb.rows;++i)
	{
		unsigned char* ptr = cmb.ptr<uchar>(i);
		for(int j=0;j<cmb.cols;++j)
		{
			if(ptr[j]<255 && ptr[i]>0)
				ptr[j]=0;	
		}
	}
	imshow("fi",cmb);
	waitKey(0);
	return 0;
}

Mat Sauvola(Mat& gray_img,int R,float K,int W)
{
	//当前像素点为中心的区域宽度
	const int w = W;
	//修正系数0.0-1.0
	const double k = K;
	//边界到中心点的距离
	const int whalf = w>>1;
	//图像的灰色通道二进制位权值
	const int r = R;
	//图片灰度最大值
	const int maxval=256;

	int xmin,ymin,xmax,ymax;

	int const img_width = gray_img.rows;

	int const img_height = gray_img.cols;

	unsigned long integral_img[img_width][img_height];

	unsigned long integral_sqimg[img_width][img_height];

	unsigned long rowsum_img[img_width][img_height];

	unsigned long rowsum_sqimg[img_width][img_height];

	double diagsum,idiagsum,diff;

	double sqdiagsum,sqidiagsum,sqdiff,area;

	double mean,std,threshold;

	cout<<"W:"<<img_width<<",H:"<<img_height<<endl;

	for(int j=0;j<img_height;j++)
	{
		unsigned long tmp = gray_img.at<uchar>(0,j);
		rowsum_img[0][j] = tmp;
		rowsum_sqimg[0][j] = tmp*tmp;
	}


	for(int i=1;i<img_width;i++)
	{

		for(int j=0;j<img_height;j++)
		{
			unsigned long tmp = gray_img.at<uchar>(i,j);
			//计算图像方位内任意宽度领域的灰度值之和
			rowsum_img[i][j] = rowsum_img[i-1][j]+ tmp;
			//灰度值平方之和
			rowsum_sqimg[i][j] = rowsum_sqimg[i-1][j] + tmp*tmp;
		}
	}


	for(int i=0;i<img_width;i++)
	{
		integral_img[i][0] = rowsum_img[i][0];
		integral_sqimg[i][0] = rowsum_sqimg[i][0];
	}

	for(int i=0;i<img_width;i++)
	{
		for(int j=1;j<img_height;j++)
		{
			//计算图像梵文内任意宽度区域的灰度值的积分
			integral_img[i][j] = integral_img[i][j-1] + rowsum_img[i][j];
			//计算图像范围内任意宽度区域灰度值的平方的积分
			integral_sqimg[i][j] = integral_sqimg[i][j-1] + rowsum_sqimg[i][j];
		}
	}

	//根据图片计算mean和standard deviation
	for(int i=0;i<img_width;++i)
	{
		for(int j=0;j<img_height;++j)
		{
			xmin = max(0,i-whalf);
			ymin = max(0,j-whalf);
			xmax = min(img_width-1,i+whalf);
			ymax = min(img_height-1,j+whalf);
			area = (xmax-xmin+1)*(ymax-ymin+1);
			if(area<=0)
				return gray_img;
			if(xmin==0 && ymin==0)
			{
				//原点
				diff = integral_img[xmax][ymax];
				sqdiff = integral_sqimg[xmax][ymax];
			}
			else if(xmin==0 && ymin>0)
			{
				//第一列
				diff = integral_img[xmax][ymax] - integral_img[xmax][ymin-1];
				sqdiff = integral_sqimg[xmax][ymax] - integral_sqimg[xmax][ymin-1];
			}
			else if(xmin>0 && ymin==0)
			{
				//第一行
				diff = integral_img[xmax][ymax] - integral_img[xmin-1][ymax];
				sqdiff = integral_sqimg[xmax][ymax] - integral_sqimg[xmin-1][ymax];
			}
			else
			{
				//重新设置图片
				diagsum = integral_img[xmax][ymax] + integral_img[xmin-1][ymin-1];
				idiagsum = integral_img[xmax][ymin-1] + integral_img[xmin-1][ymax];
				//以(i,j)为中心的w宽度区域内的灰度值积分
				diff = diagsum - idiagsum;
				sqdiagsum = integral_sqimg[xmax][ymax] +integral_sqimg[xmin-1][ymin-1];
				sqidiagsum = integral_sqimg[xmax][ymin-1] + integral_sqimg[xmin-1][ymax];
				//以(i,j)为中心的w宽度区域内的灰度值平方的积分
				sqdiff = sqdiagsum - sqidiagsum;
			}

			//以(i,j)为中心的w宽度区域内的灰度均值
			mean = 1.0*diff/area;

			//以(i,j)为中心的w宽度区域内的标准方差
			std = sqrt((sqdiff - diff*diff/area)/(area-1));

			//根据计算公式和(i,j)为中心点的w区域内的灰度均值与标准方差来就算当前点(i,j)的二值化阀值
			threshold = mean * (1 + k * ((1.0*std/r - 1)));

			if(threshold>maxval)
			{
				cout<<"点<"<<i<<","<<j<<">的阀值(Error):"<<threshold<<endl;
			}

			unsigned char* ptr = gray_img.ptr<uchar>(i);
			//根据当前点的阀值对当前像素点进行二值化
			if(gray_img.at<uchar>(i,j) < threshold)
			{
				ptr[j] = 0;
			}
			else
			{
				ptr[j] = maxval-1;
			}

		}
	}
	return gray_img;
}
