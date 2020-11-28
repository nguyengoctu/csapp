#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    int i;
    for (int i = 0; i < len; i++)
    {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void show_double(double x)
{
    show_bytes((byte_pointer)&x, sizeof(double));
}

void show_short(short x)
{
    show_bytes((byte_pointer)&x, sizeof(short));
}

void show_long(long x)
{
    show_bytes((byte_pointer)&x, sizeof(long));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)val;
    double dval = (double)val;
    short sval = (short)val;
    long lval = (long)val;
    int *pval = &val;
    show_int(ival);
    show_float(fval);
    show_double(dval);
    show_short(sval);
    show_long(lval);
    show_pointer(pval);
}

int is_little_endian()
{
    short val = 1;
    byte_pointer p = &val;
    if (p[0] == 0x0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    if (is_little_endian())
    {
        printf("This is a little endian system\n");
    }
    else
    {
        printf("This is a little endian system\n");
    }
    return 0;
}