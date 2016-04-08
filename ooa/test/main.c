//
// Created by Tobias on 08.04.2016.
//

# include <stdio.h >
#include <stdio.h>
# include "liste.h"
void main ( void ) {
    int i;
    list_t *l = create ();
    for (i = 1; i < 30; i ++)
        append (l , i );
    toScreen ( l );
    i = getValueAt (l , 30);
    if (l -> error != 0)
        printf (" value [%2 d] = %2 d\n " , 30 , i );
    destroy (l );
}