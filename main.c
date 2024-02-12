#include <stdio.h>
#include <string.h>

char version[3] = "0.1";

void color(char code[5]){
	if (strcmp(code, "-y") == 0){
		printf("\033[1;33m");	
	}
	else if (strcmp(code, "-r") == 0){
		printf("\033[1;31m");
	}
	else if (strcmp(code, "-rs") == 0){
		printf("\033[0m");
	}
}

void readFile(int argc, char **argv){
	FILE *file;
	file = fopen(argv[2], "r");
	if (file == NULL){
		color("-r");
		printf("error in the file open process");
		color("-rs");
		return;
	}
	const unsigned MAX_SIZE = 256;
	char buffer[MAX_SIZE];
	while (fgets(buffer, MAX_SIZE, file)){
		printf("%s", buffer);
	}
}

void router(int argc, char **argv){
	if (argc == 1){
		printf("for help use : ");
		color("-r");
		printf("cfile -help");
		return;	
	}
	else if (argc > 1){
		if (strcmp(argv[1], "-help") == 0){
			printf("cfile - version %s", version);
			printf("\n-r : Read file.");
		}
		if (strcmp(argv[1], "-r") == 0){
			readFile(argc, argv);
		}
	}
}


int main(int argc, char **argv){
	
	router(argc, argv);
	printf("\n");
}
