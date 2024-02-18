#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

#include "color.c"

// READ FUNCTION
void readFile(int argc, char **argv){

	FILE *file;
	file = fopen(argv[2], "r");

	if (file == NULL){
		printf("%serror in the file open process", RED);
		return;
	}

	char line[1024];
	int lineIndex = 1;
	while (fgets(line, sizeof(line), file) != NULL){
		lineIndex++;
	}
	fseek(file, 0, 0);

	char lineIndexInString[256];
	sprintf(lineIndexInString, "%d", lineIndex);
	size_t lineNumberOfNumber = strlen(lineIndexInString);

	int lineCounter = 0;
	char lineCounterInString[256];
	while (fgets(line, sizeof(line), file) != NULL){

		lineCounter++;
		printf("%s", UBLK);
		sprintf(lineCounterInString, "%d", lineCounter);
		size_t lineCounterNumberOfNumber = strlen(lineCounterInString);
		int target = lineNumberOfNumber - lineCounterNumberOfNumber + 1;
		for (int x = 1; x != target; x++){
			printf("0");
		}
		printf("%d : %s", lineCounter, WHT);

		for (int i = 0; line[i] != 0; i++) {
			if (line[i]=='('||line[i]==')'){
				printf("%s%c%s", GRN, line[i], WHT);
			}
			else if (line[i] == '{'||line[i]=='}'){
				printf("%s%c%s", RED, line[i], WHT);
			}
			else if (line[i] == '['||line[i]==']'){
				printf("%s%c%s", BLU, line[i], WHT);
			}
			else if (line[i]=='#'){
				printf("%s%c%s", GRNHB, line[i], WHT);
			}
			else if (line[i]=='<'||line[i]=='>'){
				printf("%s%c%s", REDHB, line[i], WHT);
			}
			else{
				printf("%c", line[i]);
			}
		}
	}

	return;
}
// READ FUNCTION