#include <Makefile/Makefile.h>
#include <Makefile/Recipe.h>
#include <Makefile/Procedure.h>
#include <Graph/MakeProcedure.h>
#include <Sys/CommandExecutioner.h>

#include <gtest/gtest.h>

namespace ym {
		class TestExecution : public ::testing::Test {
	public:
		using TestingMakefile = Makefile<Recipe>;
		using TestingProcedure = Procedure<Recipe>;
		using TestingProcedureMaker = MakeProcedure<TestingMakefile, Recipe, TestingProcedure>;
		using TestingExecution = CommandExecutioner<TestingProcedure>;

		TestExecution() {
			makefile.AddRecipe(Recipe("foo"));
			makefile.back().AddCommand("echo hello world");
		}

		TestingMakefile makefile;
	};


	TEST_F(TestExecution, CanMakeProcedure) {
		TestingProcedure procedure = TestingProcedureMaker::Create(makefile, "foo");
		TestingExecution::ExecuteCommands(procedure);
	}
}