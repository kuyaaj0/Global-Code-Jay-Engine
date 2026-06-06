package com.game.gameturbo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.TextView;
import android.graphics.Color;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class MainActivity extends Activity {

    private int activeEngineTarget = 0;
    private int customSafeFrames = 10;

    // 🔥 JNI BRIDGE (MISSING PIECE FIXED)
    public native void syncAndLaunchEngine();

    static {
        System.loadLibrary("jay_engine");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_turbo);

        final Button btnOriginal = findViewById(R.id.btnOriginal);
        final Button btnPsych = findViewById(R.id.btnPsych);
        final Button btnSafeFrames = findViewById(R.id.btnSafeFrames);
        final Button btnLaunch = findViewById(R.id.btnLaunch);

        final TextView txtEngineTitle = findViewById(R.id.txtEngineTitle);
        final TextView txtEngineDesc = findViewById(R.id.txtEngineDesc);

        final EditText edtScrollSpeed = findViewById(R.id.edtScrollSpeed);
        final CheckBox chkDownscroll = findViewById(R.id.chkDownscroll);
        final CheckBox chkMiddlescroll = findViewById(R.id.chkMiddlescroll);
        final CheckBox chkModcharts = findViewById(R.id.chkModcharts);

        // LEFT: Original FNF
        btnOriginal.setOnClickListener(v -> {
            activeEngineTarget = 0;

            btnOriginal.setBackgroundColor(Color.parseColor("#00FFCC"));
            btnOriginal.setTextColor(Color.parseColor("#111215"));

            btnPsych.setBackgroundColor(Color.parseColor("#2C2F38"));
            btnPsych.setTextColor(Color.parseColor("#AAAAAA"));

            txtEngineTitle.setText("Original FNF Configuration");
            txtEngineDesc.setText("Standard unmodded ruleset. Optimized for low-end hardware paths.");

            chkModcharts.setVisibility(View.GONE);
        });

        // LEFT: Psych Engine
        btnPsych.setOnClickListener(v -> {
            activeEngineTarget = 1;

            btnPsych.setBackgroundColor(Color.parseColor("#00FFCC"));
            btnPsych.setTextColor(Color.parseColor("#111215"));

            btnOriginal.setBackgroundColor(Color.parseColor("#2C2F38"));
            btnOriginal.setTextColor(Color.parseColor("#AAAAAA"));

            txtEngineTitle.setText("Psych Engine Configuration");
            txtEngineDesc.setText("Modded fork ruleset. Enables Lua modchart processing.");

            chkModcharts.setVisibility(View.VISIBLE);
        });

        // SAFE FRAMES SWITCH
        btnSafeFrames.setOnClickListener(v -> {
            if (customSafeFrames == 10) customSafeFrames = 12;
            else if (customSafeFrames == 12) customSafeFrames = 15;
            else if (customSafeFrames == 15) customSafeFrames = 8;
            else customSafeFrames = 10;

            btnSafeFrames.setText("SAFE: " + customSafeFrames + " FRAMES");
        });

        // 🔥 LAUNCH BUTTON (FIXED PIPELINE)
        btnLaunch.setOnClickListener(v -> {

            float targetSpeed = 2.0f;

            try {
                targetSpeed = Float.parseFloat(edtScrollSpeed.getText().toString());
            } catch (Exception ignored) {}

            // Build JSON config
            String jsonConfigString =
                    "{\"engine\":" + activeEngineTarget +
                    ",\"downscroll\":" + chkDownscroll.isChecked() +
                    ",\"middlescroll\":" + chkMiddlescroll.isChecked() +
                    ",\"lua_modcharts\":" + chkModcharts.isChecked() +
                    ",\"scroll_speed\":" + String.format("%.2f", targetSpeed) +
                    ",\"safe_frames\":" + customSafeFrames +
                    "}";

            // Save file
            File cacheFile = new File(getFilesDir(), "turbo_config.json");

            try (FileWriter writer = new FileWriter(cacheFile)) {
                writer.write(jsonConfigString);
            } catch (IOException e) {
                e.printStackTrace();
            }

            // 🔥 CRITICAL FIX: CALL NATIVE ENGINE
            syncAndLaunchEngine();
        });
    }
}
