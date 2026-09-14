#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

void parse_input(char *line, char **args){
	//splits raw input line into tokens for execution
	int i = 0;
	args[i] = strtok(line, " \t\n");
	while(args[i] != NULL && i < MAX_ARGS - 1){
		i++;
		args[i] = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
}

int main(){

}
