//
// Created by nedo on 7.06.21.
//

#include "StartState.hpp"
#include "MainState.hpp"
#include "SelectMusicState.hpp"
#include "../Window/App.hpp"

void StartState::OnCall(App *app) {
    this->app = app;
    //Load the UI widgets.
    LoadUI();

    //Get TGUI elements from the GUI.
    welcome = GetUI(tgui::Label, "Welcome");
    newScene = GetUI(tgui::Button, "NewScene");
    openScene = GetUI(tgui::Button, "OpenScene");
    ShowUI();
}

void StartState::OnAttachEvents() {
    newScene->onPress.connect([=]{this->NewScene();});
    openScene->onPress.connect([=]{this->OpenScene();});
}

void StartState::NewScene() {
    //Hide the UI.
    HideUI();
    //Create a new Save File Dialog.
    auto dialog = tgui::FileDialog::create("Save Scene", "Save");
    dialog->setFileMustExist(false);
    dialog->setPosition("(parent.innersize - size) / 2");
    dialog->setFileTypeFilters({{"BA Scene File", {"*.basf"}}});
    //Attach events to it.
    AttachDialogEvents(dialog);

    //Add the dialog!
    GUI->add(dialog, "Dialog");
    dialog->showWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
}

void StartState::OpenScene() {
    //Hide the UI.
    HideUI();
    //Create a new Open File Dialog.
    auto dialog = tgui::FileDialog::create("Open Scene", "Open");
    dialog->setFileMustExist(true);
    dialog->setPosition("(parent.innersize - size) / 2");
    dialog->setFileTypeFilters({{"BA Scene File", {"*.basf"}}});
    //Attach events to it.
    AttachDialogEvents(dialog, true);

    //Add the dialog!
    GUI->add(dialog, "Dialog");
    dialog->showWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
}

void StartState::HideUI() {
    welcome->hideWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
    newScene->hideWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
    openScene->hideWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
}

void StartState::ShowUI() {
    welcome->showWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
    newScene->showWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
    openScene->showWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
}

void StartState::AttachDialogEvents(const tgui::FileDialog::Ptr& dialog, bool callMainState) {
    dialog->onClosing.connect([=](bool* abort){
        //Cancel the closing first.
        *abort = true;
        //If Cancel or Close was pressed, show the buttonsPanel again.
        if(dialog->getSelectedPaths().empty())
            ShowUI();
        //Else, slowly fade out the dialog and only then close.
        dialog->hideWithEffect(tgui::ShowAnimationType::Fade, 1000.f);
        //Schedule removing the dialog after a second (when the fade finishes).
        tgui::Timer::scheduleCallback([=]{
            GlobalSettings::Get()->ScenePath = dialog->getSelectedPaths()[0].asString();
            GUI->remove(GUI->get("Dialog"));
            if(callMainState)
            {
                auto mainState = std::make_shared<MainState>();
                app->SetCurrentState(mainState);
            }
            else
            {
                auto selectMusic = std::make_shared<SelectMusicState>();
                app->SetCurrentState(selectMusic);
            }
        }, tgui::Duration(sf::seconds(1)));
    });
}

tgui::String StartState::GetName() {
    return "StartState";
}

