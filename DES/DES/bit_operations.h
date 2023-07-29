#pragma once

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define BITS_IN_BYTE 8

int get_bit_at_position(unsigned char* str, int pos);
int set_bit_at_position(unsigned char* str, int pos, int new_bit);

void bits_shl(unsigned char* str);
void bits_shr(unsigned char* str);