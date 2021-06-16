//
// Created by nedo on 9.06.21.
//

#include "MainButtonsSettings.hpp"
#include "../States/Controllers/ColorController.hpp"
#include <utility>

std::unique_ptr<MainButtonsSettings> MainButtonsSettings::singleton;

MainButtonsSettings MainButtonsSettings::Get() {
    //If pointer is nullptr, create new settings and load them.
    if(!singleton) {
        singleton = std::make_unique<MainButtonsSettings>();
        singleton->Load();
    }
    //Else, return the settings.
    return *singleton;
}

void MainButtonsSettings::Load() {
    Logger::Info("MainButtonsSettings: Loading button events..");

    //TODO
    RegisterButton("Basic", "Change Background", [=](App* app){
        auto colorPicker = std::make_shared<ColorController>();
        app->SetCurrentState(colorPicker);
        auto color = colorPicker->WaitForValue();
        Logger::Success("Works!");
    });

    Logger::Success("MainButtonSettings: Successfully loaded button settings!");
}

void MainButtonsSettings::RegisterButton(const tgui::String &category, const tgui::String &name,
                                         CALLBACK onClick) {
    Logger::Info("Registering " + name + " in category " + category + "..", true);
    buttons[category][name] = std::move(onClick);
    Logger::EndStatus(true);
}

const BUTTONS_MAP &MainButtonsSettings::GetButtons() const {
    return buttons;
}
