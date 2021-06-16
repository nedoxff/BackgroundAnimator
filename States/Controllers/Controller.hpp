//
// Created by nedo on 11.06.21.
//

#ifndef BACKGROUNDANIMATOR_CONTROLLER_HPP
#define BACKGROUNDANIMATOR_CONTROLLER_HPP

#include <TGUI/TGUI.hpp>
#include <optional>
#include "../State.hpp"

template<class ReturnValue, class WindowType>
class Controller: public State {
public:
    virtual ReturnValue WaitForValue() = 0;
protected:
    virtual typename WindowType::Ptr CreateWindow() = 0;
    virtual void OnValueChange() = 0;
    ReturnValue TempObject;
    bool Finished{};
};


#endif //BACKGROUNDANIMATOR_CONTROLLER_HPP
