#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#define BUFF_SIZE 8192
void tail(FILE *input, int lines);

int main(int argc, const char * argv[]){
	int input_fd;
    ssize_t ret_in;
    FILE* fp; 
    char buffer[BUFF_SIZE];
    if(argc != 3){
        printf("Usage: cp file1 noOfLines");
        return 1;
    }
    fp = fopen(argv[1], "rb");
    char *noLines = argv[2];
    int val = atoi(noLines) - 1;    
    if(fp == -1){
        perror(argv[1]);
        return 2;
    }
    tail(fp, val);
    return 0;
}
void tail(FILE *input, int lines){
	int count = 0;
	unsigned long long noChars;
	char str[BUFF_SIZE]; 
	if(fseek(input, 0, SEEK_END)) 
		perror("fseek() failed!");
	else{
		noChars = ftell(input);
		printf("No Chars: %llu\n", noChars);
		while (noChars){ 
            if (!fseek(input, --noChars, SEEK_SET)){  // reverse fseek() loop. 
                if (fgetc(input) == '\n') 
                    if (count++ == lines) 
                        break; 
            } 
            else
                perror("fseek() failed"); 
        } 
        printf("Printing last %d lines -\n", lines+1); 
        while (fgets(str, sizeof(str), input)) 
            printf("%s", str); 
	}
	printf("\n"); 
}
