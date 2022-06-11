#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <interrupt.h>



void main(){
    bool teste;
    char *test;

    test = &teste;

    printf("%d", teste);
    printf("%d", test);
    printf("%d", &test);
    printf("%d", teste);

}