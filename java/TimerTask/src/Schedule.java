/**
 * @author TianChen
 *
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Schedule extends Thread{
	/**
	 * @param args
	 */
	private int count;
	public boolean flag;
	public void setCount(int count)
	{
		this.count=count;
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		super.run();
		try {
			while(flag){
			this.count++;
			System.out.println(this.count+"\n");
			this.currentThread().sleep(1000);
			}
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Schedule scdThread = new Schedule();
		scdThread.setCount(0);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		scdThread.flag=true;
		scdThread.start();
		try {
			String content = br.readLine();
			if(content.equals("x"))
			{
				scdThread.flag=false;
			}
			else
			{
				scdThread.flag=true;
			}
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
			scdThread.flag=false;
		}
	}

}
