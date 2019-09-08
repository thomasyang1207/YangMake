#include <Parse/Parse.h>
#include <Makefile/Makefile.h>
#include <Makefile/Recipe.h>


#include <fstream>
#include <cstdio>

#include <gtest/gtest.h>

namespace ym {
	class TestParse : public ::testing::Test {
	public:
		using TestingMakefile = Makefile<Recipe>;
		using TestingParser = Parse<TestingMakefile, Recipe>;

		TestParse() {
			// write some files 

			//Write file one...
			std::ofstream outFile("Makefile1");
			outFile << "foo : foo.o bar.o\n\techo \"hello world\"";
			outFile.close();
	

			std::ofstream outFile2("Makefile2");
			outFile2 << "foo : foo.o bar.o\n\techo \"hello world\"\n";
			outFile2 << "foo2 : foo.o bar.o\n\techo \"hello world\"\n\techo \"hello world\"\n";
			outFile2 << "foo3 : foo.o bar.o\n\techo \"hello world\"";
			outFile2.close();
	
		}

		~TestParse() {
			//close those files, maybe even call like os.delete
			std::remove("Makefile1");
			std::remove("Makefile2");
		}
	};

	TEST_F(TestParse, CanBuildParser) {
		TestingParser parser;
		SUCCEED();
	}

	TEST_F(TestParse, CanReadMakefile) {
		TestingParser parser;
		TestingMakefile makefile;

		std::ifstream file; 
		file.open("Makefile1", std::ifstream::in);

		ASSERT_TRUE(file);

		TestingParser::ParseFile(file, makefile);

		file.close();

		ASSERT_EQ(makefile.size(), 1);
		ASSERT_EQ(makefile.back().commands.size(), 1);
		ASSERT_EQ(makefile.back().dependencies.size(), 2);
	}

	TEST_F(TestParse, CanReadCorrectly) {
		TestingParser parser;
		TestingMakefile makefile;

		std::ifstream file; 
		file.open("Makefile1", std::ifstream::in);

		ASSERT_TRUE(file);

		TestingParser::ParseFile(file, makefile);

		file.close();

		ASSERT_EQ(makefile.size(), 1);
		ASSERT_EQ(makefile.back().commands.size(), 1);
		ASSERT_EQ(makefile.back().dependencies.size(), 2);

		ASSERT_EQ(makefile.size(), 1);
		ASSERT_EQ(makefile.back().commands.size(), 1);
		ASSERT_EQ(makefile.back().dependencies.size(), 2);

		ASSERT_STREQ(makefile.back().targetName.c_str(), "foo");
		ASSERT_STREQ(makefile.back().dependencies[0].c_str(), "foo.o");
		ASSERT_STREQ(makefile.back().dependencies[1].c_str(), "bar.o");
	}

	TEST_F(TestParse, CanReadMakefile2) {
		TestingParser parser;
		TestingMakefile makefile;

		std::ifstream file; 
		file.open("Makefile2", std::ifstream::in);

		ASSERT_TRUE(file);

		TestingParser::ParseFile(file, makefile);

		file.close();

		ASSERT_EQ(makefile.size(), 3);
		ASSERT_EQ(makefile.back().commands.size(), 1);
		ASSERT_EQ(makefile.back().dependencies.size(), 2);
	}


}