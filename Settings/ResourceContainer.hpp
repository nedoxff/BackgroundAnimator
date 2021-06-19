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
     * Check if all resources needed for running the app exist.
     */
    void CheckResources();

    /**
     * Load resources.
     */
    void Load();

    /**
     * Get a font from the \c fonts map.
     * @param name
     * @return
     */
    tgui::Font GetFont(const tgui::String &name);

    /**
     * Get path to the directory containing all resources needed to run the app.
     * @return The string containing the path.
     */
    [[nodiscard]] const tgui::String &GetResourcesPath() const;

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
     * Find the directory containing resources and set it to \c resourcesPath.
     */
    void FindResourcesDirectory();

    /**
     * The fonts map.
     */
    std::map<tgui::String, tgui::Font> fonts;
    /**
     * Path to the directory containing the resources.
     */
    tgui::String resourcesPath;
};


#endif //BACKGROUNDANIMATOR_RESOURCECONTAINER_HPP
