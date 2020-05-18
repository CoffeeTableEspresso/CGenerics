//
// Created by thiabaud on 17/05/20.
//

#include "vect.h"

#define VECT_INIT_CAP 8

#define VECT_INSTANTIATE(T)\
struct VECT_NAME(T) {\
	size_t count, cap;\
	T *items;\
};\
\
Vect(T) v_init(T)(void) {\
	return {\
		0, VECT_INIT_CAP, malloc(VECT_INIT_CAP * sizeof(T))\
	};\
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
	v->items[v->count++] = t;\
}\
\
T v_pop(T)(Vect(T) *v) {\
	return v->items[--v->count];\
}\
\
T v_get(T)(Vect(T) *v, size_t idx) {\
	return v->items[idx];\
}

// uncomment to instantiate with int.
// VECT_INSTANTIATE(int)
