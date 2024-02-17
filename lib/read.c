#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// READ FUNCTION
void readFile(int argc, char **argv){
	FILE *file;
	file = fopen(argv[2], "r");
	if (file == NULL){
		color("-r", "error in the file open process");
		return;
	}

	bool lineNumberShow = false;
	int lineCount = 1;
	char lineStart[256];

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
			sprintf(lineStart, "%d : ", lineCount);
			color("-y", lineStart);
			lineCount++;
		}
		printf("%s", buffer);
	}
	return;
}
// READ FUNCTION