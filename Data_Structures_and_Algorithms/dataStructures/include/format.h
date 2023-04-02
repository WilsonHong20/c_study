#ifndef FORMAT_H
#define FORMAT_H

#include <stdio.h>
#include <stdarg.h>

void print_string(const char*str);
void print_interger(int num);
void print_float(float num);
void print_array(int size,int arr[]);
void va_format(const char* format, ...);


#endif