#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char version[3] = "0.1";

void colorChar(char code[5], char content[256]){
	if (strcmp(code, "-y") == 0){
		printf("\033[1;33m");	
	}
	else if (strcmp(code, "-r") == 0){
		printf("\033[1;31m");
	}
	else if (strcmp(code, "-rs") == 0){
		printf("\033[0m");
	}
	printf("%s", content);
	printf("\033[0m");
	return;
}

void colorInt(char code[5], int content){
	if (strcmp(code, "-y") == 0){
		printf("\033[1;33m");	
	}
	else if (strcmp(code, "-r") == 0){
		printf("\033[1;31m");
	}
	else if (strcmp(code, "-rs") == 0){
		printf("\033[0m");
	}
	printf("%d", content);
	printf("\033[0m");
	return;
}

void readFile(int argc, char **argv){
	FILE *file;
	file = fopen(argv[2], "r");
	if (file == NULL){
		colorChar("-r", "error in the file open process");
		return;
	}

	bool lineNumberShow = false;
	int lineCount = 1;

	for (int i = 0; i != argc; i++){
		if (strcmp("-l", argv[i]) == 0){
			lineNumberShow = true;
			break;
		}
	}

	const unsigned int MAX_SIZE = 256;
	char buffer[MAX_SIZE];
	while (fgets(buffer, MAX_SIZE, file)){
		if (lineNumberShow == true){
			colorInt("-y", lineCount);
			printf(" : ");
			lineCount++;
		}
		printf("%s", buffer);
	}
	return;
}

void router(int argc, char **argv){
	if (argc == 1){
		printf("for help use : ");
		colorChar("-r", "cfile -h");
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


int main(int argc, char **argv){
	router(argc, argv);
	colorChar("-rs", "");
	return 0;
}