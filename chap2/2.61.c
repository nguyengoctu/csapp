#include <stdio.h>
#include <assert.h>

/**
 * @brief  
 * @note   
 * @param  x: 
 * @retval return 1 if all bits are equal 1, 0 otherwise
 */
int isAllBitsEqual1(int x) {
    return !~x;
}

int isAllBitsEqual0(int x) {
    return !x;
}

int isLeastSignificantByteFF(int x) {
    return !~(x | ~0xff);
    
}

int isMostSignificantByte00(int x) {
    return !(x & (0xff << ((sizeof(int) - 1) << 3)));
}

int main() {
    assert(isAllBitsEqual1(0xffffffff) == 1);
    assert(isAllBitsEqual1(0xffffff0f) == 0);
    assert(isAllBitsEqual1(0x0) == 0);

    assert(isAllBitsEqual0(0x0) == 1);
    assert(isAllBitsEqual0(0x1) == 0);
    
    assert(isLeastSignificantByteFF(0x0f0000ff) == 1);
    assert(isLeastSignificantByteFF(0x0000f0f1) == 0);

    assert(isMostSignificantByte00(0x00123456) == 1);
    assert(isMostSignificantByte00(0x0f) == 1);
    assert(isMostSignificantByte00(0x01000000) == 0);
    return 0;
}