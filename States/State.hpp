//
// Created by nedo on 7.06.21.
//

#ifndef BACKGROUNDANIMATOR_STATE_HPP
#define BACKGROUNDANIMATOR_STATE_HPP
#include <TGUI/String.hpp>

/**
 * Shortening my own code :D
 */
#define GUI app->GetMainWindow()->GetGui()
#define GetUI(type, name) GUI->get<type>(name)
#define LoadUI(file) GUI->loadWidgetsFromFile(ResourceContainer::Get()->GetResourcesPath() + "/" + file + ".txt", true)

class App;
/**
 * This class describes a state in
 * which the app can be.
 */
class State {
public:
    /**
     * Load the UI, and prepare some variables before the main loop starts.
     * @param app Pointer to the app (the caller).
     */
    virtual void OnCall(App* app) = 0;
    /**
     * Attaching events can be a lot of code,
     * so this is a separate method to attach events to
     * the TGUI buttonsPanel/etc.
     */
    virtual void OnAttachEvents() = 0;
    /**
     * Get the name of the state.
     * @return The name.
     */
    virtual tgui::String GetName() = 0;
    /**
     * Default destructor. Nothing special.
     */
    virtual ~State() { app = nullptr; }
    /**
     * Show the UI with any of the TGUI animation types.
     */
    virtual void ShowUI() {}
    /**
     * Hide the UI with any of the TGUI animation types.
     */
    virtual void HideUI() {}
protected:
    /**
     * Pointer to the app (the caller).
     */
    App* app;
};


#endif //BACKGROUNDANIMATOR_STATE_HPP
