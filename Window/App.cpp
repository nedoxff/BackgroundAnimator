//
// Created by nedo on 6.06.21.
//

#include "App.hpp"
#include "../States/State.hpp"
#include "../States/StartState.hpp"
#include "../Settings/ResourceContainer.hpp"

App::App() {
    Logger::Info("Initializing the App..");

    Logger::Info("Creating the MainWindow..");
    mainWindow = std::make_unique<Window>(1280, 720, "Background Animator");
    mainWindow->SetOnUpdate([=]{
       if(currentState)
           currentState->Tick();
    });

    Logger::Info("Loading resources..");
    auto resources = ResourceContainer::Get();
    mainWindow->GetGui()->setFont(resources->GetFont("opensans"));

    Logger::Info("Loading the Dark Theme..", true);
    tgui::Theme::setDefault(resources->GetResourcesPath() + "/themes/Black.txt");
    Logger::EndStatus(true);

    Logger::Success("Successfully initialized the App!\n");
}

void App::SetCurrentState(const std::shared_ptr<State> &currentState) {
    App::previousState = App::currentState;
    App::currentState = currentState;

    Logger::Info(currentState->GetName() + ": Calling..");
    currentState->OnCall(this);

    Logger::Info(currentState->GetName() + ": Attaching UI..");
    currentState->OnAttachEvents();

    Logger::Success("App: Current state was successfully set to " + currentState->GetName() + "!");
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

void App::ReturnToPreviousState() {
    if(previousState) {
        App::currentState = App::previousState;
        Logger::Success("App: Successfully restored the previous state: " + currentState->GetName() + "!");
    }
}
