//
// Created by nedo on 10.06.21.
//

#include "GlobalSettings.hpp"

std::shared_ptr<GlobalSettings> GlobalSettings::singleton;

std::shared_ptr<GlobalSettings>& GlobalSettings::Get() {
    if(!singleton)
        singleton = std::make_shared<GlobalSettings>();
    return singleton;
}
