// Project 7 - Tales from the crypt
// Jessica Salvino
// CMS 230, 2017

#include <stdio.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>
#include <stdlib.h>

char * crack(char *end, int n, int c, int l) {
    FILE *x = fopen("./words", "r"); // open file
    if (x == NULL) {
        perror("fopen");
        return NULL;
    }
    
    char *buffer = malloc(128);
    while(fgets(buffer, 128, x)) {
        char *salt = "$1$";
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        if (c) {
            buffer[0] ^= ' ';
        }
        if (l) {
            int i;
            for (i = 0; i < strlen(buffer); i++) {
                if (buffer[i] == 'a') {
                    buffer[i] = '@';
                }
                if (buffer[i] == 'e') {
                    buffer[i] = '3';
                }
                if (buffer[i] == 'i') {
                    buffer[i] = '!';
                }
                if (buffer[i] == 'l') {
                    buffer[i] = '1';
                }
                if (buffer[i] == 'o') {
                    buffer[i] = '0';
                }
                if (buffer[i] == 's') {
                    buffer[i] = '5';
                }
            }
        }
        if (n) {
            int d = 0;
            int wordLength = strlen(buffer);
            for (d = 0; d < 10; d++) {
                buffer[wordLength] = (d + '0');
                char *hashChar = crypt(buffer, salt);
                if (strcmp(end, hashChar) == 0) {
                    printf("%s  %s\n", buffer, hashChar);
                    fclose(x);
                    return buffer;
                }
            }
        } else {
            char *hash = crypt(buffer, salt);
            if (strcmp(end, hash) == 0) {
                printf("%s %s\n", buffer, hash);
                fclose(x);
                return buffer;
            }
        }
    }// end of while loop
    fclose(x); // close file
    return NULL;
}// end of crack function

int main(int argc, char *argv[]) {
    char *dictionary;
    char *input;
    char *output;
    int n = 0;
    int c = 0;
    int l = 0;
    char a;
    while((a = getopt(argc, argv, "i:o:d:ncl")) != -1) {
        if( a == 'i') {
            input = optarg;
        }
        if( a == 'o') {
            output = optarg;
        }
        if( a == 'd') {
            dictionary = optarg;
        }
        if( a == 'n') {
            n = 1;
        }
        if( a == 'c') {
            c = 1;
        }
        if( a == 'l') {
            l = 1;
        }
    } // end of while loop
    
    FILE *inputFile = fopen(input, "r"); // open inputFile
    FILE *outputFile = fopen(output, "w"); // open outputFile
    FILE *dictionaryFile = fopen(dictionary, "r"); //open dictionaryFile
    char buffer[128];
    while (fgets(buffer, sizeof (buffer), inputFile)) {
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        } 
        strtok(buffer, ":");
        char * hash = strtok(NULL, ":");
        printf("%s\n", hash);
        char *password = crack(hash, n, c, l);
        fprintf(outputFile, "%s\n", password);
        free(password);
    } // end of while loop
    
    fclose(inputFile); // close inputFile
    fclose(outputFile); // close outputFile
    fclose(dictionaryFile); // close dictionaryFile

    return 0;
}