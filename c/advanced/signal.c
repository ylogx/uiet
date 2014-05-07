/* A C program that does not terminate when Ctrl+C is pressed */
#include<stdio.h>
#include <signal.h>

void signalHandler( int signum ){
    //reset signal handler to catch SIGINT next time
    signal(SIGINT,signalHandler);
    printf(" \n Mr. Shubham Chaudhary Ctrl^C can't be used \n");
    fflush(stdout);
}

int main(){
    /* Set the SIGINT (Ctrl-C) signal handler to sigintHandler
     *        Refer http://en.cppreference.com/w/c/program/signal */
    signal( SIGINT , signalHandler );
    //infinite loop
    while(1){
    }
    return 0;
}

