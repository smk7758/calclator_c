#include "vector.h"
#include <stdlib.h>

#define NULL ((void *)0)
#define DEFAULT_SIZE 128

vec_t *vec_new() {
  vec_t *v = calloc(sizeof(vec_t), 1);
  v->ptr = calloc(sizeof(void *), DEFAULT_SIZE);
  v->cap = DEFAULT_SIZE;
  v->size = 0;
  return v;
}

void vec_push(vec_t *v, void *e) {
  if (v->size >= v->cap) {
    v->cap *= 2;
    v->ptr = realloc(v->ptr, v->cap * sizeof(vec_t));
  }
  v->ptr[v->size++] = e;
}

void *vec_pop(vec_t *v) {
  if (v->size == 0) return NULL;
  return v->ptr[--v->size];
}

void *vec_get(vec_t *v, int i) {
    if (v->size == 0) return NULL;
    return v->ptr[i];
}