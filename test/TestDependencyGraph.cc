#include <Makefile/Makefile.h>
#include <Makefile/Recipe.h>
#include <Graph/DependencyGraph.h>


#include <gtest/gtest.h>

namespace ym {
	class TestDependencyGraph : public ::testing::Test {
	public:
		using TestingMakefile = Makefile<Recipe>;
		using TestingDependencyGraph = DependencyGraph<TestingMakefile, Recipe>;

		TestDependencyGraph() {
			makefile.AddRecipe(Recipe("foo"));
			makefile.back().AddDependency("bar");
			makefile.back().AddDependency("baz");

			makefile.AddRecipe(Recipe("bar"));
			makefile.back().AddDependency("qux");

			makefile.AddRecipe(Recipe("baz"));
			makefile.back().AddDependency("qux");

			makefile.AddRecipe(Recipe("qux"));



			unknownRecipeMakefile.AddRecipe(Recipe("foo"));
			unknownRecipeMakefile.back().AddDependency("bar");



			cyclicalMakefile.AddRecipe(Recipe("foo"));
			cyclicalMakefile.back().AddDependency("bar");
			cyclicalMakefile.AddRecipe(Recipe("bar"));
			cyclicalMakefile.back().AddDependency("foo");

		}

		TestingMakefile makefile;
		TestingMakefile unknownRecipeMakefile;
		TestingMakefile cyclicalMakefile;
	};

	TEST_F(TestDependencyGraph, CanMakeDependencyGraph) {

		TestingDependencyGraph depGraph(makefile);

		ASSERT_TRUE(depGraph.IsValid());

	}

	TEST_F(TestDependencyGraph, CannotMakeValidGraphIfUnknownRecipe) {

		TestingDependencyGraph depGraph(unknownRecipeMakefile);

		ASSERT_FALSE(depGraph.IsValid());

	}

	TEST_F(TestDependencyGraph, CannotMakeValidGraphIfCyclical) {

		TestingDependencyGraph depGraph(cyclicalMakefile);

		ASSERT_FALSE(depGraph.IsValid());

	}
}