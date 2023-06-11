// Author : MD Sabir Islam Khan..
// ID : 0242310005101420
// Description : This project is a data encryption / decryption program

// importing library functions
#include<stdio.h>
#include<string.h>
#include <sys/time.h>
#include <stdbool.h>
#include <windows.h>
#include<wchar.h>
#include <stdlib.h>

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

        }  else if(charCode >= 48 && charCode <= 57) {

            // current character is a number. Adding 15 to ascii value to randomize
            charCode += 15;

        } else if( charCode >= 33 && charCode <= 47 ) {

            // first subset of special characters
            charCode += 40;

        } else if(charCode >= 58 && charCode <= 64 ){
            // second subset of special characters
            charCode += 30;

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

       }  else if( charCode >= 63 && charCode <= 72){

           // current charact
            charCode -= 15;

       }
       else if(charCode >= 73 && charCode <= 87 ) {

           // first subset of special characters. Removing 40 to get original form
            charCode -= 40;
       } else if(charCode >= 88 && charCode <= 94){
           // second subset of special characters
            charCode -= 30;
       }
        else if(charCode >= 37 && charCode <= 62){

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

    const wchar_t* string;

    bool flag = true;
    char buffer;

    while(flag){
        int choice;
        printf("Please enter choice to continue:\n");
        printf("1. Encrypt Data\n");
        printf("2. Decrypt Data\n");
        printf("0. Exit Application\n");

        scanf("%d",&choice);

        switch(choice) {
        case 1:

                printf("Please enter a text to encrypt:\n");
                fflush(stdin);
                gets(string);
                encryptText(string);
                printEncryptedText(string);

                FILE* file = fopen("encrypted.txt", "w");
                if (file == NULL) {
                printf("Failed to open the file.\n");
                return 1;
                }
                size_t length = wcslen(string);

                fwrite(string, sizeof(wchar_t), length, file);  // Write text to the file

                fclose(file); // Close the file

                printf("Data written to the file successfully.\n");

                continue;
        case 2:
                printf("Enter encrypted text:\n\n");
                fflush(stdin);
                gets(string);
                decryptText(string);
                printDecryptedText(string);
                continue;
        case 0:
                flag = false;
        }
    }

    printf("\n\n\n\t\t\t********** Thank You **********\n\n\n");
    return 0;
}
