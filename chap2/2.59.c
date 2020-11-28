#include <stdio.h>
#include <assert.h>

size_t operation(size_t a, size_t b) {
    size_t mask = 0xff;
    return (mask & a) + (~mask & b);
}

int main() {
    size_t res = operation(0x89abcdef, 0x76543210);
    assert(res == 0x765432ef);
    printf("%x", res);
    return 0;
}