//
// Created by nedo on 19.06.21.
//

#ifndef BACKGROUNDANIMATOR_INSTRUCTIONHELPER_HPP
#define BACKGROUNDANIMATOR_INSTRUCTIONHELPER_HPP

/**
 * Includes
 */
#include <TGUI/TGUI.hpp>
#include "Instruction.hpp"

#define uint8 unsigned char

/**
 * Circular dependency fix.
 */
class InstructionProcessor;

/**
 * This class is like a "communicator" between
 * the C++ variables and the \c InstructionProcessor.
 * It provides methods to easily add instructions
 * using stuff that exists in C++, like strings and integers.
 */
class InstructionHelper {
public:
    /**
     * Constructor.
     * @param instructionProcessor Pointer to the instruction processor.
     */
    explicit InstructionHelper(InstructionProcessor *instructionProcessor) {
        processor = instructionProcessor;
    }

    /**
     * Destructor.
     */
    ~InstructionHelper() {
        processor = nullptr;
    }

    /**
     * Set music for the scene.
     * @param path Path to the music.
     */
    void RegisterMusic(const tgui::String &path);

private:
    InstructionProcessor *processor;
};


#endif //BACKGROUNDANIMATOR_INSTRUCTIONHELPER_HPP
