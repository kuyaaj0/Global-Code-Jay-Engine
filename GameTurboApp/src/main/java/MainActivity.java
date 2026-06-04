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
    private int customSafeFrames = 10; // Default accuracy window frame count

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

        // LEFT BAR SWITCH: Original FNF Mode
        btnOriginal.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                activeEngineTarget = 0;
                btnOriginal.setBackgroundColor(Color.parseColor("#00FFCC"));
                btnOriginal.setTextColor(Color.parseColor("#111215"));
                btnPsych.setBackgroundColor(Color.parseColor("#2C2F38"));
                btnPsych.setTextColor(Color.parseColor("#AAAAAA"));
                
                txtEngineTitle.setText("Original FNF Configuration");
                txtEngineDesc.setText("Standard unmodded ruleset. Optimized for low-end hardware paths.");
                chkModcharts.setVisibility(View.GONE);
            }
        });

        // LEFT BAR SWITCH: Psych Engine Mode
        btnPsych.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                activeEngineTarget = 1;
                btnPsych.setBackgroundColor(Color.parseColor("#00FFCC"));
                btnPsych.setTextColor(Color.parseColor("#111215"));
                btnOriginal.setBackgroundColor(Color.parseColor("#2C2F38"));
                btnOriginal.setTextColor(Color.parseColor("#AAAAAA"));
                
                txtEngineTitle.setText("Psych Engine Configuration");
                txtEngineDesc.setText("Modded fork ruleset. Enables Sol2 Lua script processing pipelines.");
                chkModcharts.setVisibility(View.VISIBLE);
            }
        });

        // TOP RIGHT NAVBAR PANEL: Toggle hit window frames (10 -> 12 -> 15 -> 8)
        btnSafeFrames.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (customSafeFrames == 10) customSafeFrames = 12;
                else if (customSafeFrames == 12) customSafeFrames = 15;
                else if (customSafeFrames == 15) customSafeFrames = 8;
                else customSafeFrames = 10;
                
                btnSafeFrames.setText("SAFE: " + customSafeFrames + " FRAMES");
            }
        });

        // ACTION BUTTON: Save configurations to cache
        btnLaunch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                float targetSpeed = 2.0f;
                try {
                    targetSpeed = Float.parseFloat(edtScrollSpeed.getText().toString());
                } catch(NumberFormatException e) { /* Fallback to default */ }

                String jsonConfigString = String.format(
                    "{\"engine\":%d,\"downscroll\":%b,\"middlescroll\":%b,\"lua_modcharts\":%b,\"scroll_speed\":%.2f,\"safe_frames\":%d}",
                    activeEngineTarget, 
                    chkDownscroll.isChecked(), 
                    chkMiddlescroll.isChecked(),
                    chkModcharts.isChecked(),
                    targetSpeed,
                    customSafeFrames
                );

                File cacheFile = new File(getFilesDir(), "turbo_config.json");
                try (FileWriter writer = new FileWriter(cacheFile)) {
                    writer.write(jsonConfigString);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
    }
}
