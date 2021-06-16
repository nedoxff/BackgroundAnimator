//
// Created by nedo on 6.06.21.
//

#include "Logger.hpp"

void Logger::Info(const tgui::String &string, bool status) {
    std::cout << termcolor::cyan << "[INFO] " << termcolor::reset << string.toStdString() << (status ? "": "\n");
}

void Logger::Warning(const tgui::String &string, bool status) {
    std::cout << termcolor::yellow << "[WARNING] " << termcolor::reset << string.toStdString() << (status ? "": "\n");
}

void Logger::Success(const tgui::String &string) {
    std::cout << termcolor::green << "[SUCCESS] " << termcolor::reset << string.toStdString() << std::endl;
}

void Logger::EndStatus(bool success, bool throwException, const std::string& exceptionString) {
    std::cout << (success ? termcolor::green : termcolor::red) << (success ? " OK" : " FAILED") << termcolor::reset << std::endl;
    if(!success && throwException) {
        throw std::runtime_error("Logger::EndStatus: throwing an exception was requested:\n" + exceptionString);
    }
}

void Logger::Error(const tgui::String &string, bool throwException, const std::string &exceptionString) {
    std::cout << termcolor::red << "[ERROR] " << termcolor::reset << string.toStdString();
    if(throwException) {
        throw std::runtime_error("Logger::Error: throwing an exception was requested:\n" + exceptionString);
    }
}

