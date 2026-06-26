package com.game.gameturbo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.ScrollView;
import android.widget.ImageView;
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

    private View launchOverlay;
    private View launchCard;

    private void showLaunchSequence()
{
    launchOverlay.setVisibility(View.VISIBLE);

    launchCard.setAlpha(1f);

    launchOverlay.postDelayed(() -> {
        //syncAndLaunchEngine();
    }, 3000);
}

    private void scrollToSection(ScrollView scrollView, View target)
{
    scrollView.post(() ->
        scrollView.smoothScrollTo(0, target.getTop())
    );
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
        final Button btnGameplay = findViewById(R.id.btnNavGameplay);
        final Button btnPerformance = findViewById(R.id.btnNavPerformance);
        final Button btnModcharts = findViewById(R.id.btnNavModcharts);
        final Button btnAbout = findViewById(R.id.btnNavAbout);

        ScrollView mainScrollView = findViewById(R.id.mainScrollView);
        
        View sectionEngine = findViewById(R.id.sectionEngine);
        View sectionGameplay = findViewById(R.id.sectionGameplay);
        View sectionPerformance = findViewById(R.id.sectionPerformance);
        View sectionModcharts = findViewById(R.id.sectionModcharts);
        View sectionLaunch = findViewById(R.id.sectionLaunch);
        View sectionAbout = findViewById(R.id.sectionAbout);

        final TextView txtEngineTitle = findViewById(R.id.txtEngineTitle);
        final TextView txtEngineDesc = findViewById(R.id.txtEngineDesc);

        launchOverlay = findViewById(R.id.launchOverlay);
        launchCard = findViewById(R.id.launchCard);
        final TextView txtLaunchLine1 = findViewById(R.id.txtLaunchLine1);
        final TextView txtLaunchLine2 = findViewById(R.id.txtLaunchLine2);
        final TextView txtLaunchLine3 = findViewById(R.id.txtLaunchLine3);
        final TextView txtLaunchLine4 = findViewById(R.id.txtLaunchLine4);
        final TextView txtLaunchLine5 = findViewById(R.id.txtLaunchLine5);

        final ImageView imgEngineLogo = findViewById(R.id.imgEngineLogo);
        
        final TextView txtSelectedEngine = findViewById(R.id.txtSelectedEngine);
        final TextView txtEngineVersion = findViewById(R.id.txtEngineVersion);
        final TextView txtEnginePlatform = findViewById(R.id.txtEnginePlatform);
        final TextView txtEngineCompatibility = findViewById(R.id.txtEngineCompatibility);

        final TextView txtEngineFeatures = findViewById(R.id.txtEngineFeatures);
        final TextView txtEngineNotes = findViewById(R.id.txtEngineNotes);

        final TextView txtSummaryEngine = findViewById(R.id.txtSummaryEngine);
        final TextView txtSummaryGameplay = findViewById(R.id.txtSummaryGameplay);
        final TextView txtSummaryPerformance = findViewById(R.id.txtSummaryPerformance);

        final EditText edtScrollSpeed = findViewById(R.id.edtScrollSpeed);
        final CheckBox chkDownscroll = findViewById(R.id.chkDownscroll);
        final CheckBox chkMiddlescroll = findViewById(R.id.chkMiddlescroll);
        final CheckBox chkPlayOpponent = findViewById(R.id.chkPlayOpponent);
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
    scrollToSection(mainScrollView, sectionGameplay);
});

btnPerformance.setOnClickListener(v -> {
    scrollToSection(mainScrollView, sectionPerformance);
});
        
btnModcharts.setOnClickListener(v -> {
    scrollToSection(mainScrollView, sectionModcharts);
});

btnAbout.setOnClickListener(v -> {
    scrollToSection(mainScrollView, sectionAbout);
});
        
        // LEFT: Original FNF
        btnOriginal.setOnClickListener(v -> {
            activeEngineTarget = 0;

            btnOriginal.setBackgroundColor(Color.parseColor("#FFD600"));
            btnOriginal.setTextColor(Color.parseColor("#111215"));

            btnPsych.setBackgroundColor(Color.parseColor("#2C2F38"));
            btnPsych.setTextColor(Color.parseColor("#AAAAAA"));

            btnJay.setBackgroundColor(Color.parseColor("#2C2F38"));
            btnJay.setTextColor(Color.parseColor("#AAAAAA"));

            txtEngineTitle.setText("FNF Vanilla Configuration");
            txtEngineDesc.setText("Standard unmodded ruleset. Optimized for low-end hardware paths. this part is for official one and lua will be on notes only");

            imgEngineLogo.setImageResource(R.drawable.ic_fnf);
            
            txtSelectedEngine.setText("Selected Engine: FNF Vanilla");
            txtSummaryEngine.setText("Engine: FNF Vanilla");
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

            btnPsych.setBackgroundColor(Color.parseColor("#A020F0"));
            btnPsych.setTextColor(Color.parseColor("#111215"));
            
            btnOriginal.setBackgroundColor(Color.parseColor("#2C2F38"));
            btnOriginal.setTextColor(Color.parseColor("#AAAAAA"));

            btnJay.setBackgroundColor(Color.parseColor("#2C2F38"));
            btnJay.setTextColor(Color.parseColor("#AAAAAA"));
            
            txtEngineTitle.setText("Psych Engine Configuration");
            txtEngineDesc.setText("Modded fork ruleset. Enables Lua modchart processing. optimization will come handy soon");

            imgEngineLogo.setImageResource(R.drawable.ic_psych);

            txtSelectedEngine.setText("Selected Engine: Psych Engine");
            txtSummaryEngine.setText("Engine: Psych Engine");
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

            btnJay.setBackgroundColor(Color.parseColor("#00E5FF"));
            btnJay.setTextColor(Color.parseColor("#111215"));

            btnOriginal.setBackgroundColor(Color.parseColor("#2C2F38"));
            btnOriginal.setTextColor(Color.parseColor("#AAAAAA"));

            btnPsych.setBackgroundColor(Color.parseColor("#2C2F38"));
            btnPsych.setTextColor(Color.parseColor("#AAAAAA"));

            txtEngineTitle.setText("Jay Engine Configuration");
            txtEngineDesc.setText("Experimental Engine, that has the modchart, and custom parts");

            imgEngineLogo.setImageResource(R.drawable.ic_jay);
            
            txtSelectedEngine.setText("Selected Engine: Jay Engine");
            txtSummaryEngine.setText("Engine: Jay Engine");
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
                + ",\"play_opponent\":" + chkPlayOpponent.isChecked()
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
                //syncAndLaunchEngine();
                showLaunchSequence();
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }
}
