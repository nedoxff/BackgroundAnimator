//
// Created by nedo on 7.06.21.
//

#include "SelectMusicState.hpp"
#include "MainState.hpp"
#include "../Window/App.hpp"

void SelectMusicState::OnCall(App *app) {
    //Load the UI.
    this->app = app;
    LoadUI("Resources/SelectMusicState.txt");

    //Get the TGUI widgets.
    title = GetUI(tgui::Label, "Title");
    music = GetUI(tgui::Label, "Music");
    filePanel = GetUI(tgui::Panel, "FilePanel");

    //Create a new FileDialog filling the whole panel.
    dialog = tgui::FileDialog::create("Select music", "Open");
    dialog->setFileTypeFilters({{"Music file", {"*.ogg", "*.wav"}}});
    dialog->setSize("100%");
    filePanel->add(dialog);

    //Show the UI.
    ShowUI();
}

void SelectMusicState::OnAttachEvents() {
    //Do not allow moving the file dialog.
    dialog->onPositionChange.connect([=]{
        dialog->setPosition({0, 0});
    });
    //Do not allow canceling the action.
    dialog->onClosing.connect([=](bool* abort){
        *abort = true;
        //Else if Open was pressed, call the MainState.
        if(!dialog->getSelectedPaths().empty())
        {
            //Slowly hide the UI.
            HideUI();
            tgui::Timer::scheduleCallback([=]{
                GlobalSettings::Get()->MusicPath = dialog->getSelectedPaths()[0].asString();
                //Remove the dialog.
                GUI->remove(GUI->get("Dialog"));
                //Switch to the MainState.
                auto mainState = std::make_shared<MainState>();
                app->SetCurrentState(mainState);
            }, tgui::Duration(sf::seconds(1)));
        }
    });
}

tgui::String SelectMusicState::GetName() {
    return "SelectMusicState";
}

void SelectMusicState::ShowUI() {
    title->showWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
    music->showWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
    filePanel->showWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
}

void SelectMusicState::HideUI() {
    title->hideWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
    music->hideWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
    filePanel->hideWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
}
