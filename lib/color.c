#include <stdio.h>
#include <string.h>

// COLOR FUNCTION
void color(char code[5], char content[256]){
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
// COLOR FUNCTION