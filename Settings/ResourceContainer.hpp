//
// Created by nedo on 10.06.21.
//

#ifndef BACKGROUNDANIMATOR_RESOURCECONTAINER_HPP
#define BACKGROUNDANIMATOR_RESOURCECONTAINER_HPP

#include <memory>
#include <map>
#include <filesystem>
#include <TGUI/String.hpp>
#include <TGUI/Backend.hpp>
#include "../Logging/Logger.hpp"

/**
 * A singleton container for all fonts, images, etc.
 */
class ResourceContainer {
public:
    /**
     * Get the singleton pointer.
     * @return The pointer to the container.
     */
    static std::shared_ptr<ResourceContainer> Get();

    /**
     * Load resources.
     */
    void Load();

    /**
     * Get a font from the \c fonts map.
     * @param name
     * @return
     */
    tgui::Font GetFont(const tgui::String& name);
private:
    /**
     * A private singleton pointer.
     */
    static std::shared_ptr<ResourceContainer> singleton;

    /**
     * Load fonts from Resources/Fonts.
     */
    void LoadFonts();
    /**
     * The fonts map.
     */
    std::map<tgui::String, tgui::Font> fonts;
};


#endif //BACKGROUNDANIMATOR_RESOURCECONTAINER_HPP
