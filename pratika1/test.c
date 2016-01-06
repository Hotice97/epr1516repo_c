//
// Created by Tobias on 25.11.2015.
//

#include <stdio.h>


char string[]="Ich mag EPR";

int main(){

    char* char_ptr1 = string + 4;

    char* char_ptr2 = string + 8;


    printf("%c lsmöajmsa\n",*string);

    printf("\n%s", string);
    printf("\n%s", char_ptr1);
    printf("\n%c", (*string + 2));

    printf("\n%s", char_ptr2);
    printf("\n%c", *(char_ptr1++));
    printf("\n%s", ++char_ptr1);

    printf("\n%d",string);
    printf("\n%d",char_ptr2);

    printf("\n%d", string < char_ptr2);

    return 0;
}