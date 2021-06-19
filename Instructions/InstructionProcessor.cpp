//
// Created by nedo on 19.06.21.
//

#include "InstructionProcessor.hpp"
#include "../Window/App.hpp"
#include "../Settings/GlobalSettings.hpp"

InstructionHelper InstructionProcessor::GetHelper() const {
    return helper;
}

const std::vector<Instruction> &InstructionProcessor::GetInstructions() const {
    return instructions;
}

void InstructionProcessor::LoadInstructions(const tgui::String &path) {
    instructions = InstructionParser::Parse(path);
}

void InstructionProcessor::SaveInstructions(const tgui::String &path) {
    InstructionWriter::Write(path, instructions);
}

void InstructionProcessor::AddInstruction(Instruction &instruction) {
    instructions.emplace_back(instruction);
}

void InstructionProcessor::ExecuteFirstInstructions() {
    for (auto &ins: instructions)
        if (ins.GetMillisecond() == 0)
            ExecuteInstruction(ins);
}

void InstructionProcessor::ExecuteInstruction(Instruction &instruction) {
    switch (instruction.GetType()) {
        case RegisterMusic: {
            GlobalSettings::Get()->MusicPath = instruction["path"];
            break;
        }
    }
}
