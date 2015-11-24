//
// Created by Tobias Grothusmann on 02.11.15.
//

#include <stdio.h>

int forschleife(float dezzahl, int anzahl) {
    printf("Das Ergebnis als for Schleife ist:      0,");
    float nachkommazahl = dezzahl;
    for (int i = 0; i < anzahl; i++) {

        //Prüfung ob die Fließkommazahl verdoppelt größer als 1 ist
        if ((nachkommazahl * 2) >= 1) {
            printf("1");
            nachkommazahl = (nachkommazahl * 2) - 1;
        }
        else {

            printf("0");
            nachkommazahl = nachkommazahl * 2;
        }

    }
    printf("\n");

}

int whileschleife(float dezzahl, int anzahl) {
    printf("Das Ergebnis als while Schleife ist:    0,");
    float nachkommazahl = dezzahl;
    int k = 0;
    while (k < anzahl) {

        if ((nachkommazahl * 2) >= 1) {

            printf("1");
            nachkommazahl = (nachkommazahl * 2) - 1;
        }
        else {

            printf("0");
            nachkommazahl = nachkommazahl * 2;
        }
        k++;
    }
    printf("\n");
}

int dowhileschleife(float dezzahl, int anzahl) {
    printf("Das Ergebnis als do-while Schleife ist: 0,");
    float nachkommazahl = dezzahl;
    int l = 0;

    do {
        if ( anzahl == 0){
            break;
        }

        if ((nachkommazahl * 2) >= 1) {

            printf("1");
            nachkommazahl = (nachkommazahl * 2) - 1;
        }
        else {

            printf("0");
            nachkommazahl = nachkommazahl * 2;
        }
        l++;
    } while (l < (anzahl));
    printf("\n");
}

int main() {

    float dezzahl = 0;
    int anzahl;

    printf("Gleitkommazahl zwischen 0 und 1:\n");

    do {

        scanf("%f", &dezzahl);

        if (!(0 < dezzahl && dezzahl < 1)) {
            printf("Bitte wiederholen Sie die Eingabe:\n");
        }

    } while (!(0 < dezzahl && dezzahl < 1));

    printf("Anzahl der Nachkommastellen:\n");
    scanf("%d", &anzahl);

    forschleife(dezzahl, anzahl);
    whileschleife(dezzahl, anzahl);
    dowhileschleife(dezzahl, anzahl);

    return 0;


    //0.375   0,011
    //0.6876  0,10110000000001101
    //0.1     0,000110011001100110011001101
    //0.3     0,010011001100110011001101

}

