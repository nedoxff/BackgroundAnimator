//
// Created by nedo on 6.06.21.
//

#ifndef BACKGROUNDANIMATOR_LOGGER_HPP
#define BACKGROUNDANIMATOR_LOGGER_HPP

/**
 * Includes
 */
#include <TGUI/TGUI.hpp>
#include <termcolor.hpp>
#include <iostream>

/**
 * A command line logger with color output and
 * status support.
 */
class Logger {
public:
    /**
     * Write a line with [INFO] in the beginning.
     * @param string The string to output.
     * @param status Should this log have status?
     */
    static void Info(const tgui::String& string, bool status = false);
    /**
     * Write a line with [WARNING] in the beginning.
     * @param string The string to output.
     * @param status Should this log have status?
     */
    static void Warning(const tgui::String& string, bool status = false);
    /**
     * Write a line with [ERROR] in the beginning.
     * @param string The string to output.
     * @param throwException Throw an exception?
     * @param exceptionString If throw an exception, what message to output?
     */
    static void Error(const tgui::String& string, bool throwException = true, const std::string& exceptionString = "");
    /**
     * Write a line with [SUCCESS] in the beginning.
     * No status is allowed here.
     * @param string The string to output.
     */
    static void Success(const tgui::String& string);
    /**
     * If any method like \c Info , \c Warning , or \c Error was
     * called with \c status enabled, write a string
     * finishing the log, and throwing an exception
     * if \c throwException is true.
     * @param success Did the operation complete successfully?
     * @param throwException If it failed, throw an exception?
     * @param exceptionString If throw an exception, what message to output?
     */
    static void EndStatus(bool success, bool throwException = true, const std::string& exceptionString = "");
};


#endif //BACKGROUNDANIMATOR_LOGGER_HPP
