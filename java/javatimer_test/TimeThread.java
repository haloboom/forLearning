//启动线程方法:
//继承Thread
//引用Runnable接口
public class TimeThread extends Thread{
  int time=0;
  boolean flag=true;
  public void run(){//线程体
    super.run();
    try{
      while(flag){
      this.currentThread().sleep(1000);
      time++;
      System.out.println(time+"\n");
      }
    }catch(InterruptedException e){
        e.printStackTrace();
    }
  }
  public static int main(String args[]){
    try{
      TimeThread thread = new TimeThread();
      thread.start();
      BufferedReader bt = new BufferedReader(new InputStreamReader(System.in));
      String line = br.readLine();
      if(line.equals("1")){
        thread.flag=false;
      }
      else{
        thread.flag=true;
      }
    }catch(IOException e){
      e.printStackTrace();
    }
    return 0;
  }
};
