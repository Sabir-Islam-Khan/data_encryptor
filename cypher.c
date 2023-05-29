// Author : MD Sabir Islam Khan..
// ID : 0242310005101420
// Description : This project is a data encryption / decryption program

// importing library functions
#include<stdio.h>
#include<string.h>
#include <sys/time.h>


#define elements(x)  (sizeof(x)/sizeof(x[0]))


// spinning cursor to show while processing data
void cursor(){
    char wheel[] = {'\\','|','/', '-'};

    for (int i=0; i<5; i++) {
        printf("\r%c", wheel[i%elements(wheel)]);
        fflush(stdout);
        sleep(1);
    }
}

// function to encrypt string
void encryptText(char* string){

    printf("\n\n Current Text is :\n\n");
    printf("\t %s\n\n",string);
    printf("  ********* Encrypting given data ************\n");
    cursor();

    int len = strlen(string);

    for(int i = 0; i < len; i++){

        int charCode = (int) string[i];

        if(charCode == 32 ) {
           // current character is space.. skipping

        } else if(charCode >= 97 ){

            // subtracting 60 from all lowercase characters [ A - Z ]
            charCode -= 60;\

        } else if( charCode >= 65 && charCode <= 90){

            // if current character is uppercase, removing 55 [ a - z ]
            charCode -= 55;

        }

        string[i] = (char) charCode;
    }
}

void decryptText(char* string){

    printf("\n\n Current Text is :\n\n");
    printf("\t %s\n\n",string);
    printf("  ********* Decrypting given data ************\n");
    cursor();
    int len = strlen(string);

    for(int i = 0; i < len; i++){
        int charCode = (int) string[i];

       if(charCode == 32 ){
        // current character is space. Skipping..

       } else if(charCode >= 37 && charCode <= 62){

           // adding 60 back again to lowercase letters to give back original form
            charCode += 60;

        } else if(charCode >= 10 && charCode <= 35){

            // same procedure for lowercase letters also
            charCode += 55;
        }

        string[i] = (char) charCode;
    }
}

// function to print encrypted text
void printEncryptedText(char* string){
     printf("\n\n Encrypted Text is :\n \t %s\n\n",string);
}

// function to print decrypted text
void printDecryptedText(char* string){
    printf("\n\n Decrypted Text is :\n \t %s\n\n",string);
}
// main program entry
int main(){

    char string[1000];

    printf("Please enter a text excluding numbers and special characters:\n");
    gets(string);
    // calling function to encrypt data
    encryptText(string);

    // calling custom print function to print encrypted data
    printEncryptedText(string);

    // calling function to decrypt data
    decryptText(string);

    // custom print function to display decrypted data
    printDecryptedText(string);
    return 0;
}
