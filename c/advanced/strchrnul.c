#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    if ('\0')
        printf("Yes True");
    else
        printf("False man");;
    char bla[20] = "adfadfadf";
    printf("%s\n",bla);
    char *ep = strchrnul(bla,'\n');
    char *fp = strchrnul(bla,'f');
//     printf("%d %c %s",ep - bla, ep , ep);
    printf("%s %c",fp,fp);
//     if(ep == NULL)
//         printf("Yes NULL");
    if (*ep == '\0')
        printf("No its \\0");
    return 0;
}
