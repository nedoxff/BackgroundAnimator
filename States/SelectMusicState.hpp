//
// Created by nedo on 7.06.21.
//

#ifndef BACKGROUNDANIMATOR_SELECTMUSICSTATE_HPP
#define BACKGROUNDANIMATOR_SELECTMUSICSTATE_HPP

/**
 * Includes
 */
#include "State.hpp"
#include <TGUI/TGUI.hpp>

/**
 * The state which is called before actually
 * creating a new scene.
 */
class SelectMusicState : public State {
public:
    void OnCall(App *app) override;

    void OnAttachEvents() override;

    tgui::String GetName() override;

    void ShowUI() override;

    void HideUI() override;

private:
    /**
     * TGUI widgets.
     */
    tgui::Label::Ptr title;
    tgui::Label::Ptr music;
    tgui::Panel::Ptr filePanel;
    tgui::FileDialog::Ptr dialog;
};


#endif //BACKGROUNDANIMATOR_SELECTMUSICSTATE_HPP
