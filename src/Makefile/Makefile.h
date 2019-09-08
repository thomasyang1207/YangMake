#pragma once

#include <string>
#include <deque>

namespace ym {

	template <typename RecipeType>
	class Makefile {
		// RecipeType specifies an implementation of a recipe. 
	public:
		Makefile() : numTargets(0) {}

	public:
		void AddRecipe(RecipeType && recipe) {
			recipes.push_back(recipe);
			numTargets++;
		}

		RecipeType& back() {
			return recipes.back();
		}

		int size() {
			return numTargets;
		}

		int numTargets;
		std::deque<RecipeType> recipes; // a recipe has a NAME... 
	};
}