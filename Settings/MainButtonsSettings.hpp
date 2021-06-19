//
// Created by nedo on 9.06.21.
//

#ifndef BACKGROUNDANIMATOR_MAINBUTTONSSETTINGS_HPP
#define BACKGROUNDANIMATOR_MAINBUTTONSSETTINGS_HPP

/**
 * Includes
 */
#include <memory>
#include <TGUI/String.hpp>
#include <functional>
#include "../Window/App.hpp"
#include "../Logging/Logger.hpp"
/**
 * Shortening code
 */
#define CALLBACK std::function<void(App* app)>
#define BUTTONS_MAP std::map<tgui::String, std::map<tgui::String, CALLBACK>>
#define STRING_ARG const tgui::String&

/**
 * A singleton that contains all information and callbacks
 * needed for buttonsPanel in the MainState.
 * \see MainState
 */
class MainButtonsSettings {
public:
    /**
     * Get the singleton
     * @return The settings.
     */
    static MainButtonsSettings Get();

    /**
     * Get button settings.
     * @return The map containing categories and buttonsPanel with their callbacks.
     */
    [[nodiscard]] const BUTTONS_MAP &GetButtons() const;

private:
    /**
     * Pointer to the only instance of MainButtonsSettings.
     */
    static std::unique_ptr<MainButtonsSettings> singleton;

    /**
     * Load settings into the map.
     */
    void Load();

    /**
     * Add a button into the map.
     * @param category The category where the button is.
     * @param name The name of the button.
     * @param onClick The callback of the button.
     */
    void RegisterButton(STRING_ARG category, STRING_ARG name, CALLBACK onClick);
    /**
     * The map containing button info :D
     */
    BUTTONS_MAP buttons;
};


#endif //BACKGROUNDANIMATOR_MAINBUTTONSSETTINGS_HPP
