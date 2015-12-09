//
// Created by Tobias on 08.12.2015.
//
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

int anzeigen(int martikelnummern[], int arraylength){
    for(int i = 0; i < arraylength;i++){
        printf("%d ,",martikelnummern[i]);
    }
    printf("\n");
}

int finde_index(int martikelnummern[], int arraylength, int value) {
    int i;
    for (i=0; i<arraylength; i++)
    {
        if (martikelnummern[i] == value) {
            return i;
        }
    }
    return(-1);
}


int suchen(int maritkelnummer[], int value, int arraylength){

    int index;
    index = finde_index(maritkelnummer, arraylength, value);
    if (index == -1) {
        printf("Die gesuchte Martikelnummer %d konnte nicht gefunden werden.\n", value);
    } else {
        printf("Die gesuchte Martikelnummer %d wurde an der Stelle %d gefunden\n", value, index);
    }
}

int hinzufuegen(int martikelnummern[],int stelle, int value){
    martikelnummern[stelle] = value;
}

int loeschen(int marikelnummern[],int position,int arraylength){

    for(int i = position+1; i < arraylength;i++){
        marikelnummern[i - 1] = marikelnummern[i];
    }

    marikelnummern[arraylength-1] = 0;


}


int main(void) {
    int eingabe,eingabe3,eingabe4 = 0,eingabe5 = 0,eingabe6 = 0;

    printf("Wie gross soll das Array aus Martikelnummer sein? ");
    scanf("%d",&eingabe4);
    int arraylength = eingabe4 ;
    int arraystelle = 0;

//    int martikelnummern[arraylength];

    int martikelnummern[arraylength];
    for(int z =0;z<arraylength;z++){
        martikelnummern[z] = 0;
    }


    while(true) {
        eingabe = 0;
        printf("Sie befinden sich im Hauptmenue, was moechten sie tun? (1 = Alle Martikelnummer anzeigen , 2 = Nach einer Martikelnummer suchen, 3 = Hinzufuegen einer Martikelnumer , 4 = Loeschen einer Martikelnumer");
        scanf("%d", &eingabe);

        switch (eingabe){
            case 1: anzeigen(martikelnummern,arraylength);
                break;

            case 2:
                eingabe3 = 0;
                printf("Nach welcher Martikelnummer moechten sie suchen? ");
                scanf("%d",&eingabe3);
                suchen(martikelnummern,eingabe3,arraylength);
                break;

            case 3:eingabe5 = 0;
                printf("Welche Martikelnummer moechten sie hinzufuegen? ");
                scanf("%d",&eingabe5);
                if(finde_index(martikelnummern,arraylength, eingabe5)==-1){
                    if(arraystelle<arraylength){
                        hinzufuegen(martikelnummern, arraystelle, eingabe5);
                        arraystelle++;
                        printf("Die Martikelnummer wurde erfolgreich hinzugefügt!\n");
                    } else {
                        printf("Es können keine weiteren Martikelnummer hinzugefügt werden!\n");
                    }
                } else{
                    printf("Die gewählte Martikelnummer ist bereits vorhanden\n");
                }
                break;

            case 4:
                eingabe6 = 0;
                printf("Welche Martikelnummer wollen sie entfernen? ");
                scanf("%d",&eingabe6);
                if(finde_index(martikelnummern,arraylength,eingabe6)!=-1){
                    int index = finde_index(martikelnummern,arraylength,eingabe6);
                    loeschen(martikelnummern,index,arraylength);
                    printf("Erfolgreich entfernt\n");
                 } else{
                    printf("Entfernen fehlgeschlagen!\n");
                }
                break;
        }
    }
}
