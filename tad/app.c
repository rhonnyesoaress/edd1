#include "float_vector.h"
#include "float_vector.c"
#include <stdio.h>

int main(){

    FloatVector *vec = create(10);
    FloatVector_print(vec);

    FloatVector_append(vec, 1.0);
    FloatVector_append(vec, 2.0);
    FloatVector_append(vec, 3.0);

    FloatVector_print(vec);

    FloatVector_destroy(&vec);

    return 0;
}