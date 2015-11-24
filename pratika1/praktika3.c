//
// Created by Tobias Grothusmann on 11.11.15.
//
#include <stdio.h>

float euro2dollar(float betrag, float umrechnungsfaktor){

    float ergebnis;
    ergebnis = betrag * umrechnungsfaktor;
  //  printf("Ihr Betrag in Dollar ist: ");
  //  printf("%f\n", ergebnis);
    return ergebnis;

}

float dollar2euro(float betrag, float umrechnungsfaktor){

    float ergebnis;
    ergebnis = betrag / umrechnungsfaktor;

  //  printf("Ihr Betrag in Euro ist: ");
  //  printf("%f\n", ergebnis);
    return ergebnis;

}


float printTableEuro2Dollar(float anfangswert, float endwert, float umrechnungsfaktor, float schrittgroeße){

    float ergebnis = 0;

    printf("Euro       |     Dollar\n");
    printf("-----------+-----------\n");
    while(anfangswert <= endwert){

        ergebnis = 0;
        //ergebnis = anfangswert * umrechnungsfaktor;
        ergebnis = euro2dollar(anfangswert,umrechnungsfaktor);
        printf("%f", anfangswert);
        printf(" | ");
        printf("%f \n", ergebnis);
        anfangswert = anfangswert + schrittgroeße;

    }

}


float printTableDollar2Euro(float anfangswert, float endwert, float umrechnungsfaktor, float schrittgroeße){

    float ergebnis = 0;

    printf("Dollar     |       Euro\n");
    printf("-----------+-----------\n");
    while(anfangswert <= endwert){

        ergebnis = 0;
        //ergebnis = anfangswert * umrechnungsfaktor;
        ergebnis = dollar2euro(anfangswert,umrechnungsfaktor);
        printf("%f", anfangswert);
        printf(" | ");
        printf("%f \n", ergebnis);
        anfangswert = anfangswert + schrittgroeße;

    }

}


int main(){
    float eurobetrag = 0;
    float dollarbetrag = 0;
    float umrechnungsfaktor = 1.3810095;


    printf("Gib den in Dollar umzurechnenden Betrag ein: ");
    scanf("%f", &eurobetrag);
    euro2dollar(eurobetrag, umrechnungsfaktor);
    printf("Gib den in Euro umzurechnenden Betrag ein: ");
    scanf("%f", &dollarbetrag);
    dollar2euro(dollarbetrag,umrechnungsfaktor);


    printf("Euro2Dollar Tabelle!\n");
    int eingabe = 0;
    int eingabe1 = 0;
    int eingabe2 = 0;
    printf("Geben sie den Anfangsbetrag (in Euro) ein: ");
    scanf("%d", &eingabe);
    printf("Geben sie den Endbetrag (in Euro) ein: ");
    scanf("%d", &eingabe1);
    printf("Geben sie die Schrittgroeße ein: ");
    scanf("%d", &eingabe2);

    printTableEuro2Dollar(eingabe,eingabe1,umrechnungsfaktor,eingabe2);


    printf("Dollar2Euro Tabelle!\n");
    eingabe = 0;
    eingabe1 = 0;
    eingabe2 = 0;
    printf("Geben sie den Anfangsbetrag (in Dollar) ein: ");
    scanf("%d", &eingabe);
    printf("Geben sie den Endbetrag (in Dollar) ein: ");
    scanf("%d", &eingabe1);
    printf("Geben sie die Schrittgroeße ein: ");
    scanf("%d", &eingabe2);

    printTableDollar2Euro(eingabe,eingabe1,umrechnungsfaktor,eingabe2);

    return 0;
}


