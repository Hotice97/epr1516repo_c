//
// Created by Tobias on 27.10.2015.
//

#include "c_praktika1.h"

int schaltjahr(int jahr){
    if( jahr%400==0 || jahr%4==0 && jahr%100!=0){
        printf("Das gewaehlte Jahr ist ein Schaltjahr");
    } else {
        printf("Das gewaehlte Jahr ist kein Schaltjahr");
    }
}

int jahresliste(int anfangsjahr, int endjahr){
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

int main(){
    int eingabe;
    int eingabe2;
    printf("Gib ein Jahr deiner Wahl ein: ");
    scanf("%d",&eingabe);
    schaltjahr(eingabe);
    printf("\nGib das Anfangsjahr ein: ");
    scanf("%d",&eingabe);
    printf("Gib das Endjahr ein: ");
    scanf("%d",&eingabe2);
    jahresliste(eingabe,eingabe2);
    return 0;
}