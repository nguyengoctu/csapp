#include <stdio.h>
#include <assert.h>
#include <limits.h>

/**
 * @brief  logical right-shift using arithmetic right-shift
 * @note   
 * @param  x: 
 * @param  k: 
 * @retval 
 */
unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    return xsra & ((int)INT_MAX >> (k - 1));
}

/**
 * @brief  arithmetic right-shift using logical right-shift
 * @note   
 * @param  x: 
 * @param  k: 
 * @retval 
 */
int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;
    return ((-((unsigned)x >> (__INT_WIDTH__ - 1))) << (__INT_WIDTH__ - k)) | xsrl;
}

int main()
{
    assert(srl(-1, __INT_WIDTH__ - 1) == 1);
    assert(srl(-__INT_MAX__ - 1, __INT_WIDTH__ - 1) == 1);

    assert(sra(-1, __INT_WIDTH__ - 1) == -1);
    assert(sra(__INT_MAX__, __INT_WIDTH__ - 1) == 0);
    return 0;
}