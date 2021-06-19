//
// Created by nedo on 11.06.21.
//

#ifndef BACKGROUNDANIMATOR_COLORCONTROLLER_HPP
#define BACKGROUNDANIMATOR_COLORCONTROLLER_HPP

#include "Controller.hpp"
#include <SFML/Graphics.hpp>

class ColorController : public Controller<sf::Color, tgui::ColorPicker> {
public:
    sf::Color WaitForValue() override;

    void OnCall(App *app) override;

    void OnAttachEvents() override;

    tgui::String GetName() override;

    void ShowUI() override;

    void HideUI() override;

protected:
    tgui::ColorPicker::Ptr window;

    tgui::ColorPicker::Ptr CreateWindow() override;

    void OnValueChange() override;
};


#endif //BACKGROUNDANIMATOR_COLORCONTROLLER_HPP
