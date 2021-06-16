//
// Created by nedo on 6.06.21.
//

#include "App.hpp"
#include "../Settings/ResourceContainer.hpp"

App::App() {
    Logger::Info("Initializing the App..");

    mainWindow = std::make_unique<Window>(1280, 720, "Background Animator");
    Logger::Info("Creating the MainWindow..", true);
    Logger::EndStatus(true);

    Logger::Info("Loading the Dark Theme..", true);
    tgui::Theme::setDefault("Resources/themes/Black.txt");
    Logger::EndStatus(true);

    Logger::Info("Loading resources..");
    auto resources = ResourceContainer::Get();
    mainWindow->GetGui()->setFont(resources->GetFont("opensans"));

    Logger::Success("Initialized the App!\n");
}

void App::SetCurrentState(const std::shared_ptr<State> &currentState) {
    App::currentState = currentState;

    Logger::Info(currentState->GetName() + ": Calling..");
    currentState->OnCall(this);

    Logger::Info(currentState->GetName() + ": Attaching UI..");
    currentState->OnAttachEvents();

    Logger::Success("App: Current state was successfully set to " + currentState->GetName() + "!\n");
}

const std::unique_ptr<Window> &App::GetMainWindow() const {
    return mainWindow;
}

void App::Run() {
    auto startState = std::make_shared<StartState>();
    SetCurrentState(startState);
    while(mainWindow->GetWindow()->isOpen())
        mainWindow->Update();
}
