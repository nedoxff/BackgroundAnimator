//
// Created by nedo on 11.06.21.
//

#include "ColorController.hpp"
#include "../../Window/App.hpp"

sf::Color ColorController::WaitForValue() {
    while (!Finished)
        app->GetMainWindow()->Update();
    return TempObject;
}

tgui::ColorPicker::Ptr ColorController::CreateWindow() {
    auto childWindow = tgui::ColorPicker::create("Select Color");
    childWindow->setSize({530, 400});
    childWindow->setInheritedOpacity(0.75f);
    return childWindow;
}

void ColorController::OnValueChange() {
    app->GetMainWindow()->SetBackgroundColor(TempObject);
}

void ColorController::OnCall(App *app) {
    this->app = app;

    window = CreateWindow();
    window = tgui::ColorPicker::create("Select Color");
    window->setInheritedOpacity(0.75f);
}

void ColorController::OnAttachEvents() {
    window->onColorChange.connect([=] {
        TempObject = window->getColor();
        OnValueChange();
    });
    window->onOkPress.connect([=] {
        TempObject = window->getColor();
        Finished = true;
    });

    app->GetMainWindow()->GetGui()->add(window);
    ShowUI();
}

tgui::String ColorController::GetName() {
    return "ColorController";
}

void ColorController::ShowUI() {
    window->showWithEffect(tgui::ShowAnimationType::Fade, 500.f);
}

void ColorController::HideUI() {
    window->showWithEffect(tgui::ShowAnimationType::Fade, 500.f);
}

