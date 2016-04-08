//
// Created by Tobias on 08.04.2016.
//

#ifndef EPR1516REPO_C_LISTE_H
#define EPR1516REPO_C_LISTE_H

#endif //EPR1516REPO_C_LISTE_H

typedef struct {
    int size, last, *values;
    char error;

} list_t;

list_t *create();
char isFull ( list_t *l );
void increase ( list_t *l );
void decrease ( list_t *l );
void append ( list_t *l , int val );
int find ( list_t *l , int val );
int getValueAt ( list_t *l , int pos );
void erase ( list_t *l , int val );
void toScreen ( list_t *l );
void destroy ( list_t * l );

