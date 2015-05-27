package com.example.quiz;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {
	private Button btn_login;
	private TextView text_usrname,text_passwd;
	private EditText edit_usrname,edit_passwd;
	private CheckBox chkbox_remember_status;
	private SharedPreferences setting;
	private SharedPreferences.Editor editor;
	private String filename;
	private boolean isRmb;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		btn_login=(Button)findViewById(R.id.btn_login);
		text_usrname=(TextView)findViewById(R.id.text_usrname);
		text_passwd=(TextView)findViewById(R.id.text_passwd);
		edit_usrname=(EditText)findViewById(R.id.edit_usrname);
		edit_passwd=(EditText)findViewById(R.id.edit_passwd);
		setting = getSharedPreferences(filename, 0);
		editor = setting.edit();
		btn_login.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				if(edit_passwd.getText().toString().equals("admin") && edit_usrname.getText().toString().equals("admin"))
				{
					isRmb=true;
					//turn to 2nd act
					
				}
				else
				{
					isRmb=false;
					//toast notice
				}
			}
		});
	}
	//DeveloperFuncs
	public void setfilename(String filename)
	{
		this.filename=filename;
	}
}
