# C Generics
A sample of using macros to emmulate generics in C.

This is just a POC, to show it's possible or get your started on writing your own.

How it works:

Put `vect.c` and `vect.h` into your project.

Whenever you need a vector of type `T`, add `VECT_INSTANTIATE(T)` to `vect.c` and `VECT_DECL(T)` to `vect.h`.

Then, after including `vect.h`, you can do the following (assuming `T` is whatever type you want, for example `int`):

```
// Declare v
Vect(T) v;

// initialize v
v_init(T)(&v);

// add an element to v.
v_push(T)(&v, t);

// get the element at index 0
T tmp = v_get(T)(&v, 0);

// cleanup v
v_cleanup(T)(&v);
```

(There's not a better way to do this in C99 sadly, AFAIK.)
