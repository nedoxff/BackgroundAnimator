//
// Created by nedo on 6.06.21.
//

#include "Window.hpp"

Window::Window(unsigned int width, unsigned int height, const tgui::String &title, bool resizable) {
    //Create a sf::RenderWindow
    Logger::Info("Creating a new window with title: \"" + title + "\"..", true);
    if(title.empty())
        Logger::EndStatus(false, true, "Window: The title was empty.");
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height),
                                                title.toStdString(),
                                                resizable ?
                                                sf::Style::Close :
                                                sf::Style::Default);
    SetBackgroundColor(sf::Color(44, 47, 51));
    Logger::EndStatus(true);

    //Attach a tgui::GuiSFML to the created sf::RenderWindow
    Logger::Info("Attaching GUI to the window..", true);
    gui = std::make_unique<tgui::GuiSFML>(*window);
    Logger::EndStatus(true);
}

const std::unique_ptr<sf::RenderWindow> &Window::GetWindow() const {
    return window;
}

const std::unique_ptr<tgui::GuiSFML> &Window::GetGui() const {
    return gui;
}

void Window::SetOnUpdate(const std::function<void()> &onUpdate) {
    Window::onUpdate = onUpdate;
}

void Window::Update() {
    //Clear
    window->clear(backgroundColor);
    //Handle events
    sf::Event event{};
    while(window->pollEvent(event))
    {
        //SFML Handling
        if(event.type == sf::Event::Closed) {
            Logger::Info("Shutting down the app..");
            window->close();
        }
        //TGUI Handling
        gui->handleEvent(event);
    }
    //Update (custom callback)
    if(onUpdate && !cancelUpdate)
        onUpdate();
    //Draw
    gui->draw();
    //Display
    window->display();
}

const sf::Color &Window::GetBackgroundColor() const {
    return backgroundColor;
}

void Window::SetBackgroundColor(const sf::Color &backgroundColor) {
    Window::backgroundColor = backgroundColor;
}

void Window::SetCancelUpdate(bool cancelUpdate) {
    Window::cancelUpdate = cancelUpdate;
}
