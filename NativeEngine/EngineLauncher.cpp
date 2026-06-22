#include "Renderer/Matrix4Renderer.hpp"
#include "Config/EngineConfig.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "external/json.hpp"

//#include "OriginalFunkin/FunkinSettings.hpp"
//#include "PsychEngine/ClientPrefs.hpp"

using json = nlohmann::json;

void launchSelectedEngine(const std::string& configPath) {

    std::ifstream configFile(configPath);
    if (!configFile.is_open()) {
        std::cout << "[Launcher] No config found. Defaulting to Original FNF\n";
        // FunkinO::Game::startGameplay();
        return;
    }

    json config;
    configFile >> config;

    if (config.is_null()) {
        std::cout << "[Launcher] Invalid config\n";
        return;
    }

    int chosenEngine = config.value("engine", 2);
    bool downscroll = config.value("downscroll", false);
    bool middlescroll = config.value("middlescroll", false);
    bool luaModcharts = config.value("lua_modcharts", false);
    
    bool performanceMode = config.value("performance_mode", false);
    bool lowEndMode = config.value("low_end_mode", false);
    bool matrix4Pipeline = config.value("matrix4_pipeline", false);
    
    bool enable3D = config.value("enable_3d", false);
    bool perspectiveCamera = config.value("perspective_camera", false);
    bool matrixTransforms = config.value("matrix_transforms", false);
    bool optimizeLua = config.value("optimize_lua", false);
    bool notitgEffects = config.value("notitg_effects", false);
    bool depthSorting = config.value("depth_sorting", false);

float scrollSpeed = config.value("scroll_speed", 2.0f);
int safeFrames = config.value("safe_frames", 10);

    std::cout << "========================================\n";
    std::cout << " GLOBAL CODE JAY ENGINE LAUNCHER\n";
    std::cout << "========================================\n";

    //this are the part of the string settings part
    std::cout << "[Settings]" << std::endl;
    std::cout << "Scroll Speed: " << scrollSpeed << std::endl;
    std::cout << "Safe Frames: " << safeFrames << std::endl;
    
    std::cout << "Performance Mode: " << performanceMode << std::endl;
    std::cout << "Low End Mode: " << lowEndMode << std::endl;
    std::cout << "Matrix4 Pipeline: " << matrix4Pipeline << std::endl;
    
    std::cout << "3D Rendering: " << enable3D << std::endl;
    std::cout << "Perspective Camera: " << perspectiveCamera << std::endl;
    std::cout << "Matrix Transforms: " << matrixTransforms << std::endl;
    std::cout << "Optimize Lua: " << optimizeLua << std::endl;
    std::cout << "NotITG Effects: " << notitgEffects << std::endl;
    std::cout << "Depth Sorting: " << depthSorting << std::endl;

    if (EngineConfig::matrix4Pipeline)
{
    std::cout << "[Jay Engine] Matrix4 Pipeline Enabled." << std::endl;

    //Matrix4Renderer::initialize();
}

    //on the vanilla part is referencing to the original or official one
    if (chosenEngine == 0) {

        std::cout << "[Status] Friday Night Funkin Vanilla Selected\n";

        //Funkin::Game::funkinSetting::downscroll = downscroll;
       // Funkin::Game::funkinSetting::middlescroll = middlescroll;

        // TODO: REAL ENGINE START
        // Funkin::Game::startGameplay();

    } 
    else if (chosenEngine == 1) {

        std::cout << "[Status] Psych Engine Selected\n";

       // Psych::Backend::ClientPrefs::downScroll = downscroll;
       // Psych::Backend::ClientPrefs::middleScroll = middlescroll;

        // TODO: REAL ENGINE START
        // Psych::Backend::initLuaModcharts();

    } 
    else if (chosenEngine == 2) {
        std::cout << "[status] Jay Engine Selected\n";
        // Settings on my engine is still coming soon
    }
    
    else {
        std::cout << "[Warning] Unknown engine, defaulting to Original FNF\n";
        // FunkinO::Game::startGameplay();
    }
}
