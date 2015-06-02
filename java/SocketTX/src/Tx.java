/**
 * 
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
/**
 * @author TianChen
 *
 */
import java.net.Socket;
import java.net.SocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;

public class Tx {

	/**
	 * @param args
	 */
	public Socket connect;
	public SocketChannel channel;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Tx sender = new Tx();
		try {
			sender.connect = new Socket("192.168.1.100",23333);
			sender.channel = SocketChannel.open();
			sender.channel.connect(sender.connect.getRemoteSocketAddress());
			ByteBuffer sendMsg = ByteBuffer.allocate(1024);
			byte[] bytes = new String("hello Server").getBytes("utf-8");//new BufferedReader(new InputStreamReader(System.in)).readLine().getBytes();
			sendMsg.put(bytes);
			sender.channel.write(sendMsg);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		if(sender.connect.isBound()&&sender.connect.isConnected())
		{
			System.out.println("Connected Successful");
		}
		else{
			System.out.println("Connected Faild");
		}
		try {
			sender.channel.close();
			sender.connect.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
