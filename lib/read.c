#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

#include "color.c"

// READ FUNCTION
void readFile(int argc, char **argv){

	FILE *file;
	file = fopen(argv[2], "r");

	char line[1024];
	int lineCounter = 0;

	if (file == NULL){
		printf("%serror in the file open process", RED);
		return;
	}

	while (fgets(line, sizeof(line), file) != NULL){

		printf("%s%d : %s", BYEL, lineCounter++, WHT);

		for (int i = 0; line[i] != 0; i++) {
			if (
				line[i] == '('
				|| line[i] == ')'
			) {
				printf("%s%c%s", GRN, line[i], WHT);
			}
			else if (
				line[i] == '{'
				|| line[i] == '}'
			) {
				printf("%s%c%s", RED, line[i], WHT);
			}
			else {
				printf("%c", line[i]);
			}
		}
	}

	return;
}
// READ FUNCTION