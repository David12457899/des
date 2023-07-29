#include "bit_operations.h"

static int _get_bit_at_position_in_byte(unsigned char byte, int pos);
static unsigned char _get_set_bit_at_position_in_byte(unsigned char byte, int pos, int bit);
static unsigned char _unset_bit_at_position_on_byte(unsigned char byte, int pos);
static int _generate_flag_for_pos(int pos);

int get_bit_at_position(unsigned char* str, int pos) {
	int bytes_size = strlen(str);

	if (pos > bytes_size * BITS_IN_BYTE - 1) {
		return -1;
	}

	int index = pos / BITS_IN_BYTE;

	return _get_bit_at_position_in_byte(str[index], pos);
}

int set_bit_at_position(unsigned char* str, int pos, int new_bit) {
	int bytes_size = strlen(str);

	if (pos > bytes_size * BITS_IN_BYTE - 1) {
		return -1;
	}

	int index = pos / BITS_IN_BYTE;
	
	unsigned char new_byte = _get_set_bit_at_position_in_byte(str[index], pos, new_bit);
	str[index] = new_byte;

	return 0;
}

void bits_shl(unsigned char* str) {
	int i = 0;
	int length = strlen(str);

	int saved_first_bit = get_bit_at_position(str, 0);
	
	for (i = 1; i < length * BITS_IN_BYTE; i++) {
		set_bit_at_position(str, i - 1, get_bit_at_position(str, i));
	}

	set_bit_at_position(str, length * BITS_IN_BYTE - 1, saved_first_bit);
}

void bits_shr(unsigned char* str) {
	int i = 0;
	int length = strlen(str);

	int saved_last_bit = get_bit_at_position(str, length * BITS_IN_BYTE - 1);

	for (i = length * BITS_IN_BYTE - 1; i > 0 ; i--) {
		set_bit_at_position(str, i + 1, get_bit_at_position(str, i));
	}

	set_bit_at_position(str, 0, saved_last_bit);
}

static int _get_bit_at_position_in_byte(unsigned char byte, int pos) {
	int flag = _generate_flag_for_pos(pos);

	return (byte & flag) == flag;
}

static unsigned char _get_set_bit_at_position_in_byte(unsigned char byte, int pos, int bit) {
	int flag = _generate_flag_for_pos(pos);
	byte = _unset_bit_at_position_on_byte(byte, pos);

	return bit ? (byte | flag) : byte;
}

static unsigned char _unset_bit_at_position_on_byte(unsigned char byte, int pos) {
	int flag = _generate_flag_for_pos(pos);

	return byte & (~flag);
}

static int _generate_flag_for_pos(int pos) {
	/*
	* Generates a value to use binary AND (&) with later
	*
	* Example: byte - 01101110, pos - 2 (start index is 0)
	* flag would be 00100000
	*/
	return (int)(pow(2, (BITS_IN_BYTE - (pos % BITS_IN_BYTE) - 1)));
}