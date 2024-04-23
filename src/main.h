#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*-----------STRUCTURES-----------*/
typedef struct rectangle {
    int length;
    int breadth;
} Rectangle;

typedef struct dynamicArray {
    int *A;
    int size;
    int length;
    bool array_full;
} dynamicArray;

typedef struct staticArray {
    int A[20];
    int size;
    int length;
    bool array_full;
} staticArray;

typedef struct Matrix{
    int A[10];
    int n;  //dimension
} Matrix;

typedef struct Element{
    int i;
    int j;
    int x;
} Element;

typedef struct SparseMatrix{
    int m;  //rows
    int n;  //columns
    int num;    //non-zero elements
    Element *E;
} SparseMatrix;

typedef struct Term{
    int coeff;
    int expo;
} Term;

typedef struct Polynomial{
    int n;
    Term *T;
} Polynomial;

/*-------FUNCTION-PROTOTYPES-------*/

/*--------functions-basic----------*/
int add (int, int);
void swap (int *, int *);
void modify_arr (int [], int, int);
int area_pba (Rectangle *);
int area_pbv (Rectangle);
/*-----------Recursion------------*/
void print_rec(int);
int print_rec_static_var(int);
void print_tree_rec(int);
int sum_n_nums(int);
int sum_n_nums_iterative(int);
int fact_n_nums(int);
int fact_n_nums_iterative(int);
int exponent(int, int);
int exponent_iterative(int, int);
int exponent_better(int, int);
double taylor_series(int, int);
int fib(int);
int c__(int, int);
void TOH(int, int, int, int);
/*-------------Arrays------------*/
dynamicArray Initialize_d(int);
void display_array_d(dynamicArray);
void display_array_s(staticArray);
void add_element_d(dynamicArray *, int);
void add_element_s(staticArray *, int);
void insert_element_d(dynamicArray *, int, int);
void insert_element_s(staticArray *, int, int);
int delete_element_d(dynamicArray *, int);
int delete_element_s(staticArray *, int);
int linear_search_d(dynamicArray *, int);
int binary_search(dynamicArray, int);
int get_array(dynamicArray, int);
void set_array(dynamicArray *, int, int);
int max_array(dynamicArray);
int max_array_s(staticArray);
void reverse_array(dynamicArray *);
void rotate_array(dynamicArray *, int, int);
bool check_sortedArray(dynamicArray);
void insert_sortedArray(dynamicArray *, int);
dynamicArray merge_sortedArray(dynamicArray, dynamicArray);
int missingSingle_array(staticArray);
void missingMultiple_array(staticArray);
void find_duplicate(staticArray);
void sum_k_array(staticArray, int);
/*------------Strings-------------*/
int string_length(char *);
void convert_uppercase(char *);
void convert_lowercase(char *);
bool validate_string(char *);
void reverse_string(char *);
bool check_palindromeString(char *);
void duplicate_string(char *);
int check_anagramstring(char *, char *);
void perm_string(char *, int);
/*-----------Matrices------------*/
void display_diagonalMatrix(Matrix);
void set_diagonalMatrix(Matrix *, int, int, int);
int get_diagonalMatrix(Matrix, int, int);
void set_lotriangMatrix(Matrix *, int, int, int);
int get_lotriangMatrix(Matrix, int, int);
void display_lotriangMatrix(Matrix);
void Initialize_sparseMatrix(SparseMatrix *);
void display_sparseMatrix(SparseMatrix);
SparseMatrix* add_sparseMatrix(SparseMatrix *, SparseMatrix *);
void Initialize_polynomial(Polynomial *);
int evaluate_polynomial(Polynomial, int);
Polynomial* add_polynomial(Polynomial *, Polynomial *);
void display_polynomial(Polynomial);
