//
// Created by nedo on 7.06.21.
//

#include "ResourcesChecker.hpp"

std::vector<tgui::String> ResourcesChecker::UiFiles = {
        "StartState",
        "SelectMusicState",
        "MainState"
};

void ResourcesChecker::Check() {
    Logger::Info("Checking resources..");

    Logger::Info("Checking for resources folder..", true);
    if(!PathExists("Resources"))
        Logger::EndStatus(false, true, "Resources folder does not exist.");
    else
        Logger::EndStatus(true);

    Logger::Info("Checking for UI files..");
    for(auto& file: UiFiles)
    {
        Logger::Info("Checking for " + file + "..", true);
        if(!UiFileExists(file))
            Logger::EndStatus(false, true, "Resources/" + file.toStdString() + ".txt does not exist.");
        else
            Logger::EndStatus(true);
    }

    Logger::Info("Checking for the dark theme (folder)..", true);
    if(!PathExists("Resources/themes"))
        Logger::EndStatus(false, true, "Resources/themes folder does not exist.");
    else
        Logger::EndStatus(true);

    Logger::Info("Checking for the dark theme (file)..", true);
    if(!PathExists("Resources/themes/Black.txt"))
        Logger::EndStatus(false, true, "Resources/themes/Black.txt does not exist.");
    else
        Logger::EndStatus(true);

    Logger::Info("Checking for Fonts folder..", true);
    if(!PathExists("Resources/Fonts"))
        Logger::EndStatus(false, true, "Resources/Fonts does not exist!");
    else
        Logger::EndStatus(true);

    Logger::Success("All resources were found!\n");
}

bool ResourcesChecker::UiFileExists(const tgui::String &name) {
    return PathExists("Resources/" + name + ".txt");
}

bool ResourcesChecker::PathExists(const tgui::String &path) {
    return std::filesystem::exists(path.toStdString());
}
