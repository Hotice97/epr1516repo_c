//
// Created by Tobias Grothusmann on 11.11.15.
//
#include <stdio.h>
#include <jconfig.h>
#include <stdbool.h>

float euro2dollar(float betrag, float umrechnungsfaktor) {

    float ergebnis;
    ergebnis = betrag * umrechnungsfaktor;
    //  printf("Ihr Betrag in Dollar ist: ");
    //  printf("%f\n", ergebnis);
    return ergebnis;

}

float dollar2euro(float betrag, float umrechnungsfaktor) {

    float ergebnis;
    ergebnis = betrag / umrechnungsfaktor;

    //  printf("Ihr Betrag in Euro ist: ");
    //  printf("%f\n", ergebnis);
    return ergebnis;

}


float printTableEuro2Dollar(float anfangswert, float endwert, float umrechnungsfaktor, float schrittgroesse) {

    float ergebnis = 0;

    printf("Euro       |     Dollar\n");
    printf("-----------+-----------\n");
    while (anfangswert <= endwert) {

        ergebnis = 0;
        //ergebnis = anfangswert * umrechnungsfaktor;
        ergebnis = euro2dollar(anfangswert, umrechnungsfaktor);
        printf("%f", anfangswert);
        printf(" | ");
        printf("%f \n", ergebnis);
        anfangswert = anfangswert + schrittgroesse;

    }

}


float printTableDollar2Euro(float anfangswert, float endwert, float umrechnungsfaktor, float schrittgroesse) {

    float ergebnis = 0;

    printf("Dollar     |       Euro\n");
    printf("-----------+-----------\n");
    while (anfangswert <= endwert) {

        ergebnis = 0;
        //ergebnis = anfangswert * umrechnungsfaktor;
        ergebnis = dollar2euro(anfangswert, umrechnungsfaktor);
        printf("%f", anfangswert);
        printf(" | ");
        printf("%f \n", ergebnis);
        anfangswert = anfangswert + schrittgroesse;

    }

}

boolean schaltjahr(int jahr){

    if( jahr%400==0 || jahr%4==0 && jahr%100!=0){
        return true;
    } else {
        return false;
    }
}

int monateImJahr() {
    return 12;
}

int tageImMonat(int monat,int jahr) {
    if (monat == 2) {
        if(schaltjahr(jahr)){
            return 29;
        } else{
            return 28;
        }
    } else if (monat == 1 || monat == 3 || monat == 5 || monat == 7 || monat == 8 || monat == 10 || monat == 12) {
        return 31;
    } else {
        return 30;
    }
}

boolean checkDate(int tag, int monat, int jahr){
    if(monat > 12 || monat<1){
        return false;
    } else{
        if(monat == 2){
            if(schaltjahr(jahr)){
                if(tag > 29 || tag < 1){
                    return false;
                }
            } else{
                if(tag > 28 || tag < 1){
                    return false;
                }
            }
        } else if(tageImMonat(monat,jahr) == 30){
            if(tag > 30 || tag < 1){
                return false;
            }
        } else if(tageImMonat(monat,jahr) == 31){
            if(tag > 31 || tag < 1){
                return false;
            }
        }
    }
    if(jahr < 1){
        return false;
    }
    return true;
}




int main() {
//    float eurobetrag = 0;
//    float dollarbetrag = 0;
//    float umrechnungsfaktor = 1.3810095;
//
//
//    printf("Gib den in Dollar umzurechnenden Betrag ein: ");
//    scanf("%f", &eurobetrag);
//    euro2dollar(eurobetrag, umrechnungsfaktor);
//    printf("Gib den in Euro umzurechnenden Betrag ein: ");
//    scanf("%f", &dollarbetrag);
//    dollar2euro(dollarbetrag,umrechnungsfaktor);
//
//
//    printf("Euro2Dollar Tabelle!\n");
//    int eingabe = 0;
//    int eingabe1 = 0;
//    int eingabe2 = 0;
//    printf("Geben sie den Anfangsbetrag (in Euro) ein: ");
//    scanf("%d", &eingabe);
//    printf("Geben sie den Endbetrag (in Euro) ein: ");
//    scanf("%d", &eingabe1);
//    printf("Geben sie die Schrittgroeße ein: ");
//    scanf("%d", &eingabe2);
//
//    printTableEuro2Dollar(eingabe,eingabe1,umrechnungsfaktor,eingabe2);
//
//
//    printf("Dollar2Euro Tabelle!\n");
//    eingabe = 0;
//    eingabe1 = 0;
//    eingabe2 = 0;
//    printf("Geben sie den Anfangsbetrag (in Dollar) ein: ");
//    scanf("%d", &eingabe);
//    printf("Geben sie den Endbetrag (in Dollar) ein: ");
//    scanf("%d", &eingabe1);
//    printf("Geben sie die Schrittgroeße ein: ");
//    scanf("%d", &eingabe2);
//
//    printTableDollar2Euro(eingabe,eingabe1,umrechnungsfaktor,eingabe2);



    printf("%d Monate im Jahr\n", monateImJahr());

    int monat = 0;
    int jahr = 0;
    printf("Geben sie den zu pruefenden Monat ein ");
    scanf("%d", &monat);
    printf("Geben sie das Jahr ein ");
    scanf("%d", &jahr);
    printf("Der gewaehlte Monat hat %d Tage\n",tageImMonat(monat,jahr));

    monat = 0;
    int tag = 0;
    jahr = 0;
    printf("Geben sie den Tag ein ");
    scanf("%d", &tag);
    printf("Geben sie den Monat ein ");
    scanf("%d", &monat);
    printf("Geben sie das Jahr ein ");
    scanf("%d", &jahr);

    if(checkDate(tag,monat,jahr)){
        printf("Das eingebene Datum ist korrekt");
    } else{
        printf("Das eingebene Datum ist nicht korrekt");
    }


    return 0;
}


