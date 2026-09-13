#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** loadDictionary(const char *filename, int *wordCount){
	FILE *file = fopen(filename, "r");
	if(file == NULL){
		printf("Error: Could not open dictionary file %s\n");
		return NULL;
	}

	int capacity = 100;
	int count = 0;
	char **words = malloc(capacity * sizeof(char*));
	char buffer[32];

	while(fgets(buffer, sizeof(buffer), file) != NULL){
		buffer[strcspn(buffer, "\r\n")] = '\0';

		if(strlen(buffer) == 5){
			if(count >= capacity){
				capacity *= 2;
				char **temp = realloc(words, capacity * sizeof(char*));
				if(temp == NULL){
					fclose(file);
					return words;
				}
				words = temp;
			}
			words[count] = malloc(6 * sizeof(char));
			strcpy(words[count], buffer);
			count++;
		}
	}

	fclose(file);
	*wordCount = count;
	return words;
}


