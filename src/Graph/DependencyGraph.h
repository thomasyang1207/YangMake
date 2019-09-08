// The actual Dependency Graph that we're gonna be using 

#include <unordered_map>
#include <string>
#include <deque>
#include <iostream>

namespace ym {
	template<typename MakefileType, typename RecipeType>
	class DependencyGraph {
	public:
		explicit DependencyGraph(MakefileType& makefile_) : makefile(makefile_) {
			adjList = std::deque<std::deque<int>>(makefile_.recipes.size(), std::deque<int>());
			reverseLookup = std::deque<std::string>(makefile_.recipes.size(), "");
		}

	public:
		bool IsValid() {
			for(int i = 0; i < makefile.recipes.size(); i++) {
				if(lookup.find(makefile.recipes[i].targetName) != lookup.end()) {
					std::cout << "Redefinition of target \"" << makefile.recipes[i].targetName << "\"" << std::endl;
					return false;
				}
				lookup[makefile.recipes[i].targetName] = i;
				reverseLookup[i] = makefile.recipes[i].targetName;
			}

			for(auto& r: makefile.recipes) {
				for(std::string& dep : r.dependencies) {
					if(lookup.find(dep) == lookup.end()) {
						std::cout << "No rule to make \"" << dep << "\". Stop" << std::endl;
						return false;
					} else {
						adjList[lookup[r.targetName]].push_back(lookup[dep]);
					}
				}
			}

			return !hasCycle();
		}


		std::unordered_map<std::string, int> lookup;
		std::deque<std::string> reverseLookup;
		std::deque<std::deque<int>> adjList;
		MakefileType& makefile;

	private:
		bool hasCycle() {
			std::deque<int> state(adjList.size(), 0);

			for(int i = 0; i <  adjList.size(); i++){
				if(state[i] == 2) continue;
				if(dfs(state, i)) {
					std::cout << "Unsatisfiable dependency detected" << std::endl;
					return true; // no
				}
			}

			return false;
		}

		bool dfs(std::deque<int>& state, int node) {
			if(state[node] == 1) {
				state[node] = 2;
				return true;
			}

			state[node] = 1;
			for(auto n : adjList[node]) {
				if(dfs(state, n)) {
					state[node] = 2;
					return true;
				}
			}

			state[node] = 2; // once we're done...
			return false;
		}
	};
}