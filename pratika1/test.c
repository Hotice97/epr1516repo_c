//
// Created by Tobias on 25.11.2015.
//

#include <stdio.h>
int produkt(int zahl1,int zahl2){
    unsigned int i = 0;
    unsigned long produkt = 1;
    for(i=zahl1;i<=zahl2;i++){
        produkt *= i;
    }
    return produkt;
}

main(void){
    unsigned int zahl1,zahl2;

    printf("Zah1= ");
    scanf("%u",&zahl1);
    printf("Zah2= ");
    scanf("%u",&zahl2);

    printf("Produkt aller Zahlen zwischen %u und %u = %u\n",zahl1,zahl2,produkt(zahl1,zahl2));
}
