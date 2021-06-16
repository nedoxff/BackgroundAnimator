//
// Created by nedo on 8.06.21.
//

#ifndef BACKGROUNDANIMATOR_MAINSTATE_HPP
#define BACKGROUNDANIMATOR_MAINSTATE_HPP

/**
 * Includes
 */
#include "State.hpp"
#include "../Settings/MainButtonsSettings.hpp"
#include "../Settings/GlobalSettings.hpp"
#include "../Settings/ResourceContainer.hpp"
#include <TGUI/TGUI.hpp>

/**
 * The state where the work happens.
 */
class MainState: public State {
public:
    void OnCall(App *app) override;
    void OnAttachEvents() override;
    tgui::String GetName() override;
    void ShowUI() override;
    void HideUI() override;

private:
    /**
     * Global settings.
     */
    std::shared_ptr<GlobalSettings> settings;
    /**
     * Resource settings.
     */
     std::shared_ptr<ResourceContainer> resources;
    /**
     * Button settings.
     */
    MainButtonsSettings buttonSettings;
    /**
     * Load buttonsPanel from a category (and add them to \c buttonsPanel).
     * @param category The name of the category.
     */
    void LoadButtons(const tgui::String& category);
    /**
     * Load categories from the settings.
     * \see MainButtonsSettings
     */
    void LoadCategories();
    /**
     * To not recreate the string each update call,
     * this string stores the duration of the audio.
     * \remarks Used in \c progress.
     */
    tgui::String durationString;
    /**
     * TGUI widgets.
     */
    tgui::ChildWindow::Ptr controls;
    tgui::Button::Ptr play;
    tgui::ProgressBar::Ptr progress;
    tgui::Slider::Ptr progressSlider;
    tgui::ScrollablePanel::Ptr buttonsPanel;
    tgui::Tabs::Ptr tabs;
};


#endif //BACKGROUNDANIMATOR_MAINSTATE_HPP
