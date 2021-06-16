//
// Created by nedo on 6.06.21.
//

#ifndef BACKGROUNDANIMATOR_WINDOW_HPP
#define BACKGROUNDANIMATOR_WINDOW_HPP

/**
 * Includes
 */
#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "../Logging/Logger.hpp"

/**
 * A wrapper around sf::RenderWindow with some
 * additional functions.
 * \see sf::RenderWindow
 */
class Window {
public:
    /**
     * The constructor.
     * @param width The width of the window.
     * @param height The height of the window.
     * @param title The title of the window.
     * @param resizable Should the window be resizable? Defaults to false.
     */
    Window(unsigned int width, unsigned int height, const tgui::String& title, bool resizable = false);

    /**
     * Get the sf::RenderWindow.
     * @return The wrapped sf::RenderWindow.
     */
    [[nodiscard]] const std::unique_ptr<sf::RenderWindow> &GetWindow() const;
    /**
     * Get the tgui::GuiSFML.
     * @return The wrapped tgui::GuiSFML.
     */
    [[nodiscard]] const std::unique_ptr<tgui::GuiSFML> &GetGui() const;
    /**
     * Set the callback for updating the window.
     * @param onUpdate The callback.
     */
    void SetOnUpdate(const std::function<void()> &onUpdate);
    /**
     * Update the window (Clear, Update, Draw).
     */
    void Update();
    /**
     * Get the background color of the window.
     * @return The color.
     */
    [[nodiscard]] const sf::Color &GetBackgroundColor() const;
    /**
     * Set the background color of the window.
     * @param backgroundColor The new color.
     */
    void SetBackgroundColor(const sf::Color &backgroundColor);
    /**
     * Set if onUpdate should be canceled.
     * @param cancelUpdate New value.
     */
    void SetCancelUpdate(bool cancelUpdate);
private:
    /**
     * The pointer to the wrapped sf::RenderWindow.
     */
    std::unique_ptr<sf::RenderWindow> window;
    /**
     * The pointer to the wrapped TGUI.
     */
    std::unique_ptr<tgui::GuiSFML> gui;
    /**
     * The function for allowing additional
     * stuff to get called while the window is updating.
     */
    std::function<void()> onUpdate;
    /**
     * The background color of the window.
     */
    sf::Color backgroundColor;
    /**
     * Should the onUpdate function be temporarily canceled?
     * \remarks Useful for controllers.
     */
     bool cancelUpdate;
};


#endif //BACKGROUNDANIMATOR_WINDOW_HPP
