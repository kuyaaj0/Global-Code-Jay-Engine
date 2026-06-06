#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"

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

    int chosenEngine = config.value("engine", 0);
    bool downscroll = config.value("downscroll", false);
    bool middlescroll = config.value("middlescroll", false);

    std::cout << "========================================\n";
    std::cout << " GLOBAL CODE JAY ENGINE LAUNCHER\n";
    std::cout << "========================================\n";

    if (chosenEngine == 0) {

        std::cout << "[Status] Original FNF Selected\n";

        //FunkinO::Game::funkinSetting::downscroll = downscroll;
       // FunkinO::Game::funkinSetting::middlescroll = middlescroll;

        // TODO: REAL ENGINE START
        // FunkinO::Game::startGameplay();

    } 
    else if (chosenEngine == 1) {

        std::cout << "[Status] Psych Engine Selected\n";

       // Psych::Backend::ClientPrefs::downScroll = downscroll;
       // Psych::Backend::ClientPrefs::middleScroll = middlescroll;

        // TODO: REAL ENGINE START
        // Psych::Backend::initLuaModcharts();

    } 
    else {
        std::cout << "[Warning] Unknown engine, defaulting to Original FNF\n";
        // FunkinO::Game::startGameplay();
    }
}
