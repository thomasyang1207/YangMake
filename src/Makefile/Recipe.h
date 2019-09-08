#pragma once

#include <string>

namespace ym {
	class Recipe {
	public:
		explicit Recipe(std::string targetName_) : targetName(targetName_) {}

	public:

		void AddDependency(std::string dep) {
			dependencies.push_back(dep);
		}

		void AddCommand(std::string command) {
			commands.push_back(command);
		}

	public:
		std::string targetName;
		std::deque<std::string> dependencies;
		std::deque<std::string> commands; // command to be executed
	};
}