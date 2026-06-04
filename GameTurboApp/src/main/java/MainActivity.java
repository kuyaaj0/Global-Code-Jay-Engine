package com.game.gameturbo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.TextView;
import android.graphics.Color;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class MainActivity extends Activity {

    // Track active configuration engine: 0 = Original FNF, 1 = Psych Engine
    private int activeEngineTarget = 0; 

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_turbo); // Links layout file

        // Hook up UI visual components
        final Button btnOriginal = findViewById(R.id.btnOriginal);
        final Button btnPsych = findViewById(R.id.btnPsych);
        final Button btnLaunch = findViewById(R.id.btnLaunch);
        
        final TextView txtEngineTitle = findViewById(R.id.txtEngineTitle);
        final TextView txtEngineDesc = findViewById(R.id.txtEngineDesc);
        
        final CheckBox chkDownscroll = findViewById(R.id.chkDownscroll);
        final CheckBox chkMiddlescroll = findViewById(R.id.chkMiddlescroll);
        final CheckBox chkModcharts = findViewById(R.id.chkModcharts);

        // LEFT NAVBAR SELECTION ACTION: Original FNF Toggle
        btnOriginal.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                activeEngineTarget = 0;
                
                // Visual Navbar feedback color profiles
                btnOriginal.setBackgroundColor(Color.parseColor("#00FFCC"));
                btnOriginal.setTextColor(Color.parseColor("#111215"));
                btnPsych.setBackgroundColor(Color.parseColor("#2C2F38"));
                btnPsych.setTextColor(Color.parseColor("#AAAAAA"));
                
                // Content update actions
                txtEngineTitle.setText("Original FNF Configuration");
                txtEngineDesc.setText("Standard unmodded ruleset. Optimized for low-end hardware paths.");
                chkModcharts.setVisibility(View.GONE); // Hide Lua toggles for original FNF
            }
        });

        // LEFT NAVBAR SELECTION ACTION: Psych Engine Toggle
        btnPsych.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                activeEngineTarget = 1;
                
                // Visual Navbar feedback color profiles
                btnPsych.setBackgroundColor(Color.parseColor("#00FFCC"));
                btnPsych.setTextColor(Color.parseColor("#111215"));
                btnOriginal.setBackgroundColor(Color.parseColor("#2C2F38"));
                btnOriginal.setTextColor(Color.parseColor("#AAAAAA"));
                
                // Content update actions
                txtEngineTitle.setText("Psych Engine Configuration");
                txtEngineDesc.setText("Modded fork ruleset. Enables Sol2 Lua script processing pipelines.");
                chkModcharts.setVisibility(View.VISIBLE); // Show Lua toggles for Psych Engine
            }
        });

        // LAUNCH ACTION: Save configuration properties out to C++ file shared cache
        btnLaunch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Build a tiny runtime tracking package string
                String jsonConfigString = String.format(
                    "{\"engine\":%d,\"downscroll\":%b,\"middlescroll\":%b,\"lua_modcharts\":%b}",
                    activeEngineTarget, 
                    chkDownscroll.isChecked(), 
                    chkMiddlescroll.isChecked(),
                    chkModcharts.isChecked()
                );

                // Export to shared storage space where native C++ boot loader reads it
                File cacheFile = new File(getFilesDir(), "turbo_config.json");
                try (FileWriter writer = new FileWriter(cacheFile)) {
                    writer.write(jsonConfigString);
                } catch (IOException e) {
                    e.printStackTrace();
                }

                // Native call pipeline placeholder: launchGameEngineWindow();
            }
        });
    }
}

