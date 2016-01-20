//
// Created by Tobias on 06.01.2016.
//

#include "praktika5.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int isPalindrom(char *palin){

  int start,mitte,ende,laenge = strlen(palin);
    ende = laenge - 1; // \0 raus nehemen
    mitte = laenge /2 ;

    for (start = 0; start < mitte; start ++){
        if(palin[start] != palin[ende]){
            return 0;
        }
        ende --;
    }

    if(start == mitte){
        return 1;
    }

}
void removeNonLetters(char *palin){


    int i;
    for(i = 0;palin[i] != '\0'; i++){
        if(palin[i] < 65 || palin[i] > 90){
           if(palin[i] < 97 || palin[i] > 122){

               for(int j = i; j < strlen(palin); j ++){
                  palin[j] = palin[j+1];
               }
                                        i--;
           }

        }
    }


}

void tolower(char *palin){

    int i;
    for(i =0;palin[i] != '\0'; i++){

        if(palin[i] >= 65 && palin[i] <=90){ //if upper case
            palin[i] |= 32; //add 32 to get lower case
        }

    }

}

int main() {

    char one[200];

    while (true) {

        printf("Gib das zu pr�fende Wort ein! \n");
        scanf("%s", one);

        printf("Original: %s\n", one);

        if (isPalindrom(one) == 1) {
            printf("Palindrom: %s\n", one);
        } else {
            printf("kein Palindrom: %s\n", one);
        }

        removeNonLetters(one);

        printf("nach removeLetters: %s\n", one);

        if (isPalindrom(one) == 1){
            printf("Palindrom: %s\n", one);
        } else {
            printf("kein Palindrom %s\n", one);
        }

        tolower(one);

        printf("nach toLower: %s\n", one);

        if (isPalindrom(one) == 1){
            printf("Palindrom: %s\n",one);
        } else {
            printf("kein Palindrom %s\n", one);
        }

        printf("*************************\n");

    }

    return 0;
}