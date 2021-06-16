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
        FindResourcesDirectory();
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
    Logger::Info("Loading fonts..");
    try {
        for (auto &file: fs::directory_iterator(resourcesPath.toStdString() + "/Fonts")) {
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
        Logger::Success("Successfully loaded fonts!");
    }
    catch(std::runtime_error& exc)
    {
        Logger::Error("Failed to load fonts!", true, exc.what());
        std::exit(1);
    }
}

void ResourceContainer::FindResourcesDirectory() {
    Logger::Info("Finding the Resources directory..", true);

    try {
        auto currentDirectory = fs::current_path();
        int counter = 0;
        while (!fs::exists(currentDirectory.string() + "/Resources")) {
            currentDirectory = currentDirectory.parent_path();
            counter++;
            if (counter == 5)
                throw std::runtime_error("Your Resources folder does not exist or it is too far from the executable!");
        }
        Logger::EndStatus(true);
        resourcesPath = currentDirectory.string() + "/Resources";
        Logger::Info("Resource directory is " + resourcesPath);
    }
    catch(std::runtime_error& exc)
    {
        Logger::EndStatus(false, true, exc.what());
        std::exit(1);
    }

}

void ResourceContainer::CheckResources() {

}

const tgui::String &ResourceContainer::GetResourcesPath() const {
    return resourcesPath;
}
