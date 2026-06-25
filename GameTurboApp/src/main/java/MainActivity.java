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
    try {
        System.loadLibrary("jay_engine");
    } catch (UnsatisfiedLinkError e) {
        e.printStackTrace();
    }
}

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_turbo);

        final Button btnOriginal = findViewById(R.id.btnOriginal);
        final Button btnPsych = findViewById(R.id.btnPsych);
        final Button btnJay = findViewById(R.id.btnJay);
        final Button btnSafeFrames = findViewById(R.id.btnSafeFrames);
        final Button btnLaunch = findViewById(R.id.btnLaunch);
        final Button btnGameplay = findViewById(R.id.btnGameplay);
        final Button btnPerformance = findViewById(R.id.btnPerformance);
        final Button btnModcharts = findViewById(R.id.btnModcharts);
        final Button btnAbout = findViewById(R.id.btnAbout);

        final TextView txtEngineTitle = findViewById(R.id.txtEngineTitle);
        final TextView txtEngineDesc = findViewById(R.id.txtEngineDesc);
        final TextView txtSelectedEngine = findViewById(R.id.txtSelectedEngine);final TextView txtEngineVersion = findViewById(R.id.txtEngineVersion);
        final TextView txtEnginePlatform = findViewById(R.id.txtEnginePlatform);
        final TextView txtEngineCompatibility = findViewById(R.id.txtEngineCompatibility);

        final TextView txtEngineFeatures = findViewById(R.id.txtEngineFeatures);
        final TextView txtEngineNotes = findViewById(R.id.txtEngineNotes);

        final EditText edtScrollSpeed = findViewById(R.id.edtScrollSpeed);
        final CheckBox chkDownscroll = findViewById(R.id.chkDownscroll);
        final CheckBox chkMiddlescroll = findViewById(R.id.chkMiddlescroll);
        final CheckBox chkModcharts = findViewById(R.id.chkModcharts);

        final CheckBox chkPerformanceMode = findViewById(R.id.chkPerformanceMode);
        final CheckBox chkLowEndMode = findViewById(R.id.chkLowEndMode);
        final CheckBox chkMatrix4 = findViewById(R.id.chkMatrix4);
        
        final CheckBox chkEnable3D = findViewById(R.id.chkEnable3D);
        final CheckBox chkPerspective = findViewById(R.id.chkPerspective);
        final CheckBox chkMatrixTransforms = findViewById(R.id.chkMatrixTransforms);
        final CheckBox chkOptimizeLua = findViewById(R.id.chkOptimizeLua);
        final CheckBox chkNotITG = findViewById(R.id.chkNotITG);
        final CheckBox chkDepthSorting = findViewById(R.id.chkDepthSorting);

        btnGameplay.setOnClickListener(v -> {
    txtEngineTitle.setText("Gameplay Settings");
        });
        
        btnPerformance.setOnClickListener(v -> {
    txtEngineTitle.setText("Performance Settings");
        });

        btnModcharts.setOnClickListener(v -> {
    txtEngineTitle.setText("Modchart Settings");
        });

        btnAbout.setOnClickListener(v -> {
    txtEngineTitle.setText("About Jay Engine");
        });
        
        // LEFT: Original FNF
        btnOriginal.setOnClickListener(v -> {
            activeEngineTarget = 0;

            btnOriginal.setBackgroundColor(Color.parseColor("#00FFCC"));
            btnOriginal.setTextColor(Color.parseColor("#111215"));

            btnPsych.setBackgroundColor(Color.parseColor("#2C2F38"));
            btnPsych.setTextColor(Color.parseColor("#AAAAAA"));

            txtEngineTitle.setText("FNF Vanilla Configuration");
            txtEngineDesc.setText("Standard unmodded ruleset. Optimized for low-end hardware paths. this part is for official one and lua will be on notes only");

            txtSelectedEngine.setText("Selected Engine: FNF Vanilla");
            txtEngineVersion.setText("Version: v0.8.5");
            txtEnginePlatform.setText("Platform: Android");
            txtEngineCompatibility.setText("Compatibility: Stable");
            
            txtEngineFeatures.setText(
                "• Vanilla Gameplay\n" +
                "• Standard Note System\n" +
                "• Basic Lua Support"
            );

            txtEngineNotes.setText(
                "Official Friday Night Funkin build. " +
                "Focused on original gameplay experience."
            );

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
            txtEngineDesc.setText("Modded fork ruleset. Enables Lua modchart processing. optimization will come handy soon");

            txtSelectedEngine.setText("Selected Engine: Psych Engine");
            txtEngineVersion.setText("Version: v0.7.3");
            txtEnginePlatform.setText("Platform: Android");
            txtEngineCompatibility.setText("Compatibility: High");

            txtEngineFeatures.setText(
                "• Lua Modcharts\n" +
                "• Events System\n" +
                "• Custom Stages\n" +
                "• HScript Support"
            );

            txtEngineNotes.setText(
                "Most popular FNF modding engine. " +
                "Supports advanced Lua scripting."
            );
            

            chkModcharts.setVisibility(View.VISIBLE);
        });

        // LEFT: Jay Engine
        btnJay.setOnClickListener(v -> {
            activeEngineTarget = 2;

            btnPsych.setBackgroundColor(Color.parseColor("#00FFCC"));
            btnPsych.setTextColor(Color.parseColor("#111215"));

            btnOriginal.setBackgroundColor(Color.parseColor("#2C2F38"));
            btnOriginal.setTextColor(Color.parseColor("#AAAAAA"));

            txtEngineTitle.setText("Jay Engine Configuration");
            txtEngineDesc.setText("Experimental Engine, that has the modchart, and custom parts");

            txtSelectedEngine.setText("Selected Engine: Jay Engine");
            txtEngineVersion.setText("Version: Alpha");
            txtEnginePlatform.setText("Platform: Android");
            txtEngineCompatibility.setText("Compatibility: Experimental");

            txtEngineFeatures.setText(
                "• Matrix4 Pipeline\n" +
                "• 3D Modcharts\n" +
                "• Turbo Launcher\n" +
                "• Custom Rendering"
            );

            txtEngineNotes.setText(
                "Experimental engine focused on mobile optimization, " +
                "advanced rendering and future Matrix4 systems."
            );

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
                "{"
                + "\"engine\":" + activeEngineTarget
                + ",\"downscroll\":" + chkDownscroll.isChecked()
                + ",\"middlescroll\":" + chkMiddlescroll.isChecked()
                + ",\"lua_modcharts\":" + chkModcharts.isChecked()
                + ",\"scroll_speed\":" + String.format("%.2f", targetSpeed)
                + ",\"safe_frames\":" + customSafeFrames
                
                + ",\"performance_mode\":" + chkPerformanceMode.isChecked()
                + ",\"low_end_mode\":" + chkLowEndMode.isChecked()
                + ",\"matrix4_pipeline\":" + chkMatrix4.isChecked()
                
                + ",\"enable_3d\":" + chkEnable3D.isChecked()
                + ",\"perspective_camera\":" + chkPerspective.isChecked()
                + ",\"matrix_transforms\":" + chkMatrixTransforms.isChecked()
                + ",\"optimize_lua\":" + chkOptimizeLua.isChecked()
                + ",\"notitg_effects\":" + chkNotITG.isChecked()
                + ",\"depth_sorting\":" + chkDepthSorting.isChecked()

                + "}";
            // Save file
            File cacheFile = new File(getFilesDir(), "turbo_config.json");

            try (FileWriter writer = new FileWriter(cacheFile)) {
                writer.write(jsonConfigString);
            } catch (IOException e) {
                e.printStackTrace();
            }

            // 🔥 CRITICAL FIX: CALL NATIVE ENGINE
            try {
                syncAndLaunchEngine();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }
}
