#define CL 6//五位数
typedef struct{
int N;//存取数字
char n[CL];//存取对应的字符
}HDS;
char *bubble_zx(char str[]);//正序排列字符串
char *bubble_nx(char str[]);//逆序排列字符串
void handle(HDS hds[]);//对结构数组做陷阱处理
void getxy(HDS hds[],int *x,int *y);//获取陷阱的始末位置
void init_hds(HDS *hds,int base,int i);//随机初始化五位数
void display_hds(HDS hds[],int x,int y);//打印黑洞数陷阱
int alptoint(char *str);//字符串转换成数字