cmake_minimum_required(VERSION 3.10)

# Define the engine project name
project(GlobalCodeJayEngine CXX)

# Require modern C++17 standards for optimization and matrix math speed
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# List all active engine files that need to be compiled
set(ENGINE_SOURCES
    Backend/Conductor.cpp
    Backend/TouchManager.cpp
    
    Audio/AudioManager.cpp
    
    Object/Character.cpp
    States/Stage/Stage.cpp
    Hud/HUD.cpp
    
    Scripts/ScriptManager.cpp
    States/Converter/ChartConverter.cpp
    Config/EngineConfig.cpp
    Renderer/Matrix4Renderer.cpp
    Math/Vector3.cpp
    Math/Matrix4.cpp
    Renderer/Camera3D.cpp
    Transform/Transform.cpp
    Gameplay/Note3D.cpp
    Gameplay/NoteManager.cpp
    Gameplay/SongPosition.cpp
    Object/StrumLine.cpp
    Gameplay/ScoreManager.cpp
    Gameplay/HealthManager.cpp
    
    Loader/SongLoader.cpp

    Modifiers/ModifierManager.cpp
    
    States/ChartParser.cpp
    States/InputManager.cpp
    States/GameplayState.cpp
    
    Renderer/Renderer.cpp
    Renderer/Camera3D.cpp
    Renderer/Matrix4Renderer.cpp
    
    Math/Vector2.cpp
    Math/Vector3.cpp
    Math/Vector4.cpp
    Math/Matrix4.cpp
    Math/Quaternion.cpp
   # OriginalFunkin/FunkinGameplay.cpp
   # PsychEngine/PsychGameplay.cpp
)

# ----------------------------------------------------
# TARGET 1: ANDROID BUILD SELECTION
# ----------------------------------------------------
if(ANDROID)
    # Compiles your code into a high-performance native mobile library (.so)
    add_library(jay_engine SHARED ${ENGINE_SOURCES})

    target_include_directories(jay_engine PRIVATE
    ${CMAKE_SOURCE_DIR}/external)
    
    # Connects Android system logs, EGL context, and OpenGLES 3 graphics drivers
    target_link_libraries(jay_engine android log GLESv3 EGL)
    
    # Enables aggressive compiler optimization to prevent mobile lag spikes
    target_compile_options(jay_engine PRIVATE -O3)

# ----------------------------------------------------
# TARGET 2: WINDOWS DESKTOP BUILD SELECTION
# ----------------------------------------------------
else()
    # Compiles your code into a standard standalone executable application (.exe)
    add_executable(GlobalCodeJayEngine ${ENGINE_SOURCES})
    
    # Connects standard desktop PC OpenGL graphics drivers
    target_link_libraries(GlobalCodeJayEngine opengl32)
    
    # Handles separate compiler flags depending on Windows tools (MSVC vs GCC)
    if(MSVC)
        target_compile_options(GlobalCodeJayEngine PRIVATE /O2)
    else()
        target_compile_options(GlobalCodeJayEngine PRIVATE -O3)
    endif()
endif()
