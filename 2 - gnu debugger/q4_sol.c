#include <stdio.h>

int main()
{
    unsigned short value = 0x3412; //2 Bytes value

    unsigned char a, b; //to store byte by byte value

    a = (value & 0xFF);        //extract first byte
    b = ((value >> 8) & 0xFF); //extract second byte

    printf("a= %02X\n", a);
    printf("b= %02X\n", b);

    if (a == 0x34 && b == 0x12)
        printf("Big endian\n");
    else if (a == 0x12 && b == 0x34)
        printf("Little endian\n");

    return 0;
}