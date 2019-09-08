#include <iostream>
#include <fstream>
#include <string>
#include <deque>

#include <Makefile/Makefile.h>
#include <Makefile/Recipe.h>
#include <Makefile/Procedure.h>
#include <Parse/Parse.h>
#include <Graph/DependencyGraph.h>
#include <Graph/MakeProcedure.h>
#include <Sys/CommandExecutioner.h>

int main(int argc, char** argv) {
	// create all the objects
	using MakefileType = ym::Makefile<ym::Recipe>; 
	using Parser = ym::Parse<MakefileType, ym::Recipe>;
	using DepGraph = ym::DependencyGraph<MakefileType, ym::Recipe>;
	using Procedure = ym::Procedure<ym::Recipe>;
	using ProcedureMaker = ym::MakeProcedure<MakefileType, ym::Recipe, Procedure>;
	using Execution = ym::CommandExecutioner<Procedure>;

	MakefileType makefile; // empty makefile


	std::ifstream file;
	file.open("Makefile", std::ifstream::in);

	if(file){
		Parser::ParseFile(file, makefile);
	} else {
		std::cout << "Makefile not found" << std::endl;
	}

	DepGraph depGraph(makefile);

	std::string target;
	if(argc == 1) target = "all";
	else if(argc == 2) target = std::string(argv[1]);
	else {
		std::cout << "Multi-target making is not yet supported... yet" << std::endl;
		exit(1);
	}

	if(!depGraph.IsValid()) {
		std::cout << "YangMake failed to make target \"" << target << "\"" << std::endl;
		exit(1);
	}


	if(argc == 1) {
		std::cout << "Still gotta figure out how to find the start of a directed graph" << std::endl;
	} else {	
		Procedure procedure = ProcedureMaker::Create(makefile, std::string(argv[1]));
		Execution::ExecuteCommands(procedure);
	}

	return 0;
}