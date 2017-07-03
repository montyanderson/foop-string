#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foop.h"
#include "String.h"

void StringCat(char *str, size_t len) {
	string_t *this = _this;

	size_t offset = this->length;
	this->length += len;

	size_t size = this->size;

	while(this->size > (this->length + 1)) {
		this->size *= 2;
	}

	if(size != this->size) {
		this->raw = realloc(this->raw, this->size);
	}

	memcpy(this->raw + offset, str, len);
	this->raw[this->length] = 0x00;
}

void StringAppend(char *str) {
	StringCat(str, strlen(str));
}

void *StringSlice(size_t a, size_t b) {
	string_t *this = _this;
	string_t *str = new(String);

	$(str)->cat(this->raw + a, b - a);

	return str;
}

void StringPrint() {
	string_t *this = _this;

	printf("%s\n", this->raw);
}

void StringConstructor() {
	string_t *this = _this;

	this->size = 1;
	this->length = 0;
	this->raw = calloc(this->size, 1);

	this->cat = &StringCat;
	this->append = &StringAppend;
	this->slice = &StringSlice;
	this->print = &StringPrint;
}

void StringDestructor() {
	string_t *this = _this;

	free(this->raw);
}

const class_t _String = {
	&StringConstructor,
	&StringDestructor,
	sizeof(string_t)
};

const class_t *String = &_String;
