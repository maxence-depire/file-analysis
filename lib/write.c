#include <stdio.h>

void writeModifyLine(int argc, char **argv){
    FILE *file = fopen(argv[2], "r");
    FILE *temp_file = fopen("temp.txt", "w");
    
    char buffer[1024];
    int index = 1;
    char *t;
    long int target = strtol(argv[3], &t, 10);
    while (fgets(buffer, sizeof(buffer), file)){
        if (index == target){
            fputs(argv[4], temp_file);
        }
        else {
            fputs(buffer, temp_file);
        }
        index++;
    }

    fclose(file);
    fclose(temp_file);

    remove(argv[2]);
    rename("temp.txt", argv[2]);
}