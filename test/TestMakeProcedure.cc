#include <Makefile/Makefile.h>
#include <Makefile/Recipe.h>
#include <Makefile/Procedure.h>
#include <Graph/MakeProcedure.h>


#include <gtest/gtest.h>

namespace ym {
	class TestMakeProcedure : public ::testing::Test {
	public:
		using TestingMakefile = Makefile<Recipe>;
		using TestingProcedure = Procedure<Recipe>;
		using TestingProcedureMaker = MakeProcedure<TestingMakefile, Recipe, TestingProcedure>;

		TestMakeProcedure() {
			makefile.AddRecipe(Recipe("foo"));
			makefile.back().AddDependency("bar");
			makefile.back().AddDependency("baz");

			makefile.AddRecipe(Recipe("bar"));
			makefile.back().AddDependency("qux");

			makefile.AddRecipe(Recipe("baz"));
			makefile.back().AddDependency("qux");

			makefile.AddRecipe(Recipe("qux"));

		}

		TestingMakefile makefile;
	};


	TEST_F(TestMakeProcedure, CanMakeProcedure) {
		TestingProcedure procedure = TestingProcedureMaker::Create(makefile, "foo");
		ASSERT_EQ(procedure.recipes.size(), 4);
		ASSERT_STREQ(procedure.recipes[0]->targetName.c_str(), "qux");
		ASSERT_STREQ(procedure.recipes[3]->targetName.c_str(), "foo");
	}
}