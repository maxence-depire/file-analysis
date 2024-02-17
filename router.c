#include <stdio.h>
#include "lib/color.c"
#include "lib/read.c"

char version[3] = "0.1";

// ROUTER FUNCTION
void router(int argc, char **argv){
	if (argc == 1){
		printf("for help use : ");
		colorString("-r", "cfile -h");
		return;	
	}
	else if (argc > 1){
		if (strcmp(argv[1], "-h") == 0){
			printf("cfile - version %s", version);
			printf("\n-r : Read file.");
		}
		if (strcmp(argv[1], "-r") == 0){
			readFile(argc, argv);
		}
	}
	return;
}
// ROUTER FUNCTION