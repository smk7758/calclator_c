#pragma once

typedef struct {
  void **ptr;
  int size, cap;
} vec_t;

vec_t *vec_new();

void vec_push(vec_t *v, void *e);

void *vec_pop(vec_t *v);