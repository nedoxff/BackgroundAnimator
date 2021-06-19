//
// Created by nedo on 18.06.21.
//

#include "InstructionWriter.hpp"

void InstructionWriter::Write(const tgui::String &path, const std::vector<Instruction> &instructions) {
    Logger::Info("Saving instructions to " + path + "..", true);
    try {
        std::fstream stream{path.toStdString(), std::ios::out | std::ios::trunc};
        if (!stream)
            throw std::runtime_error("Failed opening a stream to " + path.toStdString() + "!");
        stream
                << "//This file was automatically made by BA.\n//Please, do not try to edit this file if you don't want to break everything."
                << std::endl;
        for (auto &instruction: instructions) {
            stream << instruction.GetMillisecond() << " ";
            stream << Instruction::TypeToString[instruction.GetType()] << " ";
            for (auto &argument: instruction.GetArguments())
                stream << argument.first << ": " << argument.second << " ";
        }
        Logger::EndStatus(true);
    }
    catch (std::runtime_error &exc) {
        Logger::EndStatus(false, false);
        Logger::Error("Failed to save instructions!", true, exc.what());
        std::exit(1);
    }
}
