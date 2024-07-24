#include "ft_printf_bonus.h"

int main(int argc, char const *argv[])
{
    char p = 0;
    int *pt;
    unsigned int i = 10;
    
    int j = printf("%0100.40p", pt);
    printf("%i", j);
    return 0;
}   