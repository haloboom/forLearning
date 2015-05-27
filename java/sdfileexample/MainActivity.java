package com.example.sdfileexample;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {
	private Button btnWrite,btnRead,btnAppend;
	private EditText etStr,etResult;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		btnWrite=(Button) findViewById(R.id.btnWrite);
		btnRead=(Button) findViewById(R.id.btnRead);
		btnAppend=(Button) findViewById(R.id.btnAppend);
		etStr=(EditText) findViewById(R.id.etStr);
		etResult=(EditText) findViewById(R.id.etResult);
		btnWrite.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				write("sdtest.txt");
			}
		});
		btnRead.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				etResult.setText(read("sdtest.txt"));
			}
		});
		btnAppend.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				Append("sdtest.txt");
			}
		});
	}
	private String read(String filename)
	{
		try
		{
		if(Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED))
		{
			File sdCardDir=Environment.getExternalStorageDirectory();
			FileInputStream fis=new FileInputStream(sdCardDir.getCanonicalPath()+"/" + filename);
			byte[] buffer=new byte[1024];
			StringBuilder strbuild=new StringBuilder("");
			int hasRead=0;
			if((hasRead=fis.read(buffer))>0)
			{
			strbuild.append(new String(buffer,0,hasRead));
			}
			fis.close();
			return strbuild.toString();
		}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		return null;
	}
	private void write(String filename)
	{
		try {
			if(Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED))
			{
			File sdCardDir=Environment.getExternalStorageDirectory();
			FileOutputStream fos=new FileOutputStream(sdCardDir.getCanonicalPath()+"/" + filename);
			String str=etStr.getText().toString();
			byte[] bytes=str.getBytes();
			fos.write(bytes);
			fos.close();
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	private void Append(String filename)
	{
		try
		{
			if(Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED))
			{
				File sdCardDir=new File(Environment.getExternalStorageDirectory(),filename);
				BufferedWriter bw=new BufferedWriter(new FileWriter(sdCardDir, true));
				bw.write("\n" + etStr.getText().toString());
				bw.flush();
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

}
