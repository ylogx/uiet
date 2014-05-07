#include <stdio.h>
#include <sys/types.h>
int main(){
    union alpha {
        int entry;
        struct inner_s {
            int a:1, b:2, c:3, d:10, e:12;
        } inner_field_s;
    };
    printf("sizeof alpha: %d\n\n",sizeof(union alpha));
    //union alpha instance;
    int input,value;
    //scanf("%d",&input);
    /*
    switch(input) {
        case 1:
            scanf("%d",&instance.entry);
            break;
        case 2:
            printf("Enter 5 values: ");
//            scanf("%d",&instance.inner_field_s.a);
            break;
        default:
            printf("error");
            break;
    }
    */
    union beta {
        int entry;
        struct inner_s inner_field_s;
    };
    printf("sizeof beta : %d\n\n",sizeof(union beta ));
    union beta  instance;
    scanf("%d",&input);
    instance.entry = input;
    printf("entry: %d\na:%d\tb:%d\tc:%d\td:%d\te:%d\t",instance.entry,
                                            instance.inner_field_s.a,
                                            instance.inner_field_s.b,
                                            instance.inner_field_s.c,
                                            instance.inner_field_s.d,
                                            instance.inner_field_s.e);
    printf( "size of instance: %d\n",sizeof(instance) );
    //printf( "size of: \n ssize_t: %d\n size_t: %d\n",sizeof(ssize_t),sizeof(size_t) );
    //printf("%d=ulong\t %d=uint\n",sizeof(ulong),sizeof(uint));
    return 0;
}
/*        struct inner_s {
            int a:1;
            int b:2;
            int c:3;
            int d:10;
            int e:20;
            int f:12;
        } inner_field_s;
 */
