#include "main.h"

void print_rec(int n)
{
    int n1 = n;
    if (n > 0)
    {
        printf("%d ", n);
        print_rec(n - 1);
        printf("%d ", n);
    }
}

int print_rec_static_var(int n) //see static and global variables behave
{
    static int v = 0;
    int n1 = n;
    
    if (n > 0)
    {
        v++;
        return print_rec_static_var(n - 1) + v;
    }
    return 0;
}

// Tree Recursion
void print_tree_rec(int n)
{
    if (n > 0)
    {
        // printf("%d ", n);
        int n1 = n;
        print_tree_rec(n-1);
        print_tree_rec(n-1);
    }
}

// sum of n numbers
int sum_n_nums(int n)
{
    if (n == 0) return 0;
    return sum_n_nums (n-1) + n;
}
int sum_n_nums_iterative(int n)
{
    int sum = 0;
    while(n > 0){
        sum += n;
        n--;
    }
    return sum;
}

//factorial of a numbers
int fact_n_nums(int n)
{
    if (n == 0) return 1;
    return (n)*(fact_n_nums(n-1));
}

//factorial using iteration
int fact_n_nums_iterative(int n)
{
    int fact = 1;
    while(n > 0){
        fact *= n;
        n--;
    }
    return fact;
}

//exponential using Recursion m^n
int exponent(int m, int n)
{
    if(n == 0) return 1;
    return (exponent(m, n-1))*(m);
}

//exponent using iteration
int exponent_iterative(int m, int n)
{
    int exponent = 1;
    while (n > 0)
    {
        exponent *= m;
        n--;
    }
    return exponent;
}

//faster exponent
int exponent_better(int m, int n)
{
    if(n == 0) return 1;
    if (n%2 == 0) return exponent_better(m*m, n/2);
    else return (m)*(exponent_better(m*m, (n-1)/2));
}

//Taylor series for (e)^x
double taylor_series(int x, int n)
{
    static double p=1, f=1;
    double r;
    if (n == 0) return 1;
    else {
        r = taylor_series(x, n-1);
        p = p * x;
        f = f * n;
        return r+p/f;
    }
}
int F[10];

//fibonacci series
int fib(int n)
{
    if (n <= 1) {
        F[n] = n;
        return n;
    }
    else {
        if(F[n-1]==-1) F[n-1] = fib(n-1);
        if(F[n-2]==-1) F[n-2] = fib(n-2);
        return F[n-1]+F[n-2];
    }
}

int c__(int n, int r)
{
    if (r==0 || n==r) return 1;
    return c__(n-1, r-1)+c__(n-1, r);
}

void TOH(int num_disks, int A, int B, int C)
{
    if (num_disks > 0){
        TOH(num_disks-1, A, C, B);
        printf("(%d, %d) ", A, C);
        TOH(num_disks-1, B, A, C);
    }
}

//main function
/*
int main(void)
{
	//Create functions and structures for each of the tasks 
	//in respective header files and call them here
	
	extern int F[10];
	
    printf("%d\n", sum_n_nums(10));
    printf("%d\n", sum_n_nums_iterative(10));
    printf("%d\n", fact_n_nums(5));
    printf("%d\n", fact_n_nums_iterative(5));
    printf("%d\n", exponent(4, 5));
    printf("%d\n", exponent_better(4, 5));
    printf("%f\n", taylor_series(9, 100));
    for (int i=0; i<10; i++) F[i] = -1;
    printf("%d\n", fib(5));
    printf("%d\n", c__(4, 2));
    TOH(3, 1, 2, 3);
	
	return 0;
}
*/
