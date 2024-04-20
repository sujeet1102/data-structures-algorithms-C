#include "main.h"

int add (int a, int b){
    return (a + b);
}

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int arr[5] = {1,2,3,4,5};

void modify_arr (int arr_p[], int index, int value) //or use int *arr_p (this will be general) while arr_p[] is array specific
{
    arr_p[index] = value;
}

int area_pba (Rectangle *p)
{
    return (p->length) * (p->breadth);
}

int area_pbv (Rectangle p)
{
    p.length++;
    return (p.length) * (p.breadth);
}

Rectangle R2 = {13, 3};

/*
int main(void)
{
	//Create functions for each of the tasks and call them here
	printf("basic: %d\n", add(3, 4));    //basic function - pass by value
	
	int x = 5;
	int y = 700;
	
	swap(&x, &y);   // pass by address
	
	printf("swapped: x: %d and y: %d\n", x, y);
	
	printf("%d\n", arr[2]);
	modify_arr(arr, 2, 666);
	printf("%d\n", arr[2]);
	
	printf("area: %d\n", area_pba(&R2));
	printf("area: %d\n", area_pbv(R2));
	  
	return 0;
}
*/