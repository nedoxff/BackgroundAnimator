//
// Created by nedo on 7.06.21.
//

#ifndef BACKGROUNDANIMATOR_RESOURCESCHECKER_HPP
#define BACKGROUNDANIMATOR_RESOURCESCHECKER_HPP
/**
 * Includes.
 */
#include <TGUI/String.hpp>
#include <filesystem>
#include "../Logging/Logger.hpp"
#include "../Settings/ResourceContainer.hpp"

/**
 * A class for checking if the files
 * needed for running the app exist.
 */
class ResourcesChecker {
public:
    /**
     * All UI files in this app.
     */
    static std::vector<tgui::String> UiFiles;
    /**
     * Check all of the files.
     */
    static void Check();
    /**
     * Check if file Resources/{name}.txt exists.
     * @param name The name of the UI file.
     * @return A bool indicating if it exists.
     */
    static bool UiFileExists(const tgui::String& name);
    /**
     * Check if a file/directory exists.
     * @param path The path to the file/directory.
     * @return A bool indicating if it exists.
     */
    static bool PathExists(const tgui::String& path);
};
#endif //BACKGROUNDANIMATOR_RESOURCESCHECKER_HPP
