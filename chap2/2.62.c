#include <stdio.h>
#include <assert.h>

int int_shifts_are_arithmetic() {
    int x = -1;
    return (x >> (sizeof(int) * 8) & x);
}

int main() {
    assert(int_shifts_are_arithmetic());
    return 0;
}