#ifndef STRING
#define STRING

#include "foop.h"

typedef struct {
	char *raw;
	size_t length;
	size_t size;

	void (*cat)(char *, size_t);
	void (*append)(char *);
	void *(*slice)(size_t, size_t);
	void (*print)();
} string_t;

extern const class_t *String;

#endif
