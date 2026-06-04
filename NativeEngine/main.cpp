#include <iostream>
#include <fstream>
#include <string>

// Header placeholders for both game versions
#include "OriginalFunkin/FunkinSettings.hpp"
#include "PsychEngine/ClientPrefs.hpp"

enum EngineMode {
    MODE_ORIGINAL_FUNKIN = 0,
    MODE_PSYCH_ENGINE = 1
};

EngineMode currentEngineMode = MODE_ORIGINAL_FUNKIN;

void applyUnifiedSettings(int engineSelection, bool downscroll, bool middlescroll) {
    if (engineSelection == 0) {
        currentEngineMode = MODE_ORIGINAL_FUNKIN;
        std::cout << "[Jay Engine] Booting Original FNF Rule Set..." << std::endl;
    } else {
        currentEngineMode = MODE_PSYCH_ENGINE;
        std::cout << "[Jay Engine] Booting Psych Engine Lua Rule Set..." << std::endl;
    }
}

// ----------------------------------------------------
#if defined(__ANDROID__) || defined(ANDROID)
// ----------------------------------------------------
// ANDROID TARGET ENTRY: JNI Bridge from your Game Turbo UI Navbar
#include <jni.h>

extern "C" JNIEXPORT void JNICALL
Java_com_game_gameturbo_MainActivity_syncTurboSettings(JNIEnv* env, jobject thiz, jint engine, jboolean down, jboolean middle) {
    applyUnifiedSettings(engine, down, middle);
}

// ----------------------------------------------------
#else
// ----------------------------------------------------
// WINDOWS TARGET ENTRY: Reads your external Launcher configuration file
int main(int argc, char* argv[]) {
    std::cout << "--- Global Code Jay Engine Desktop Boot ---" << std::endl;
    
    std::ifstream configFile("turbo_config.json");
    if (configFile.is_open()) {
        int engineSelection = 0;
        bool downscroll = false;
        bool middlescroll = false;
        
        configFile >> engineSelection >> downscroll >> middlescroll;
        applyUnifiedSettings(engineSelection, downscroll, middlescroll);
    } else {
        std::cout << "[Warning] No Game Turbo configuration found. Loading defaults." << std::endl;
        applyUnifiedSettings(0, false, false);
    }
    return 0;
}
#endif
