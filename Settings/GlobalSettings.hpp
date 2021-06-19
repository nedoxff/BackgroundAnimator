//
// Created by nedo on 10.06.21.
//

#ifndef BACKGROUNDANIMATOR_GLOBALSETTINGS_HPP
#define BACKGROUNDANIMATOR_GLOBALSETTINGS_HPP

#include <memory>
#include <TGUI/String.hpp>
#include <SFML/Audio.hpp>

/**
 * A singleton container for all settings like music,
 * paths, etc.
 */
class GlobalSettings {
public:
    /**
     * Get the pointer to the singleton container.
     * @return
     */
    static std::shared_ptr<GlobalSettings> &Get();

    /**
     * The path to the scene file.
     */
    tgui::String ScenePath;
    /**
     * The path to the music used in the scene.
     */
    tgui::String MusicPath;
    /**
     * The SFML music.
     */
    sf::Music Music;
private:
    /**
     * Private pointer to the singleton container.
     */
    static std::shared_ptr<GlobalSettings> singleton;
};


#endif //BACKGROUNDANIMATOR_GLOBALSETTINGS_HPP
