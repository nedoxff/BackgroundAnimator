//
// Created by nedo on 18.06.21.
//

#ifndef BACKGROUNDANIMATOR_INSTRUCTIONPARSER_HPP
#define BACKGROUNDANIMATOR_INSTRUCTIONPARSER_HPP

/**
 * Includes.
 */
#include "Instruction.hpp"
#include <vector>

/**
 * A class for parsing the scripting language (or, storage format) containing
 * the instructions to actual instances of \c Instruction.
 */
class InstructionParser {
public:
    /**
     * Parse the instructions from \c path to a vector.
     * @param path Path to a file containing instructions.
     * @return Formatted, parsed Instructions.
     */
    static std::vector<Instruction> Parse(const tgui::String& path);
};


#endif //BACKGROUNDANIMATOR_INSTRUCTIONPARSER_HPP
