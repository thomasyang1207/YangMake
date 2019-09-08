#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <deque>
#include <iostream>

#include <sys/types.h>
#include <sys/wait.h>

namespace ym { 
	template<typename ProcedureType> 
	class CommandExecutioner {
	public:
		static void ExecuteCommands(ProcedureType& procedure) {
			//
			for(auto r: procedure.recipes) {
				for(auto com : r->commands) {
					ExecuteCommand(com);
				}
			} 
		}

	private:
		static void ExecuteCommand(std::string command) {
			std::stringstream ss(command);
			std::string com;
			std::getline(ss, com, ' ');

			std::deque<std::string> args;
			std::string line;
			while(std::getline(ss, line, ' ')) {
				args.push_back(line); // add a new argument.
			}

			int pid;

			if((pid = fork()) == 0) {
				int argc = args.size() + 1;
		        char ** argv = (char **)calloc(argc + 1, sizeof(char *));
		        
		        for(int i = 1; i < argc; i++){
		        	char * arg = (char *)calloc(args[i-1].size()+1, sizeof(char));
		        	memcpy(arg, args[i-1].c_str(), args[i-1].size());
		            argv[i] = arg;
		        }

		        std::cout << "Trying local" << std::endl;
		        
		        //Try local first.
		        char * argCom = (char *)calloc(com.size()+1, sizeof(char));
		        memcpy(argCom, com.c_str(), com.size());
		        argv[0] = argCom;
		        execv(argCom, argv);
		        free(argCom);

		        std::cout << "Trying bin" << std::endl;

		        //Try bin
		        //chdir("/bin");
		        std::string path = "/bin/" + com;
		        argCom = (char *)calloc(path.size()+1, sizeof(char));
		        memcpy(argCom, path.c_str(), path.size());
		        execv(path.c_str(), argv);
		        free(argCom);
		        
		        //if still here, then try to execute from usr functions
				std::cout << "Trying usr/bin" << std::endl;

				//chdir("/usr/bin");
		        path = "/usr/bin/" + com;
		        argCom = (char *)calloc(path.size()+1, sizeof(char));
		        memcpy(argCom, path.c_str(), path.size());
		        execv(argCom, argv);
		        free(argCom);
		        
		        std::cout << "Invalid Command : \"" << command << "\"" << std::endl;
		        free(argv);
		        exit(1); // exit code during failure...
			}

			int status;
			waitpid(pid, &status, 0);

			if(WIFSIGNALED(status)) {
				std::cout << "Failed to run command : \"" << command << "\"" << std::endl;
				exit(1);
			}
		}
	};

}