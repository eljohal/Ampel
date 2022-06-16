#include<stdio.h>
#include<time.h>

/* Testfile */

int main() {
	time_t nowe;
	nowe = time(0);
	printf("%s\n", ctime(&nowe)); //TEST TIME FUNCTION
	return 0;
}