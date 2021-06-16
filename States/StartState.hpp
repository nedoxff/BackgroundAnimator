//
// Created by nedo on 7.06.21.
//

#ifndef BACKGROUNDANIMATOR_STARTSTATE_HPP
#define BACKGROUNDANIMATOR_STARTSTATE_HPP

/**
 * Includes
 */
#include "State.hpp"
#include "../Settings/GlobalSettings.hpp"
#include <TGUI/TGUI.hpp>

/**
 * The state with which the app starts.
 */
class StartState: public State {
public:
    void OnCall(App *app) override;
    void OnAttachEvents() override;
    tgui::String GetName() override;
    void HideUI() override;
    void ShowUI() override;
    void AttachDialogEvents(tgui::FileDialog::Ptr dialog, bool callMainState = false);
    /**
     * This method is called when New Scene was pressed.
     */
    void NewScene();
    /**
     * This method is called when Open Scene was pressed.
     */
    void OpenScene();
    /**
     * TGUI widgets.
     */
    tgui::Label::Ptr welcome;
    tgui::Button::Ptr newScene;
    tgui::Button::Ptr openScene;
};


#endif //BACKGROUNDANIMATOR_STARTSTATE_HPP
