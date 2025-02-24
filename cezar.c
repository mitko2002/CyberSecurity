#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
 

char* cezar_chipher(char* str, int key)
{
    int lenght = strlen(str);
    char*cipher = (char*) malloc(sizeof(char)*(lenght+1));
    for(int i=0; i <lenght; i++)
    {
        if(str[i] >='a' && str[i] <= 'z')
        {
            cipher[i]=(str[i] - 'a' + key) % 26 +'a';

        }
    }
    cipher[lenght] = '\0';
    return cipher;


}
int main(){
char str[MAX];
scanf("%s",str);
int key;
scanf("%d", &key);
char* cipher = cezar_chipher(str,key);
printf("%s",cipher);
return EXIT_SUCCESS;
}
