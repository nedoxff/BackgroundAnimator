//
// Created by nedo on 19.06.21.
//

#ifndef BACKGROUNDANIMATOR_INSTRUCTIONPROCESSOR_HPP
#define BACKGROUNDANIMATOR_INSTRUCTIONPROCESSOR_HPP

/**
 * Includes.
 */
#include "InstructionHelper.hpp"
#include "InstructionParser.hpp"
#include "InstructionWriter.hpp"
#include "Instruction.hpp"

/**
 * Circular dependency fix.
 */
class App;

/**
 * A class that can handle execution of \c Instruction s.
 * It needs to be connected to an App so it could pass stuff
 * to the PreviewPlayer, and control basically everything
 * in the preview window.
 * \see Instruction
 * \see InstructionParser
 * \see InstructionWriter
 */
class InstructionProcessor {
public:
    /**
     * Constructor.
     * @param app Pointer to the app to be controlled.
     */
    explicit InstructionProcessor(App *app) {
        this->app = app;
    }

    /**
     * Destructor.
     */
    ~InstructionProcessor() {
        app = nullptr;
    }

    /**
     * @return Instructions stored in the \c instructions vector.
     */
    [[nodiscard]] const std::vector<Instruction> &GetInstructions() const;

    /**
     * @return The InstructionHelper.
     */
    [[nodiscard]] InstructionHelper GetHelper() const;

    /**
     * Load instructions using \c InstructionParser into the \c instructions vector.
     * @param path Path to a file containing the instructions.
     */
    void LoadInstructions(const tgui::String &path);

    /**
     * Save instructions to a file using \c InstructionWriter into a file \c path.
     * @param path Path to a file where instructions should be saved.
     */
    void SaveInstructions(const tgui::String &path);

    /**
     * Add an instruction to the \c instructions vector.
     * @param instruction The instruction to be added.
     */
    void AddInstruction(Instruction &instruction);

    /**
     * Execute all instructions which should be executed
     * in the beginning (0ms).
     */
    void ExecuteFirstInstructions();

    /**
     * Execute an instruction depending on its type.
     * @param instruction The instruction to be executed.
     */
    void ExecuteInstruction(Instruction &instruction);

private:
    std::vector<Instruction> instructions;
    App *app;
    InstructionHelper helper{this};
};


#endif //BACKGROUNDANIMATOR_INSTRUCTIONPROCESSOR_HPP
