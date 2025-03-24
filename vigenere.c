#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXN 1024
#define FILENAME_MAXN 1024

char * vigenere_decrypt(char* ciphertext, char * key){
    int text_length = strlen(ciphertext);
    int key_length = strlen(key);

    char * plaintext = (char*)malloc(sizeof(char) * (text_length+1));
    memset(plaintext, '\0', sizeof(char) * (text_length+1));
    int shift = 0;
    char * key_ptr = key;
    for(int i = 0; i<text_length; i++){
        if(isalpha(ciphertext[i])){
            shift = tolower(*key_ptr) - 'a';
            if(islower(ciphertext[i])){
                plaintext[i] = 'a' + (ciphertext[i] - 'a' - shift + 26) % 26;  // Добавяме 26, за да осигурим положителен резултат
            }
            else{
                plaintext[i] = 'A' + (ciphertext[i] - 'A' - shift + 26) % 26;  // Добавяме 26, за да осигурим положителен резултат
            }
            key_ptr++;
            if(*key_ptr == '\0')
                key_ptr = key;
        }
        else{
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[text_length] = '\0';
    return plaintext;
}

int read_input_file(char* filename, char* text)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Грешка при отваряне на файла.");
        return EXIT_FAILURE;
    }

    if(fgets(text, MAXN, fp) == NULL)
    {
        printf("Грешка при четене от файла.");
        return EXIT_FAILURE;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

void write_text(char* filename, char* text)
{
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "%s", text);
    fclose(fp);
}

char * read_filename_stdin(){
    char * filename = malloc(sizeof(char) * (FILENAME_MAXN+1));
    memset(filename, '\0', sizeof(char) * (FILENAME_MAXN+1));
    scanf("%s", filename);
    return filename;
}

int main(){
    
    char text[MAXN];
    char key[MAXN];

    read_input_file(read_filename_stdin(), text);
    read_input_file(read_filename_stdin(), key);

    
    char * decrypted_text = vigenere_decrypt(text ,key);
    puts(decrypted_text);
    write_text("vigenere_decrypted.txt", decrypted_text);

    free(decrypted_text);

    return EXIT_SUCCESS;
}
