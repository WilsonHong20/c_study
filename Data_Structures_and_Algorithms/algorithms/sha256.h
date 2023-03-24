#ifndef sha256_h
#define sha256_h

#include<stdint.h>
#include<stddef.h>
#include<stdio.h>

void sha256(const unsigned char *data,size_t len,unsigned char *out);

#endif