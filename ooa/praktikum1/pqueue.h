//
// Created by Tobias on 08.04.2016.
//

#ifndef EPR1516REPO_C_PQUEUE_H
#define EPR1516REPO_C_PQUEUE_H

#endif //EPR1516REPO_C_PQUEUE_H
//
//#ifndef pqueue_h
//#define pqueue_h
//
//
//#endif /* pqueue_h */

typedef struct priorityqueue priorityqueue_t;

priorityqueue_t *pqueue_create();

void pqueue_insert(priorityqueue_t *pq, char* value, float p);

char *pqueue_extractMin(priorityqueue_t *pq);

void pqueue_decreaseKey(priorityqueue_t *pq, char *value, float p);

void pqueue_remove(priorityqueue_t *pq, char* value);

void pqueue_destroy(priorityqueue_t *pq);

void printentry (priorityqueue_t *pq);

void pqsort(priorityqueue_t *pq, int left, int right);