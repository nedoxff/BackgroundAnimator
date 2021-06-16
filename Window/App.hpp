//
// Created by nedo on 6.06.21.
//

#ifndef BACKGROUNDANIMATOR_APP_HPP
#define BACKGROUNDANIMATOR_APP_HPP

/**
 * Includes
 */
#include "Window.hpp"
#include "../Logging/Logger.hpp"
#include "../States/State.hpp"
#include "../States/StartState.hpp"
#include <memory>

/**
 * The core of this project. The container
 * for all required objects for the correct
 * work of the program.
 */
class App {
public:
    /**
     * The constructor.
     */
    App();
    /**
     * Set the state of the app.
     * @param currentState The state.
     */
    void SetCurrentState(const std::shared_ptr<State> &currentState);
    /**
     * Get the main window.
     * @return The main window..?
     */
    [[nodiscard]] const std::unique_ptr<Window> &GetMainWindow() const;
    /**
     * Run the application.
     */
    void Run();
private:
    /**
     * The pointer to the wrapped Window.
     */
    std::unique_ptr<Window> mainWindow;
    /**
     * The pointer to the current state of the app.
     */
    std::shared_ptr<State> currentState;
};


#endif //BACKGROUNDANIMATOR_APP_HPP
