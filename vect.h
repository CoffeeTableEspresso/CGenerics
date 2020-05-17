//
// Created by thiabaud on 17/05/20.
//

#ifndef EXAMPLE_VECT_H
#define EXAMPLE_VECT_H

#include <stdlib.h>

#define VECT_NAME(T) v_##T
#define CAT(A, B) A##B
#define CAT_EXPAND(A, B) CAT(A, B)
#define VECT_FUN_NAME(T, fun) CAT_EXPAND(VECT_NAME(T), fun)

#define Vect(T) struct VECT_NAME(T)
#define v_init(T) VECT_FUN_NAME(T, _init)
#define v_cleanup(T) VECT_FUN_NAME(T, _cleanup)
#define v_push(T) VECT_FUN_NAME(T, _push)
#define v_pop(T) VECT_FUN_NAME(T, _pop)
#define v_get(T) VECT_FUN_NAME(T, _get)

#define VECT_DECL(T)\
struct VECT_NAME(T) {\
	size_t count, cap;\
	T *items;\
};\
\
void v_init(T)(Vect(T) *v);\
void v_cleanup(T)(Vect(T) *v);\
void v_push(T)(Vect(T) *v, T t);\
T v_pop(T)(Vect(T) *v);\
T v_get(T)(Vect(T) *v, size_t idx);

// uncomment to declare vector of int.
// VECT_DECL(int)

#endif //EXAMPLE_VECT_H
