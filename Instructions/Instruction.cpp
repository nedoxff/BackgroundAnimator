//
// Created by nedo on 18.06.21.
//


#include "Instruction.hpp"
#include <utility>

std::map<InstructionType, tgui::String> Instruction::TypeToString = {
        {RegisterSong, "RegisterSong"}
};

Instruction::Instruction(unsigned int millisecond, InstructionType type,
                         std::map<tgui::String, tgui::String> arguments) : millisecond(millisecond), type(type),
                                                                                  arguments(std::move(arguments)) {}

unsigned int Instruction::GetMillisecond() const {
    return millisecond;
}

InstructionType Instruction::GetType() const {
    return type;
}

const std::map<tgui::String, tgui::String> &Instruction::GetArguments() const {
    return arguments;
}
