//
// Created by Tobias on 08.04.2016.
//

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"


list_t * create () {
    list_t *l ;
    l = ( list_t *) calloc (1 , sizeof ( list_t ));
    l -> size = 8;
    l -> last = 0;
    l -> values = (int *) calloc (8 , sizeof (int ));
    l -> error = 0;
    return l;
}
