//
// Created by nedo on 18.06.21.
//

#ifndef BACKGROUNDANIMATOR_INSTRUCTIONWRITER_HPP
#define BACKGROUNDANIMATOR_INSTRUCTIONWRITER_HPP

/**
 * Includes.
 */
#include <vector>
#include <fstream>
#include <TGUI/String.hpp>
#include "Instruction.hpp"
#include "../Logging/Logger.hpp"

/**
 * A class that can convert \c Instruction s to a data storage format
 * which can be later read by \c InstructionParser.
 * \see Instruction
 * \see InstructionParser
 */
class InstructionWriter {
public:
    static void Write(const tgui::String &path, const std::vector<Instruction> &instructions);
};


#endif //BACKGROUNDANIMATOR_INSTRUCTIONWRITER_HPP
