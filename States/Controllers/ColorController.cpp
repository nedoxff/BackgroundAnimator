//
// Created by nedo on 11.06.21.
//

#include "ColorController.hpp"
#include "../../Window/App.hpp"

sf::Color ColorController::WaitForValue() {
    while(!Finished)
        app->GetMainWindow()->Update();
    app->GetMainWindow()->SetCancelUpdate(false);
    return TempObject;
}

tgui::ColorPicker::Ptr ColorController::CreateWindow() {
    auto childWindow = tgui::ColorPicker::create("Select Color");
    childWindow->setSize({530, 350});
    childWindow->setInheritedOpacity(0.75f);
    return childWindow;
}

void ColorController::OnValueChange() {
    app->GetMainWindow()->SetBackgroundColor(TempObject);
}

void ColorController::OnCall(App *app) {
    this->app = app;
    app->GetMainWindow()->SetCancelUpdate(true);

    window = CreateWindow();
    window = tgui::ColorPicker::create("Select Color");
    window->setSize({window->getSize().x, window->getSize().y - 25});
    window->setInheritedOpacity(0.75f);
}

void ColorController::OnAttachEvents() {
    window->onColorChange.connect([=]{
        TempObject = window->getColor();
        OnValueChange();
    });
    window->onOkPress.connect([=]{
       TempObject = window->getColor();
       Finished = true;
    });
    window->onPositionChange.connect([=]{
       window->setPosition(0, 0);
    });

    app->GetMainWindow()->GetGui()->add(window);
    ShowUI();
}

tgui::String ColorController::GetName() {
    return "ColorController";
}

void ColorController::ShowUI() {
    window->showWithEffect(tgui::ShowAnimationType::Fade, 500.f);
    //colorPicker->showWithEffect(tgui::ShowAnimationType::Fade, 500.f);
}

void ColorController::HideUI() {
    window->showWithEffect(tgui::ShowAnimationType::Fade, 500.f);
    //colorPicker->showWithEffect(tgui::ShowAnimationType::Fade, 500.f);
}
