//
// Created by Tobias on 08.04.2016.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pqueue.h"

#define MAX 100000

void testtreiber(){
    char *chptr1 = "Hallo";
    char *chptr2 = "Welt";
    char *chptr3 = "Wie";
    char *chptr4 = "geht";
    char *chptr5 = "es dir";
    char *chptr0;
    priorityqueue_t *pq = NULL;

    pq = pqueue_create();
    printf("\nNoch kein Element eingefügt\n");
    printentry(pq);

    printf("\nnachdem ein element eingefügt worden ist:\n");
    pqueue_insert(pq, chptr1, 12);
    printentry(pq);

    printf("\nnoch mehr sind eingefügt worden:\n");
    pqueue_insert(pq, chptr2, 5);
    pqueue_insert(pq, chptr3, 40000);
    pqueue_insert(pq, chptr4, 21);
    pqueue_insert(pq, chptr5, 33);
    printentry(pq);

    printf("\nnach extractMin:\n");
    chptr0 = pqueue_extractMin(pq);
    printentry(pq);

    printf("\nPrio von GEHT auf 2 setzen:\n");
    pqueue_decreaseKey(pq, chptr4, 2);
    printentry(pq);

    printf("\nHALLO entfernen\n");
    pqueue_remove(pq, chptr1);
    printentry(pq);

    printf("\nNach pqdestroy\n");
    pqueue_destroy(pq);
    printentry(pq);



}


char* randomString(int size) {
    int i;
    char* str = (char*) malloc((size+1)*sizeof(char));
    for(i = 0; i < size; ++i) {
        str[i] = (rand() % 26) + 'A';
    }
    str[size] = '\0';
    return str;
}

void testtreiber2(){
    int i;
    char* strings[MAX];
    clock_t tic, toc;

    srand(time(NULL));

    for(i = 0; i < MAX; ++i) {
        strings[i] = randomString(8);
    }

    priorityqueue_t *pq = pqueue_create();

    tic = clock();
    for(i = 0; i < MAX; ++i) {
        pqueue_insert(pq, strings[i], rand() % 100);
    }
    toc = clock();

    printf("insertion time: %.2f\n", (float)(toc-tic) / CLOCKS_PER_SEC);

    tic = clock();
    for(i = 0; i < MAX; ++i) {
        pqueue_extractMin(pq);
    }
    toc = clock();

    printf("extract tim: %.2f\n", (float)(toc-tic) / CLOCKS_PER_SEC);

    for(i = 0; i < MAX; ++i) {
        free(strings[i]);
    }
    pqueue_destroy(pq);
}

int main(void) {

    testtreiber2();

    return 0;
}