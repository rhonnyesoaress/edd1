#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//***************** PRIVADO **********************
typedef struct _float_vector{
    int capacity; // num maximo de elementos
    int size; // num de elementos atualmente
    float *data; // vetor de float
}FloatVector;

bool _FloatVector_isFull(FloatVector *vec){
    return vec->capacity == vec->size;
}

//**************** PUBLICO **********************
FloatVector *FloatVector_create(int capacity){

    FloatVector *vec_float = (FloatVector*)calloc(1, sizeof(FloatVector));

    vec_float->capacity = capacity;
    vec_float->size = 0;
    vec_float->data = (float*)calloc(capacity, sizeof(float));

    return vec_float;
}

void FloatVector_destroy(FloatVector **vec_ref){
    FloatVector *vec = *vec_ref;
    free(vec->data);
    *vec_ref = NULL;
}

void FloatVector_append(FloatVector *vec, float val){
    if(isFull(vec)){
        fprintf(stderr, "ERROR in 'append'\n");
        fprintf(stderr, "Vector is full\n");
        exit(EXIT_FAILURE);
    }
    vec->data[vec->size] = val;
    vec->size++;
}

void FloatVector_print(const FloatVector *vec){
    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);
    puts("-----");

    for(int i = 0; i < vec->size; i++){
        printf("vec[%d] = %f\n", i, vec->data[i]);
    }
}

int FloatVector_size(const FloatVector *vec){
    return vec->size;
}

int FloatVector_capacity(const FloatVector *vec){
    return vec->capacity;
}

float FloatVector_at(const FloatVector *vec, int index){
    if(index < 0 || index > vec->size){
        fprintf(stderr, "ERROR in 'at'\n");
        fprintf(stderr, "Index inválido\n");
    }
    return vec->data[index];
}

float FloatVector_get(const FloatVector *vec, int index){
    return vec->data[index];
}

void FloatVector_set(FloatVector *vec, int index, float val){
    if(index < 0 || index > vec->size){
        fprintf(stderr, "ERROR in 'set'\n");
        fprintf(stderr, "Index inválido\n");
    }

    vec->data[index] = val;
}