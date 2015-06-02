/**
 * @author TianChen
 *
 */
import java.io.IOException;
import java.net.ServerSocket;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;
import java.net.Socket;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.nio.channels.ServerSocketChannel;

public class Rx extends Thread{

	/**
	 * @param args
	 */
	public ServerSocket server;
	public Socket connect;
	public SocketChannel defaultChannel;
	public boolean flag;
	
	
	
	/* (non-Javadoc)
	 * @see java.lang.Thread#run()
	 */
	@Override
	public void run() {
		// TODO Auto-generated method stub
		super.run();
		System.out.println("Server is Running:");
		try {
			server =new ServerSocket(23333);
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		while(flag)
		{
			try {
				connect = server.accept();
				this.currentThread().sleep(600);
				//defaultChannel.open();
				/*defaultChannel.connect(connect.getRemoteSocketAddress());*/
				ByteBuffer buffer =ByteBuffer.allocate(1024);
				defaultChannel = connect.getChannel();
				if(buffer.hasArray()){
				defaultChannel.read(buffer);
				byte[] bytes = new byte[1024];
				buffer.get(bytes);
				System.out.println(bytes.toString());
				}
				defaultChannel.close();
				connect.close();
				server.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (NullPointerException e) {
				//TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		System.exit(-1);		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Rx recieve = new Rx();
		String getCMD = null ;
		recieve.flag = true;
		BufferedReader command = new BufferedReader(new InputStreamReader(System.in));
		recieve.start();
	}

}
