#pragma once

#include <string>
#include <deque>

namespace ym {

	template <typename RecipeType>
	class Makefile {
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
		std::deque<RecipeType> recipes;
	};
}