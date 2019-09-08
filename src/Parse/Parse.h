#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <cstdlib>
#include <unistd.h>

namespace ym {
	template <typename MakefileType, typename RecipeType> 
	class Parse {
	public:
		static void ParseFile(std::ifstream& file, MakefileType& makefile) {
			std::string line;

			while(std::getline(file, line)){
				// if first character is a tab: then it's a command. Otherwise, it's a defining a new target or a blank line.
				if(line.size() > 1 && line[0] == '\t') {
					if(makefile.size() == 0) {
						std::cout << "Command must be added to target" << std::endl;
						exit(1);
					}
					makefile.back().AddCommand(line.substr(1, line.size()-1));
				} else if(line.size() > 0) {
					ProcessNewTarget(line, makefile);
				}
			}

		}

	private:
		static void ProcessNewTarget(std::string& line, MakefileType& makefile) {
			std::string word;
			std::stringstream ss(line);
			// use a different "getline"
			ss >> word;
			if(word.size() > 0) {
				// defines a real target.
				makefile.AddRecipe(RecipeType(word));

				ss >> word;
				if(word != ":") {
					std::cout << "Parse Error - Expected \':\'" << std::endl;
					exit(1);
				}

				while(std::getline(ss, word, ' ')) {
					if(word.size() == 0) continue;
					makefile.back().AddDependency(word); // adds a dependency. 
				}
			}
		}
	};
}