package com.organizadordelbumdefigurinhascontrol.pankaj;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.util.Log;
import de.hdodenhof.circleimageview.CircleImageView;

public class MainActivity extends AppCompatActivity {

    EditText edt_number;
    Button button;
    TextView txt_result;
    Button buttonMove;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.i(getString(R.string.service_demo_tag)," OnCreate First activity thread id is :" +Thread.currentThread().getId());

        edt_number = findViewById(R.id.edt_number);
        button = findViewById(R.id.button);
        txt_result = findViewById(R.id.txt_result);
        buttonMove = findViewById(R.id.buttonMove);


        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String number = edt_number.getText().toString();

                if (!TextUtils.isEmpty(number)) {
                    int finNumber = Integer.valueOf(number);

                    if (finNumber>10){
                        txt_result.setText("OK");
                    }else {
                        txt_result.setText("Not Ok");
                    }
                }
            }
        });

        buttonMove.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, SecondActivity.class);
                String one="Good Morning";
                String two="Good Evening";

                //Create the bundle
                Bundle bundle = new Bundle();

                //Add your data to bundle
                bundle.putString("ONE", one);
                bundle.putString("TWO", two);

                //Add the bundle to the intent
                intent.putExtras(bundle);

                //Fire that second activity
                startActivity(intent);
            }
        });

        /*buttonMove.setOnClickListener(v -> {
            startActivity(new Intent(MainActivity.this,SecondActivity.class));
        });*/

    }


}