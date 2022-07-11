#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE 1000

int CheckRegisterSymbol(char symbol_text) {
int flag;
    if(symbol_text >= 'A' && symbol_text <= 'Z') {
        flag = 1;
    }
    else {
        flag = 0;
    }
return(flag);
    }
int IsAlphabet(char symbol) {
int flag;
    if((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
     flag = 0;
    }
    else {
     flag = 1;
    }
return(flag);
}

char LetterKey(char symbol_key) {
int flag = CheckRegisterSymbol(symbol_key);
if(flag == 1) {
    symbol_key = symbol_key + 32;
}
char key = symbol_key - 'a';
return(key);
}

int CheckKey(char key[]) {
int flag;
int counter = 0;
while (key[counter] != '\0') {
char symbol = key[counter];
    if(IsAlphabet(symbol) == 0) {
    flag = 0;
}
    else {
    flag = 1;
    return(flag);
}
counter++;
}
return(flag);
}

char StringKey(char argv[1] , int counter) {
char symbol = argv[counter];
return(symbol);
}



char ChangingText(char symbol_original_text , char symbol_key_text) {
int flag = IsAlphabet(symbol_original_text);
char changing_symbol;
    if(flag == 0) {
        changing_symbol = symbol_key_text;
}
    else {
        changing_symbol = symbol_original_text;
}
return(changing_symbol);
}

char Decrypted(char symbol , char symbol_key) {
    char key = LetterKey(symbol_key);
    int flag = CheckRegisterSymbol(symbol);
    if(flag == 1) {
        symbol = symbol + 32; }
    if(symbol >= 'a' && symbol <= 'z') {
        symbol = symbol - key;
    if(symbol < 'a') {
        symbol = (('a' - symbol) + 'a');
    }
    }
return(symbol);
}
int main(int argc , char* argv[]) {
    if(argc != 2) {
        return 1;
    }
    
int checkalphakey = CheckKey(argv[1]);
    if(checkalphakey == 1) {
        return 1;
    }
    
char key[ARRAY_SIZE];
int counter_argv = 0;
while(argv[1][counter_argv] != '\0') {
    key[counter_argv] = StringKey(argv[1] , counter_argv);
    counter_argv++;
}

char encryptedtext[ARRAY_SIZE];
printf("Encrypted text: ");
fgets(encryptedtext , ARRAY_SIZE , stdin);

int sizekey = strlen(key);
int counter_for_encryptedtext = 0;
int counter_for_key = 0;
int flag;
char changing_encryptext[ARRAY_SIZE];
while(encryptedtext[counter_for_encryptedtext] != '\0') {
char symbol_original_text = encryptedtext[counter_for_encryptedtext];
    if(counter_for_key == sizekey) {
        counter_for_key = 0;
}
char symbol_key_text = key[counter_for_key];
flag = IsAlphabet(symbol_original_text);
    if(flag == 0) {
        counter_for_key++;
}
char changing_symbol = ChangingText(symbol_original_text , symbol_key_text);
changing_encryptext[counter_for_encryptedtext] = changing_symbol;
counter_for_encryptedtext++;
}
int counter_for_decryptedtext = 0;
int flag_one;
while(encryptedtext[counter_for_decryptedtext] != '\0') {
char symbol_text = encryptedtext[counter_for_decryptedtext];
char key_symbol = changing_encryptext[counter_for_decryptedtext];
flag_one = CheckRegisterSymbol(symbol_text);
char decodechar = Decrypted(symbol_text , key_symbol);
printf("%c" , decodechar);
counter_for_decryptedtext++;
}
return 0;
}
