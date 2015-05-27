package com.example.fileexample;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

import org.apache.http.util.EncodingUtils;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

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
				write("test.txt");
			}
		});
		btnAppend.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				Append("test.txt");
			}
		});
		btnRead.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				etResult.setText(read("test.txt"));	
			}
		});
	}

	private void write(String filename)
	{
		try {
			FileOutputStream fout=openFileOutput(filename, MODE_PRIVATE);
			String str=etStr.getText().toString();
			byte[] bytes=str.getBytes();
			fout.write(bytes);
			fout.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	private void Append(String filename)
	{
		try {
			FileOutputStream fout=openFileOutput(filename, MODE_APPEND);
			String str="\n" + etStr.getText().toString();
			byte[] bytes=str.getBytes();
			fout.write(bytes);
			fout.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	private String read(String filename)
	{
		try {
			FileInputStream input=openFileInput(filename);
			byte[] buffer=new byte[1024];
			StringBuilder strbuild=new StringBuilder("");
			int hasRead=0;
			if((hasRead=input.read(buffer))>0)
			{
			strbuild.append(new String(buffer,0,hasRead));
			}
			input.close();
			return strbuild.toString();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
		
	}
}


