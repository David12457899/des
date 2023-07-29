#include "des.h"

static pt_divide* get_initial_permutation(unsigned char* str);

static int initial_permutation_table[DATA_CHUNCK_SIZE] = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52,
	44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32,
	24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };

unsigned char* des_encrypt(unsigned char* str) {
	pt_divide* pt_parts = get_initial_permutation(str);


}

static pt_divide* get_initial_permutation(unsigned char* str) {
	// todo:test
	int i = 0;
	pt_divide* pt_div = 0;
	int DATA_CHUNCK_SIZE_HALF = DATA_CHUNCK_SIZE / 2;
	int temp_table[DATA_CHUNCK_SIZE] = {0};

	pt_div = malloc(sizeof(pt_divide));

	if (pt_div == NULL) {
		return NULL;
	}

	pt_div->lpt = malloc(DATA_CHUNCK_SIZE_HALF);
	pt_div->rpt = malloc(DATA_CHUNCK_SIZE_HALF);

	if (pt_div->lpt == NULL || pt_div->rpt == NULL) {
		return NULL;
	}

	for (i = 0; i < DATA_CHUNCK_SIZE; i++) {
		temp_table[i] = str[initial_permutation_table[i]];
	}

	memcpy(pt_div->lpt, temp_table, DATA_CHUNCK_SIZE_HALF / BITS_IN_BYTE);
	memcpy(pt_div->lpt, temp_table + DATA_CHUNCK_SIZE_HALF, DATA_CHUNCK_SIZE_HALF / BITS_IN_BYTE);

	return pt_div;
}

