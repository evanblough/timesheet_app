package org.qtproject.example.timesheethelper;
import android.graphics.drawable.Icon;
import android.app.Notification;
import android.app.NotificationManager;
import android.content.Intent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.ContextWrapper;
import android.view.ContextThemeWrapper;
import android.app.Activity;
import android.util.Log;

public class MyBroadcastReceiver extends BroadcastReceiver {

        private static final String TAG = "MyBroadcastReceiver";
        @Override
        public void onReceive(Context context, Intent intent) {
            Log.d(null,"Popping up application");
            Intent qt_app_intent = new Intent(context, NotificationClient.class);
            qt_app_intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
            context.startActivity(qt_app_intent);
        }
}
