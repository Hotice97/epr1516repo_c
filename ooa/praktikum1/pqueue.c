//
// Created by Tobias on 08.04.2016.
//

#include "pqueue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct pqentry{
    char *value;
    float p;
} pqentry_t;

struct priorityqueue{
    pqentry_t *pqentrypointer;
    int size;
    int last; //index, nicht anzahl
};

priorityqueue_t *pqueue_create(){
    priorityqueue_t *tmp;

    tmp = malloc(sizeof(priorityqueue_t));
    if (tmp == NULL) {
        printf("\nSpeicherallokation fehlgeschlagen");
    }
    tmp->size = 0;

    return tmp;
}

void pqueue_insert(priorityqueue_t *pq, char* value, float p){ //läuft vom letzten index bis index 0
    if (pq->size == 0) { //falls noch kein speicher reserviert
        pq->pqentrypointer = malloc(sizeof(pqentry_t)*2);
        pq->pqentrypointer[0].p = p;
        pq->pqentrypointer[0].value = value;
        pq->size = 2;
        pq->last = 0;
    }
    else{
        //verdoppeln falls voll
        if (pq->last == (pq->size-1)) {
            pq->size *= 2;
            pq->pqentrypointer = realloc(pq->pqentrypointer, sizeof(pqentry_t)*pq->size); //doppelten speicher anlegen
        }

        //sortieren und einfügen
        if (pq->pqentrypointer[pq->last].p < p) { //falls letzter index.p kleiner als funktionsparameter p
            pq->pqentrypointer[pq->last+1].p = p;
            pq->pqentrypointer[pq->last+1].value = value;
        }
        else{
            for (int i = pq->last; i >= 0 && pq->pqentrypointer[i].p > p; i--) { //läuft bis index 0 solange index.p > p
                pq->pqentrypointer[i+1].p = pq->pqentrypointer[i].p;
                pq->pqentrypointer[i+1].value = pq->pqentrypointer[i].value;
                if (pq->pqentrypointer[i-1].p <= p || i == 0) { //falls nächstes element i-1 kleiner/gleich p ist, dann aktuelles element überschreiben
                    pq->pqentrypointer[i].p = p;
                    pq->pqentrypointer[i].value = value;
                }
            }
        }
        pq->last += 1;
    }
}

char *pqueue_extractMin(priorityqueue_t *pq){
    char *valueTmp = pq->pqentrypointer[0].value;

    for (int i = 0; i < pq->last; i++) {
        pq->pqentrypointer[i].p = pq->pqentrypointer[i+1].p;
        pq->pqentrypointer[i].value = pq->pqentrypointer[i+1].value;
    }

    pq->last -= 1;
    return valueTmp;
}

void pqueue_decreaseKey(priorityqueue_t *pq, char *value, float p){
    for (int i = 0; i < pq->size; i++) {
        if (pq->pqentrypointer[i].value == value) {
            if (pq->pqentrypointer[i+1].p < p) { //falls rechtes element kleiner p
                for (; pq->pqentrypointer[i+1].p < p; i++) { //laufe durch und überschreibe aktuelles element mit dem nächsten
                    pq->pqentrypointer[i].p = pq->pqentrypointer[i+1].p;
                    pq->pqentrypointer[i].value = pq->pqentrypointer[i+1].value;
                }
                pq->pqentrypointer[i].p = p;
                pq->pqentrypointer[i].value = value;
            }
            if (pq->pqentrypointer[i-1].p > p) { //falls linkes element größer p
                for (; pq->pqentrypointer[i-1].p > p; i--) { //laufe durch rückwärts, überschreibe aktuelles mit dem nächsten
                    pq->pqentrypointer[i].p = pq->pqentrypointer[i-1].p;
                    pq->pqentrypointer[i].value = pq->pqentrypointer[i-1].value;
                }
                pq->pqentrypointer[i].p = p;
                pq->pqentrypointer[i].value = value;
            }
        }
    }
}

void pqueue_remove(priorityqueue_t *pq, char* value){
    for (int i = 0; i < pq->size; i++) {
        if (pq->pqentrypointer[i].value == value) {
            for (int j = i; j <= pq->last; j++) {
                pq->pqentrypointer[j].p = pq->pqentrypointer[j+1].p;
                pq->pqentrypointer[j].value = pq->pqentrypointer[j+1].value;
            }
            pq->last -= 1;
            if ((pq->last+1) < (pq->size / 4)) { //halbieren falls nur ein viertel voll (anzahl elemente kleiner pq->size/4
                pq->pqentrypointer = realloc(pq->pqentrypointer, sizeof(pqentry_t)*(pq->size/2));
            }
        }
    }
}

void pqueue_destroy(priorityqueue_t *pq){
    free(pq->pqentrypointer);
    free(pq);
    pq = NULL;
}

void printentry (priorityqueue_t *pq){
    printf("\n");

    if(pq->size == 0){
        return;
    }
    else{
        for (int i = 0; i <= pq->last; i++) {
            printf("Entry: %d, Value: %s, Priority: %f\n", i, pq->pqentrypointer[i].value, pq->pqentrypointer[i].p);
        }
    }
    printf("\n");

}