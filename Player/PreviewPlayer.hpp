//
// Created by nedo on 19.06.21.
//

#ifndef BACKGROUNDANIMATOR_PREVIEWPLAYER_HPP
#define BACKGROUNDANIMATOR_PREVIEWPLAYER_HPP

/**
 * Includes
 */
#include <vector>
#include <TGUI/TGUI.hpp>
/**
 * Circular dependency fix.
 */
class App;

class PreviewPlayer {
public:
    explicit PreviewPlayer(App* app)
    {
        this->app = app;
    }

    ~PreviewPlayer()
    {
        app = nullptr;
    }
private:
    App* app;
};


#endif //BACKGROUNDANIMATOR_PREVIEWPLAYER_HPP
