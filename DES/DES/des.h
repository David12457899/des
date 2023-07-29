#pragma once

#include "bit_operations.h"

#include <string.h>

#define DATA_CHUNCK_SIZE 64

typedef struct {
	unsigned char* lpt;
	unsigned char* rpt;
} pt_divide;

unsigned char* des_encrypt(unsigned char* str);