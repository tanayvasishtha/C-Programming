#include <stdio.h>
int main()
{
    int x = 7;
    char ch = 'z';
    printf("%d\t%p\n", x, &x);
    printf("\n%ld\n%ld\n%ld",sizeof(x),sizeof(int),sizeof(char));
        return 0;
}