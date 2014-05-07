#include <stdio.h>
int alpha(void)
{
        return 20;
}

int i = alpha(); //dynamic intialization

int main()
{
        printf("i = %d",i);
            return i;
}
