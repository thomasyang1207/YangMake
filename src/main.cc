#include <iostream>
#include <fstream>
#include <string>

#include <Makefile/Makefile.h>
#include <Makefile/Recipe.h>
#include <Makefile/Procedure.h>
#include <Parse/Parse.h>

int main(int argc, char** argv) {
	// create all the objects
	using MakefileType = ym::Makefile<ym::Recipe>; 
	using Parser = ym::Parse<MakefileType, ym::Recipe>;

	MakefileType makefile; // empty makefile

	std::ifstream file;
	file.open("Makefile", std::ifstream::in);

	if(file){
		Parser::ParseFile(file, makefile);
	} else {
		std::cout << "Makefile not found" << std::endl;
	}




	return 0;
}