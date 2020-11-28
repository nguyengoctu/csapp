#include <stdio.h>
#include <assert.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    int shift = i << 3;
    unsigned mask = 0xff;
    mask = ~(mask << shift);
    unsigned ub = (unsigned) b;
    return (x & mask) + (ub << shift); 
}

int main() {
    unsigned a = 0x12345678;
    unsigned char b = 0xab;
    // printf("%x\n", replace_byte(a, 0, b));
    // printf("%x\n", replace_byte(a, 2, b));
    assert(replace_byte(0x12345678, 2, 0xab) == 0x12ab5678);
    assert(replace_byte(0x12345678, 0, 0xab) == 0x123456ab);   
    return 0;
}