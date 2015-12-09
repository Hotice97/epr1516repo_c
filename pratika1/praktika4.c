//
// Created by Tobias on 08.12.2015.
//
#include <stdio.h>
int main(void) {

    printf("Beachte bei der Eingabe, dass beide Matrizen gleich gro� sind, d.h. gleich Anzahl an Spalten und Zeilen haben! Ansonsten k�nnen diese nicht addiert werden \n\n");

    //Matrix A
    unsigned int spalten1,zeilen1;
    int eintraege1,eintraege2;
    float eingabe1 = 0;
    printf("Gib die Anzahl der Spalten ein: ");
    scanf("%d", &spalten1);
    printf("Gib die Anzahl der Zeilen ein: ");
    scanf("%d", &zeilen1);
    eintraege1 = spalten1 * zeilen1;

    float matrix_a[zeilen1*spalten1];

    for(int i = 0; i<zeilen1*spalten1;i++){
        printf("Gib eine Zahl ein: ");
        scanf("%f", &eingabe1);
        matrix_a[i] = eingabe1;
        eingabe1 = 0;
    }
    int m = 0;
    printf("Ihre eingegebene Matrix lautet: \n\n");
    for(int j = sizeof(matrix_a)/ sizeof(matrix_a[0]);j>0;j-- ){

        printf("%10.3f ", matrix_a[m]);
        m ++;
        if(m%spalten1==0) {
            printf("\n");
        }

    }


    //Matrix B
    unsigned int spalten2,zeilen2;
    float eingabe2 = 0;
    printf("Gib die Anzahl der Spalten ein: ");
    scanf("%d", &spalten2);
    printf("Gib die Anzahl der Zeilen ein: ");
    scanf("%d", &zeilen2);
    eintraege2 = spalten2 * zeilen2;

    float matrix_b[zeilen2*spalten2];

    for(int k = 0; k<zeilen2*spalten2;k++){
        printf("Gib eine Zahl ein: ");
        scanf("%f", &eingabe2);
        matrix_b[k] = eingabe2;
        eingabe2 = 0;
    }
    int b = 0;
    printf("Ihre eingegebene Matrix lautet: \n\n");
    for(int l = sizeof(matrix_b)/ sizeof(matrix_b[0]);l>0;l-- ){

        printf("%10.3f ", matrix_b[b]);
        b ++;
        if(b%spalten2==0) {
            printf("\n");
        }

    }

    if(eintraege1!=eintraege2){
        printf("Die eingegebenen Matrizen konnten nicht addiert werden, sie sind nicht gleich gross");
        return 0;
    }

    int e = 0;
    float matrix_c[sizeof(matrix_b)/ sizeof(matrix_b[0])];
    //Addition
    printf("Die Matrix C die aus der Addition von Matrix A und Matrix B entstanden ist, lautet:\n\n ");
    for(int n = sizeof(matrix_b)/ sizeof(matrix_b[0]);n>0;n-- ){

        matrix_c[e] = matrix_a[e] + matrix_b[e];
        printf("%10.3f ", matrix_c[e]);
        e ++;
        if(e%spalten2==0) {
            printf("\n");
        }

    }

}