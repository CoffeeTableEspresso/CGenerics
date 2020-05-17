//
// Created by thiabaud on 17/05/20.
//

#include "vect.h"
#include <SDL2/SDL.h>

#define VECT_INIT_CAP 8

#define VECT_INSTANTIATE(T)\
struct VECT_NAME(T) {\
	size_t count, cap;\
	T *items;\
};\
\
void v_init(T)(Vect(T) *v) {\
	v->count = 0;\
	v->cap = VECT_INIT_CAP;\
	v->items = malloc(VECT_INIT_CAP * sizeof(T));\
};\
\
void v_cleanup(T)(Vect(T) *v) {\
	free(v->items);\
}\
\
void v_push(T)(Vect(T) *v, T t) {\
	if (v->count == v->cap) {\
		v->cap *= 2;\
		v->items = realloc(v->items, v->cap * sizeof(T));\
	}\
	v->items[v->count] = t;\
}\
\
T v_pop(T)(Vect(T) *v) {\
	return v->items[--v->count];\
}\
\
T v_get(T)(Vect(T) *v, size_t idx) {\
	return v->items[idx];\
}

VECT_INSTANTIATE(SDL_Rect)
