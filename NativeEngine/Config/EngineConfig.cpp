#include "EngineConfig.hpp"

// Engine
int EngineConfig::engine = 2;

// Gameplay
bool EngineConfig::downscroll = false;
bool EngineConfig::middlescroll = false;
float EngineConfig::scrollSpeed = 2.0f;
int EngineConfig::safeFrames = 10;

// Performance
bool EngineConfig::performanceMode = false;
bool EngineConfig::lowEndMode = false;
bool EngineConfig::matrix4Pipeline = false;

// Modcharts
bool EngineConfig::luaModcharts = false;
bool EngineConfig::enable3D = false;
bool EngineConfig::perspectiveCamera = false;
bool EngineConfig::matrixTransforms = false;
bool EngineConfig::optimizeLua = false;
bool EngineConfig::notitgEffects = false;
bool EngineConfig::depthSorting = false;
