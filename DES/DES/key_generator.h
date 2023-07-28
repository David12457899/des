#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 64
#define KEY_CHUNCK_SIZE 8

char* discard_eighth_bits(char* initial_key);