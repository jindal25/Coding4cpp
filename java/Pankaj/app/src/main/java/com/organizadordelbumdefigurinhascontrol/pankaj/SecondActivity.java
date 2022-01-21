package com.organizadordelbumdefigurinhascontrol.pankaj;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.content.Intent;
import android.widget.Toast;
import android.widget.Button;


public class SecondActivity extends AppCompatActivity {
    TextView txt_result2;
    private Intent serviceIntent;
    Button btnStartService, btnStopService;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        btnStartService = findViewById(R.id.btn_startService);
        btnStartService = findViewById(R.id.btn_stopService);

        Intent intent = getIntent();
        Bundle bundle = getIntent().getExtras();
        String result = intent.getStringExtra("ONE");
        String result1 = intent.getStringExtra("TWO");

        Log.d("test", result);

        Log.i(getString(R.string.service_demo_tag)," onCreate 2nd activity thread id is :" +Thread.currentThread().getId());

        TextView txt_result2 = (TextView)findViewById(R.id.txtvres);

        txt_result2.setText(result);

        Toast.makeText(getApplicationContext(),result1,Toast.LENGTH_SHORT).show();



        btnStopService.setOnClickListener(new View.OnClickListener() {
            @OverrideserviceIntent = new Intent(getApplicationContext(),MyService.class );

        btnStartService.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    startService(serviceIntent);
                }
            });
            public void onClick(View v) {
               // stopService(serviceIntent);
            }
        });
    }


}