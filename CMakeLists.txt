cmake_minimum_required(VERSION 3.19)
project(BackgroundAnimator)

set(CMAKE_CXX_STANDARD 20)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fprofile-instr-generate -fcoverage-mapping)
    add_link_options(-fprofile-instr-generate)
    #Uncomment in case of linker errors
    #link_libraries(clang_rt.profile-x86_64)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(--coverage)
    #Uncomment in case of linker errors
    #link_libraries(gcov)
endif ()

add_executable(BackgroundAnimator main.cpp Window/Window.cpp Window/Window.hpp Logging/Logger.cpp Logging/Logger.hpp Libraries/termcolor.hpp Window/App.cpp Window/App.hpp States/State.hpp States/StartState.cpp States/StartState.hpp States/SelectMusicState.cpp States/SelectMusicState.hpp States/MainState.cpp States/MainState.hpp Settings/MainButtonsSettings.cpp Settings/MainButtonsSettings.hpp Settings/GlobalSettings.cpp Settings/GlobalSettings.hpp Settings/ResourceContainer.cpp Settings/ResourceContainer.hpp States/Controllers/Controller.cpp States/Controllers/Controller.hpp States/Controllers/ColorController.cpp States/Controllers/ColorController.hpp Instructions/Instruction.cpp Instructions/Instruction.hpp Instructions/InstructionParser.cpp Instructions/InstructionParser.hpp Instructions/InstructionWriter.cpp Instructions/InstructionWriter.hpp Instructions/InstructionProcessor.cpp Instructions/InstructionProcessor.hpp Instructions/InstructionHelper.cpp Instructions/InstructionHelper.hpp Player/PreviewPlayer.cpp Player/PreviewPlayer.hpp)

if(UNIX)
    find_package(SFML COMPONENTS graphics window system audio REQUIRED)
    find_package(TGUI REQUIRED)
endif()

add_subdirectory(Libraries/tweeny)
include_directories(Libraries)
target_link_libraries(BackgroundAnimator sfml-graphics sfml-window sfml-system sfml-audio tgui tweeny)