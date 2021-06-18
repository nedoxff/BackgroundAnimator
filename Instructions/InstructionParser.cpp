//
// Created by nedo on 18.06.21.
//

#include <fstream>
#include "InstructionParser.hpp"
#include "../Logging/Logger.hpp"

std::vector<Instruction> InstructionParser::Parse(const tgui::String &path) {
    Logger::Info("Parsing instructions from " + path + "..");
    try {
        Logger::Info("Reading the file..", true);

        //Try to create a stream
        std::ifstream stream{path.toStdString()};
        //If it failed to open, that means the file doesn't exist
        if(!stream) {
            Logger::EndStatus(false, false);
            throw std::runtime_error("File " + path.toStdString() + " does not exist!");
        }

        //Result from parsing
        std::vector<Instruction> result;
        //Lines from the file
        std::vector<tgui::String> lines;

        //Read the file line by line
        for(std::string line; getline(stream, line);)
            lines.emplace_back(line);

        Logger::EndStatus(true);

        //Parse the lines
        Logger::Info("Parsing the lines..", true);
        for(int lineIndex = 0; lineIndex < lines.size(); lineIndex++)
        {
            //Get the line
            auto& line = lines.at(lineIndex);
            //Is this line a comment or is it just empty?
            if(line.startsWith("//") || line.empty()) continue;
            //Split the line with spaces
            auto split = line.split(' ');
            //In one instruction there must be a millisecond and an instruction type
            if(split.size() < 2)
                throw std::runtime_error("Line " + std::to_string(lineIndex) + ": The line must contain at least two arguments: millisecond and the instruction type!");
            //Get the millisecond
            auto millisecond = split.at(0).toUInt();
            //Get the instruction type
            auto instructionTypeString = split.at(1);
            //Find the InstructionType in the map
            auto instructionTypeIterator = std::find_if(Instruction::TypeToString.begin(),
                                                        Instruction::TypeToString.end(), [instructionTypeString](const std::pair<InstructionType, tgui::String>& pair){
                return pair.second == instructionTypeString;
            });
            //If it doesn't exist, throw an exception
            if(instructionTypeIterator == Instruction::TypeToString.end())
                throw std::runtime_error("Line " + std::to_string(lineIndex) + ": Unknown instruction type!");
            //Or else, store it
            auto instructionType = instructionTypeIterator->first;
            /* Parsing arguments
             * Why parsing? Because I added strings to this scripting language
             * and it became a mess.
             */
            std::map<tgui::String, tgui::String> arguments;
            //If there are any arguments
            if(split.size() > 2) {
                std::vector<tgui::String> tempArguments;
                for (int argumentIndex = 2; argumentIndex < split.size(); argumentIndex++) {
                    auto &arg = split.at(argumentIndex);

                    //If there's a string
                    if (arg.startsWith("\"")) {
                        //\/ Store the string here
                        tgui::String string;
                        //count shows the amount of arguments that should be skipped,
                        //because these arguments are a part of the string
                        int count{};
                        //Start iterating
                        for (int stringIndex = argumentIndex; stringIndex < split.size(); stringIndex++) {
                            count++;
                            //Add a part of the string
                            string += split[stringIndex];

                            //If it's already the end of the string
                            if (split[stringIndex].endsWith("\""))
                                break;

                            //If it's not the end of the string
                            if (stringIndex != split.size() - 1 && !split[stringIndex].endsWith("\""))
                                string += " ";

                            //If it's already the last argument part and it doesn't end with "
                            else if (stringIndex == split.size() - 1 && !split[stringIndex].endsWith("\""))
                                throw std::runtime_error(
                                        "Line " + std::to_string(lineIndex) + ": Unknown string syntax error.");
                        }
                        //Cleanup
                        tempArguments.emplace_back(string);
                        argumentIndex += count;
                    } else {
                        //It's not a string, just add it
                        tempArguments.emplace_back(arg);
                    }
                }
                //Arguments are stored like map values: "r: 255 g: 0 b: 0" for example
                //If these keys and values amount don't match, that's a no-no.
                if (tempArguments.size() % 2 != 0)
                    throw std::runtime_error(
                            "Line " + std::to_string(lineIndex) + ": The amount of keys and values don't match!");
                //Put the keys and values into the C++ map
                for (int argumentIndex = 0; argumentIndex < tempArguments.size(); argumentIndex += 2)
                {
                    auto key = tempArguments.at(argumentIndex).replace(":", "");
                    auto value = tempArguments.at(argumentIndex + 1);
                    arguments[key] = value;
                }
            }
            result.emplace_back(millisecond, instructionType, arguments);
        }

        return result;
    }
    catch(std::runtime_error& exc)
    {
        //uh oh
        Logger::Error("Failed parsing the file!", true, exc.what());
        std::exit(1);
    }
}
