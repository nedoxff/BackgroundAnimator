//
// Created by nedo on 10.06.21.
//

#include "ResourceContainer.hpp"
namespace fs = std::filesystem;

std::shared_ptr<ResourceContainer> ResourceContainer::singleton;

std::shared_ptr<ResourceContainer> ResourceContainer::Get() {
    if(!singleton)
    {
        singleton = std::make_shared<ResourceContainer>();
        singleton->Load();
    }
    return singleton;
}

void ResourceContainer::Load() {
    Logger::Info("ResourceContainer: Loading resources..");
    try {
        Logger::Info("ResourceContainer: Loading fonts..");
        LoadFonts();
    }
    catch(std::runtime_error& exception) {
        Logger::Error(exception.what());
    }
}

tgui::Font ResourceContainer::GetFont(const tgui::String &name) {
    if(fonts.find(name) == fonts.end())
        throw std::runtime_error("ResourceContainer: A font with name \"" + name.toStdString() + "\" was not found in the fonts map!");
    return fonts[name];
}

//TODO: comment this file
void ResourceContainer::LoadFonts() {
        for (auto &file: fs::directory_iterator("Resources/Fonts")) {
            auto path = file.path().string();
            Logger::Info("Loading font from " + path + "..", true);
            tgui::Font font(path);
            if (!font)
                Logger::EndStatus(false, true, "Couldn't load font!");
            else {
                fonts[file.path().stem().string()] = font;
                Logger::EndStatus(true);
            }
        }
}
