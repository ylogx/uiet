#include<stdio.h>
//typedef is frequently used to improve code portablity
#if defined( ALPHA ) && defined ( DIGITAL_UNIX )
typedef int BYTE4_t;
#else
typedef long BYTE4_t;
#endif
void main()
{
//For the record, a variable or field that needed to be exactly four bytes will then be declared like this:
BYTE4_t field_name;

}
