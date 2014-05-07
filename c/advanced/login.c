#include <stdio.h>
//const int SIZE = 15;
#define SIZE 15
int main() {
    char username[SIZE] = "chaudhary";
    char password[SIZE] = "letmein" ;
    char input[SIZE];
    char in;
    int i;
    for (i=0; in = getch() && in != '\n'; i++) {
        input[i]=in;
    }
    printf("You entered: %s\n",input);
}


