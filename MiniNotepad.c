#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** addLine(char **lines, int *lineCount, int *capacity){
//Captures user input, handles array resizing if full, and allocates memory for the new string
	if (*lineCount >= *capacity){
		*capacity = (*capacity == 0) ? 4 : *capacity * 2;
		char **temp = realloc(lines, (*capacity) * sizeof(char*)); 
		if (temp == NULL){
			fprintf(stderr, "Error: Failed to allocate memory.\n");
			exit(EXIT_FAILURE);
		}
		lines = temp;
	}
	char buffer[256];
	printf("Enter line %d: ", *lineCount + 1);
	if (fgets(buffer, sizeof(buffer), stdin) != NULL){
		buffer[strcspn(buffer, "\n")] = '\0';
		lines[*lineCount] = malloc(strlen(buffer) + 1);
		if (lines[*lineCount] == NULL){
			fprintf(stderr, "Error: Failed to allocate memory.\n");
			exit(EXIT_FAILURE);
		}
	strcpy(lines[*lineCount], buffer);
	(*lineCount)++;
	}
	return lines;
}


void printNotepad(char **lines, int lineCount){
//Iterates through the line pointers and displays the current buffer with line numbers
	if(lineCount == 0){
		printf("\n[Notepad is currently empty]\n");
		return;
	}

	printf("\n---Notepad Buffer---\n");
	for(int i = 0; i < lineCount; i++){
		printf("%3d | %s\n", i + 1, lines[i]);
	}
	printf("----------------------\n");
}

void freeNotepad(char **lines, int lineCount){
//Frees every individual line string first, then frees the main lines array pointer to prevent leaks
	for(int i = 0; i < lineCount; i++){
		free(lines[i]);
	}
	free(lines);
}

int main(void){
//Implement functions
}
