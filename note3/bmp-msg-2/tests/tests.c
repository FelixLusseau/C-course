#include <stdio.h>
#include <string.h>

#include "tps_unit_test.h"
#include "encoder.h"

TEST_INIT_GLOBAL

const uint8_t fullset[] = {
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF
};

void test_1(void)
{
    FILE * in = fopen("test-file.bin", "w+");
    tps_assert(in != NULL);

    fwrite(fullset, 1, 8, in);
    rewind(in);

    encode_byte(in, 0b10011001, 1);
    rewind(in);
    uint8_t buffer[8];
    fread(buffer, 1, 8, in);

    const uint8_t expected[] = {
        0xFF, 0xFE, 0xFE, 0xFF,
        0xFF, 0xFE, 0xFE, 0xFF
    };

    tps_assert(memcmp(buffer, expected, 8) == 0);

    rewind(in);

    uint8_t decoded = decode_byte(in, 1);

    tps_assert(decoded == 0b10011001);
    fclose(in);
}

int main(void)
{
  TEST(test_1);
}
