#include "key_generator.h"

int main() {
    char* test = "1234567812345678123456781234567812345678123456781234567812345678";

    puts(test);
    test = discard_eighth_bits(test);
    puts(test);

    return 1;
}