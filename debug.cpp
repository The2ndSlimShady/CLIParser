#include <iostream>

#include "CLIParser.hpp"

// Try something

int main(int argc, char** args)
{	
    //for (int i = 0; i < argc; i++)
    //std::cout << '\n' << args[i];

	CLIParser parser { args, argc };
	parser.AddFlag("bool", FlagType::Bool);
    parser.BindFlag("b", "bool");
	parser.AddFlag("stringList", FlagType::StringList);
    parser.BindFlag("sl", "stringList");
	parser.AddFlag("il", FlagType::IntList);
    parser.BindFlag("i", "il");
	parser.AddFlag("fl", FlagType::FloatList);
    parser.BindFlag("f", "fl");
	Flags flags = parser.Parse();

    const auto& list = flags.GetStringList("stringList");

	for (auto& it: list) {
        std::cout << "stringList: \"" << it << "\"\n";
	}
	for (auto& it: flags.GetIntList("il")) {
        std::cout << "il: " << it << "\n";
	}
	for (auto& it: flags.GetFloatList("fl")) {
        std::cout << "fl: " << it << "\n";
	}

    std::cout << "There is " << (flags.GetIntList("i").size() == 0 ? "no" : "a") << " flag named `i`\n";;

    if (flags.GetBool("bool"))
        std::cout << "I'm so booling rn\n";
	
	return 1;
}
