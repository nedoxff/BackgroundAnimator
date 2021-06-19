//
// Created by nedo on 18.06.21.
//

#ifndef BACKGROUNDANIMATOR_INSTRUCTION_HPP
#define BACKGROUNDANIMATOR_INSTRUCTION_HPP

/**
 * Includes.
 */
#include <map>
#include <TGUI/String.hpp>

/**
 * All possible instruction types.
 */
enum InstructionType {
    RegisterMusic
};

/**
 * An instruction can be anything - Change the song,
 * Change the background, Create a color.
 * An instruction is basically the controller of everything
 * happening in the Preview window.
 */
class Instruction {
public:
    /**
     * A converter from an InstructionType to a string.
     */
    static std::map<InstructionType, tgui::String> TypeToString;

    /**
     * Constructor.
     * @param millisecond Millisecond on which the instruction should be executed.
     * @param type Type of the instruction.
     * @param arguments Arguments attached to that instruction.
     */
    Instruction(unsigned int millisecond, InstructionType type, std::map<tgui::String, tgui::String> arguments);

    /**
     * @return Millisecond on which the instruction should be executed.
     */
    [[nodiscard]] unsigned int GetMillisecond() const;

    /**
     * @return Type of the instruction.
     */
    [[nodiscard]] InstructionType GetType() const;

    /**
     * @return Arguments attached to the instruction.
     */
    [[nodiscard]] const std::map<tgui::String, tgui::String> &GetArguments() const;

    /**
     * A [] operator for accessing the arguments just like a map.
     * @param key Name of the argument.
     * @return Value of that argument.
     */
    const tgui::String &operator[](const tgui::String &key) { return arguments[key]; }

private:
    unsigned int millisecond;
    InstructionType type;
    std::map<tgui::String, tgui::String> arguments;
};


#endif //BACKGROUNDANIMATOR_INSTRUCTION_HPP
