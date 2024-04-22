#include "main.h"

//Display Diagonal Matrix
void display_diagonalMatrix(Matrix m){
	int i, j;
	for(i = 1; i <= m.n; i++){
		for(j = 1; j <= m.n; j++){
			if(i == j) printf("%d ", m.A[i-1]);
			else printf("0 ");
		}
		printf("\n");
	}
}

//Diagonal Matrix
void set_diagonalMatrix(Matrix *m_ptr, int i, int j, int x){
	if(i == j){
		m_ptr->A[i-1] = x;
	}
}

int get_diagonalMatrix(Matrix m, int i, int j){
	if(i == j){
		return m.A[i-1];
	}
	return 0;
}

//Lower Triangular Matrix - Row major method
//n dimensional matrix will have n(n+1)/2 non zero elements
void set_lotriangMatrix(Matrix *m_ptr, int i, int j, int x){
	if(i >= j){ 
		m_ptr->A[(i*(i-1)/2)+(j-1)] = x;
	}
}

int get_lotriangMatrix(Matrix m, int i, int j){
	if(i >= j){
		return m.A[(i*(i-1)/2)+(j-1)];
	}
	return 0;
}

//Display Lower Triangular Matrix
void display_lotriangMatrix(Matrix m){
	int i, j;
	for(i = 1; i <= m.n; i++){
		for(j = 1; j <= m.n; j++){
			if(i >= j) printf("%d ", m.A[(i*(i-1)/2)+(j-1)]);
			else printf("0 ");
		}
		printf("\n");
	}
}

//Sparse Matrices

//main function for basic matrices
/*
int main(void)
{
	//Create functions and structures for each of the tasks 
	//in respective header files and call them here
	Matrix m0;
    m0.n = 4;
    set_diagonalMatrix(&m0, 1, 1, 7);
    set_diagonalMatrix(&m0, 2, 2, 1);
    set_diagonalMatrix(&m0, 3, 3, 9);
    set_diagonalMatrix(&m0, 4, 4, 7);

    display_diagonalMatrix(m0);
    printf("\n");

    Matrix m1;
    m1.n = 4;
    set_lotriangMatrix(&m1, 1, 1, 7);
    set_lotriangMatrix(&m1, 2, 1, 1);
    set_lotriangMatrix(&m1, 2, 2, 9);
    set_lotriangMatrix(&m1, 3, 1, 7);
    set_lotriangMatrix(&m1, 3, 2, 1);
    set_lotriangMatrix(&m1, 3, 3, 9);
    set_lotriangMatrix(&m1, 4, 1, 4);
    set_lotriangMatrix(&m1, 4, 2, 5);
    set_lotriangMatrix(&m1, 4, 3, 6);
    set_lotriangMatrix(&m1, 4, 4, 7);

    display_lotriangMatrix(m1);

	printf("\n\n");
	return 0;
}
*/