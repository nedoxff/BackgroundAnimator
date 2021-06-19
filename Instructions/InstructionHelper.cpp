//
// Created by nedo on 19.06.21.
//

#include "InstructionHelper.hpp"
#include "InstructionProcessor.hpp"

void InstructionHelper::RegisterMusic(const tgui::String &path) {
    auto instruction = Instruction(0, InstructionType::RegisterMusic, {
            {"path", path}
    });
    processor->AddInstruction(instruction);
}
