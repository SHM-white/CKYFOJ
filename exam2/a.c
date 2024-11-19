#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned short CRC = 0xFFFF;
    int n;
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        unsigned short data;
        scanf("%hx", &data);
        CRC = (CRC) ^ data;
        for (int j = 0; j < 8; j++)
        {
            if (CRC & 0b01)
            {
                CRC >>= 1;
                CRC ^= 0xA001;
            }
            else
            {
                CRC >>= 1;
            }
        }
    }
    printf("%hx %hx", (CRC & 0xFF00) >> 8, (CRC & 0x00FF));
}