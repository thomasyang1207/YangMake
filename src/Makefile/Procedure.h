#pragma once

#include <deque>


namespace ym { 
	template<typename RecipeType>
	class Procedure {
	public:
		std::deque<RecipeType*> recipes;
	};
}