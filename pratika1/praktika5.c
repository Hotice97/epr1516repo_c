//
// Created by Tobias on 06.01.2016.
//

#include "praktika5.h"
#include <stdio.h>
#include <string.h>

int isPalindrom(char *eins, char *zwei){

    strcpy(zwei, eins);
    strrev(zwei);

    if(strcmp(eins, zwei) == 0){
        return 1;
        printf("The entered string %s is a palindrome.\n", eins);
    } else{
        return 2;
        printf("The entered string %s is not a palindrome.\n", eins);
    }

    printf("The reverse of the string is %s.\n", zwei);
}

char removeNonLetters(char *eins){


}

int main() {

    char two[200];
    char one[200];
    printf("Gib das zu prüfende Wort ein! \n");
    scanf( "%s" , one );

    *one = removeNonLetters(one);

    printf("Refactor %s\n", one);

    if(isPalindrom(one,two)==1){
        printf("Das eingegebene Wort %s ist ein Palindrom.\n", one);
    } else{
        printf("Das eingegebene Wort %s ist kein Palindrom.\n", one);
    }



    return 0;
}