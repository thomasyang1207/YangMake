#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

namespace ym {
	template <typename MakefileType, 
				typename RecipeType, 
				typename ProcedureType>
	class MakeProcedure {
	public:
		static ProcedureType Create(MakefileType& makefile, std::string start) {
			// create the neccesary dependencyGraph starting from "start". 

			std::unordered_map<std::string, RecipeType *> recipeLookup; 
			std::unordered_set<std::string> visited;

			for(auto& r : makefile.recipes) {
				recipeLookup[r.targetName] = &r;
			}

			ProcedureType procedure;

			dfs(procedure, recipeLookup, visited, start);

			return procedure;
		}

	private:
		static void dfs(ProcedureType& procedure, 
						std::unordered_map<std::string, RecipeType *>& recipeLookup,
						std::unordered_set<std::string>& visited,
						std::string node) 
		{
			// visited? 
			if(visited.find(node) != visited.end()) return; // don't need to do anything anymore
			visited.insert(node);

			Recipe * recipe = recipeLookup[node];
			for(auto& dep : recipe->dependencies) {
				dfs(procedure, recipeLookup, visited, dep);
			}

			procedure.recipes.push_back(recipe); // push back the current procedure;
		}

	};
}