#include <stdio.h>
#include <string.h>

int main(){
    char s[20]="blabooboo";
    char *op= strchr(s, 'o');
    printf("%s, %s, %ld\n",s,op,op-s);
    char *o= strchr(s, '\n');
    printf("%s   %c",o,o);
    if (o){
        printf("Shit");
    }else
        printf("Crap");
    return 0;
}
