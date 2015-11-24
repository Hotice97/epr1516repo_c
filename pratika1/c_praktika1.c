//
// Created by Tobias on 27.10.2015.
//

#include "c_praktika1.h"

int schaltjahr(){

    int eingabe;
    int eingabe2;
    printf("\nGib ein Jahr deiner Wahl ein: ");
    scanf("%d",&eingabe);
    int jahr= eingabe;

    if( jahr%400==0 || jahr%4==0 && jahr%100!=0){
        printf("Das gewaehlte Jahr ist ein Schaltjahr");
    } else {
        printf("Das gewaehlte Jahr ist kein Schaltjahr");
    }
}

int jahresliste(){

    int eingabe;
    int eingabe2;
    printf("\nGib das Anfangsjahr ein: ");
    scanf("%d",&eingabe);
    printf("Gib das Endjahr ein: ");
    scanf("%d",&eingabe2);
    int anfangsjahr = eingabe;
    int endjahr = eingabe2;

    do{
        if( anfangsjahr%400==0 || anfangsjahr%4==0 && anfangsjahr%100!=0){
            printf("%d",anfangsjahr);
            printf(": Ist ein Schaltjahr\n");
        } else {
            printf("%d",anfangsjahr);
            printf(": Ist kein Schaltjahr\n");
        }
        anfangsjahr ++;
    }while(anfangsjahr<=endjahr);
    return 0;
}

int binarytodecimal(){

    long int decimalNumber,rest,quotient;
    int binaryNumber[100],i=1,j;
    printf("Enter any decimal number: ");
    scanf("%ld",&decimalNumber);
    quotient = decimalNumber;
    while(quotient!=0){
        binaryNumber[i++]= quotient % 2;
        quotient = quotient / 2;
    }
    printf("Als binaere Zahl %d: ",decimalNumber);
    for(j = i-1 ;j > 0; j--){
        printf("%d",binaryNumber[j]);
    }
    return 0;
}


int main(){

    binarytodecimal();
    schaltjahr();
    jahresliste();


}