//
//  main.c
//  OwnGrep
//
//  Created by Kamran Janjua on 10/2/18.
//  Copyright © 2018 Kamran Janjua. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#define BUFF_SIZE 8192
// Two utility functions for implementing searching in C.
char *search(char* input, char* query);
int compare(char *input, char *query);

int main(int argc, const char * argv[]) {
    int input_fd;
    ssize_t ret_in;
    char buffer[BUFF_SIZE];
    if(argc != 3){
        printf("Usage: cp file1 query");
        return 1;
    }
    input_fd = open(argv[1], O_RDONLY);
    if(input_fd == -1){
        perror(argv[1]);
        return 2;
    }
    char* asked_query = argv[2];
    ret_in = read(input_fd, &buffer, BUFF_SIZE);
    char *out = search(buffer, asked_query);
    if (out == NULL){
        printf("\033[1;31m");
        printf("Your query doesn't exist! RE-TRY.");
    }
    printf("\n");
    return 0;
}
char *search(char *input, char *query){
    char *output = "";
    while(*input != '\0'){
        if((*input == *query) && compare(input, query)){
            printf("Your query exists in the string: \n");
            printf("....");
            for(int i = 0; i < 20; i++){
                printf("\033[1;31m");
                printf("%c", input[i]);
            }
            printf("....");
            return output;
        }
        input++;
    }
    return NULL;
}
int compare(char *input, char *query){
    while(*input && *query){
        if(*input != *query)
            return 0;
        input++;
        query++;
    }
    return (*query == '\0');
}
