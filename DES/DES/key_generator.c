#include "key_generator.h"

char* discard_eighth_bits(char* initial_key) {
    int i = 0;
    char* new_key = 0;
    int copy_index = 0;

    new_key = calloc(KEY_SIZE - KEY_CHUNCK_SIZE + 1, sizeof(char));

    if (new_key == 0) {
        printf("Error discard_eighth_bits calloc..\n");
        exit(-1);
    }

    for (i = 0; i < KEY_SIZE; i += KEY_CHUNCK_SIZE) {
        memcpy(new_key + copy_index, initial_key + i, KEY_CHUNCK_SIZE - 1);
        copy_index += KEY_CHUNCK_SIZE - 1;
    }

    return new_key;
}