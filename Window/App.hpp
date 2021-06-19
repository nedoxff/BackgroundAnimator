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
#include "../Instructions/InstructionProcessor.hpp"
#include <memory>

class State;

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
     * @return The main window.
     */
    [[nodiscard]] const std::unique_ptr<Window> &GetMainWindow() const;

    /**
     * Run the application.
     */
    void Run();

    /**
     * Go back to the previous state.
     */
    void ReturnToPreviousState();

    /**
     * @return The InstructionProcessor.
     */
    [[nodiscard]] const std::shared_ptr<InstructionProcessor> &GetProcessor() const;

private:
    /**
     * Pointer to the wrapped Window.
     */
    std::unique_ptr<Window> mainWindow;
    /**
     * Pointer to the current state of the app.
     */
    std::shared_ptr<State> currentState;
    /**
     * Pointer to the InstructionProcessor.
     */
    std::shared_ptr<InstructionProcessor> processor;
    /**
     * If anything like a Controller was called, which is also a State,
     * when exiting from it, it MUST go back to the previous state, which
     * is usually the MainState.
     */
    std::shared_ptr<State> previousState;
};


#endif //BACKGROUNDANIMATOR_APP_HPP
