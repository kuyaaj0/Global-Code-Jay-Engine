#include <iostream>
#include <fstream>
#include <string>
#include "nlohmann/json.hpp" // High-performance JSON reader

// Include separate engine paths
#include "OriginalFunkin/FunkinSettings.hpp"
#include "PsychEngine/ClientPrefs.hpp"

using json = nlohmann::json;

void launchSelectedEngine(const std::string& configPath) {
    std::ifstream configFile(configPath);
    if (!configFile.is_open()) {
        std::cout << "[Jay Engine Launcher] No config found. Booting Default Original FNF." << std::endl;
        // Call Original FNF boot function here
        return;
    }

    json config;
    configFile >> config;

    // Read the selection made on the Game Turbo navbar
    int chosenEngine = config["engine"];
    bool downscroll  = config["downscroll"];
    bool middlescroll = config["middlescroll"];

    std::cout << "========================================" << std::endl;
    std::cout << "     GLOBAL CODE JAY ENGINE LAUNCHER    " << std::endl;
    std::cout << "========================================" << std::endl;

    if (chosenEngine == 0) {
        std::cout << "[Status] Navbar Selected: Original FNF" << std::endl;
        std::cout << "[Action] Launching Original unmodded repository files..." << std::endl;
        
        // Sync layout settings to the original module variables
        FunkinO::Game::funkinSetting::downscroll = downscroll;
        FunkinO::Game::funkinSetting::middlescroll = middlescroll;
        
        // EXECUTE ORIGINAL CORE: e.g., FunkinO::Game::startGameplay();

    } else if (chosenEngine == 1) {
        std::cout << "[Status] Navbar Selected: Psych Engine Fork" << std::endl;
        std::cout << "[Action] Launching Psych Lua processing layers..." << std::endl;
        
        // Sync layout settings to the Psych Engine module variables
        Psych::Backend::ClientPrefs::downScroll = downscroll;
        Psych::Backend::ClientPrefs::middleScroll = middlescroll;
        
        // EXECUTE PSYCH FORK: e.g., Psych::Backend::initLuaModcharts();
    }
}
