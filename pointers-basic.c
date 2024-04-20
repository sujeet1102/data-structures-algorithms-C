#include "main.h"

Rectangle R1 = {4, 6};

int a; 
double b; 
long long int c;
int *p = &a;
double *q = &b;
long long int *r = &c;
Rectangle *ptr = &R1;

/*
int main(void)
{
	//Create functions for each of the tasks and call them here
	printf("%lu\n", sizeof(p));
	printf("%lu\n", sizeof(q));
	printf("%lu\n", sizeof(r));
	printf("%lu\n", sizeof(ptr));
	
	printf("length: %d\n", ptr->length);
	ptr->length = 7;
	printf("breadth: %d\n", ptr->breadth);
	printf("New length: %d\n", ptr->length);
	
	Rectangle *p;   //Dynamic allocation
	p = (Rectangle*)malloc(sizeof(Rectangle));
	
	p->length = 7;
	p->breadth = 10;
	printf("length: %d\n", p->length);
	printf("breadth: %d\n", p->breadth);
	  
	return 0;
}
*/