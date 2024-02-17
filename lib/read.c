#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

// READ FUNCTION
void readFile(int argc, char **argv){

	FILE *file;
	file = fopen(argv[2], "r");

	char line[1024];
	int lineCounter = 0;

	if (file == NULL){
		colorString("-r", "error in the file open process");
		return;
	}

	while (fgets(line, sizeof(line), file) != NULL){

		printf("\033[1;33m%d :\033[0m ", lineCounter++);

		for (int i = 0; line[i] != 0; i++) {
			if (
				line[i] == '('
				|| line[i] == ')'
			) {
				colorChar("-r", line[i]);
			}
			else if (
				line[i] == '{'
				|| line[i] == '}'
			) {
				colorChar("-y", line[i]);
			}
			else {
				printf("%c", line[i]);
			}
		}
	}

	return;
}
// READ FUNCTION