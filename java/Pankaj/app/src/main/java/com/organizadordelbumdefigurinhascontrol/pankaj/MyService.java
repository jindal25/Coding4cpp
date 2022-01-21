package com.organizadordelbumdefigurinhascontrol.pankaj;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;
import android.widget.Toast;

public class MyService extends Service {
    public MyService() {
    }

    @Override
    public IBinder onBind(Intent intent) {
        // TODO: Return the communication channel to the service.
        throw new UnsupportedOperationException("Not yet implemented");
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.i(getString(R.string.service_demo_tag)," OnStartCommand thread id is :" +Thread.currentThread().getId());
        Toast.makeText(getApplicationContext(),"Service Started",Toast.LENGTH_SHORT).show();

        stopSelf();
        return super.onStartCommand(intent, flags, startId);
    }
}