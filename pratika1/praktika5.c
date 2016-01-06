//
// Created by Tobias on 06.01.2016.
//

#include "praktika5.h"
#include <stdio.h>
#include <string.h>

int isPalindrom(char *eins, char *zwei){

    printf("Hallo! %s\n",eins);




}

int main() {

    char two[200];
    char one[200];
    printf("Gib das zu prüfende Wort ein! \n");
    scanf( "%s" , one );


    if(isPalindrom(one,two)==1){
        printf("The entered string %s is a palindrome.\n", one);
    } else{
        printf("The entered string %s is not a palindrome.\n", one);
    }

    strrev(two);
    printf("The reverse of the string is %s.\n", two);
    return 0;
}