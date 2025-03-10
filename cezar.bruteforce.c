#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
#define ALPHA_LENGTH 26
char* cezar_decipher(char* str, int key){
    int length = strlen(str);
    char* plaintext = (char*) malloc (sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        if (str [i] >= 'a' && str[i] <= 'z') {
            plaintext[i]= ((str[i] - 'a') - key + 26) % 26 + 'a';
        }
        else if (str [i] >= 'A' && str[i] <= 'Z') {
            plaintext[i]= ((str[i] - 'A') - key + 26) % 26 + 'A';
        } 
        else if(str [i] >= '0' && str [i] <= '9') {
            plaintext[i] = ((str[i] - '0') - key + 10) % 10 + '0';
        }
        else {
            plaintext[i] = str[i];
        }
    }
    return plaintext;
}

int read_cipher(char* filename, char* str) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening the file!");
        return EXIT_FAILURE;
    }

    if (fgets(str, MAXN, fp) == NULL) {
        printf("Error reading from file.");
        return EXIT_FAILURE;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}

int main () {
    char cipher[MAXN];
    scanf("%s", cipher);

    for (int key = 0; key < ALPHA_LENGTH; key++) {
        char* plaintext = cezar_decipher(cipher, key);
        printf("%s, key = %d -> %s\n", cipher, key, plaintext);
        free(plaintext);
    }

    return EXIT_SUCCESS;
}
