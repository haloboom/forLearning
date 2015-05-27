package com.example.sqltest;

import android.app.Activity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;


public class MainActivity extends Activity {
	private EditText editNum,editName,editFoundName;
	private Button btnInsert,btnSelect;
	private TextView txtResult;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        editName=(EditText) findViewById(R.id.editName);
		editNum=(EditText) findViewById(R.id.editNum);
		editFoundName=(EditText) findViewById(R.id.editFoundName);
		txtResult=(TextView) findViewById(R.id.txtResult);
		btnInsert=(Button) findViewById(R.id.btnInsert);
		btnSelect=(Button) findViewById(R.id.btnSelect);
    }
}
