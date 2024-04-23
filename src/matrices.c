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
void Initialize_sparseMatrix(SparseMatrix *s){
    printf("Enter Dimensions:\n");
    scanf("%d %d", &(s->m), &(s->n));
    printf("\nEnter no. of non-zero elements:\n");
    scanf("%d", &(s->num));
    s->E = (Element *)malloc((s->num)*sizeof(Element));
    int k;
    printf("\nEnter all elements in format (i, j, x):\n");
    for(k = 0; k < s->num; k++){
        scanf("%d %d %d", &(s->E[k].i), &(s->E[k].j), &(s->E[k].x));
    }
}

void display_sparseMatrix(SparseMatrix s){
    int i, j, k = 0;
    printf("Sparse Matrix is:\n");
    for(i = 0; i < s.m; i++){
        for(j = 0; j < s.n; j++){
            if((i == s.E[k].i) && (j == s.E[k].j)) printf("%d ", s.E[k++].x);
            else printf("0 ");
        }
        printf("\n");
    }
}

SparseMatrix* add_sparseMatrix(SparseMatrix *a, SparseMatrix *b){
    SparseMatrix *sum;
    int i, j, k;
    i = j = k = 0;
    
    if((a->n != b->n) && (a->m != b->m)) return NULL;
    
    sum = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    sum->num = a->num + b->num;
    sum->n = a->n; sum->m = a->m;
    sum->E = (Element*)malloc(sizeof(Element)*(sum->num));
    
    while((i < a->num) && (j < b->num)){
        if(a->E[i].i < b->E[j].i) sum->E[k++] = a->E[i++];
        else if(b->E[j].i < a->E[i].i) sum->E[k++] = b->E[j++];
        else{
            if(a->E[i].j < b->E[j].j) sum->E[k++] = a->E[i++];
            else if(b->E[j].j < a->E[i].j) sum->E[k++] = b->E[j++];
            else{
                sum->E[k] = a->E[i];
                sum->E[k++].x = a->E[i++].x + b->E[j++].x;
            }
        }
    }
    for(; i < a->num; i++) sum->E[k++] = a->E[i];
    for(; j < b->num; j++) sum->E[k++] = b->E[j];
    return sum;
}

//Polynomial Representation
void Initialize_polynomial(Polynomial *p){
    printf("No. of non-zero elements\n");
    scanf("%d", &(p->n));
    p->T = (Term*)malloc((p->n)*sizeof(Term));
    printf("Enter coefficient & exponent:\n");
    for(int i = 0; i < p->n; i++){
        printf("Term no %d: ", i + 1);
        scanf("%d %d", &(p->T[i].coeff), &(p->T[i].expo));
    }
}

int evaluate_polynomial(Polynomial p, int x){
    int poly_value = 0;
    for(int i = 0; i < p.n; i++){
        poly_value += exponent_iterative(x, p.T[i].expo) * (p.T[i].coeff);
    }
    return poly_value;
}

Polynomial* add_polynomial(Polynomial *a, Polynomial *b){
    Polynomial *s;
    s = (Polynomial*)malloc(sizeof(Polynomial));
    s->T = (Term*)malloc((a->n + b->n)*sizeof(Term));
    int i = 0, j = 0, k = 0;
    while((i < a->n) && (j < b->n)){
        if(a->T[i].expo > b->T[i].expo) s->T[k++] = a->T[i++];
        else if(a->T[i].expo < b->T[j].expo) s->T[k++] = b->T[j++];
        else{
            s->T[k].expo = a->T[i].expo;
            s->T[k++].coeff = a->T[i++].coeff + b->T[j++].coeff;
        }
    }
    for(; i < a->n; i++) s->T[k++] = a->T[i];
    for(; j < b->n; j++) s->T[k++] = b->T[j];
    s->n = k;
    return s;
}

void display_polynomial(Polynomial p){
    printf("Polynomial: ");
    for(int i = 0; i < p.n - 1; i++){
        printf("%d.x^(%d) + ", p.T[i].coeff, p.T[i].expo);
    }
    printf("%d.x^(%d)", p.T[p.n-1].coeff, p.T[p.n-1].expo);
}

//main function for matrices
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
    
    SparseMatrix m3, m4, *sum;
	Initialize_sparseMatrix(&m3);
	printf("\n");
	printf("First Matrix: \n");
	display_sparseMatrix(m3);
	printf("\n");
	Initialize_sparseMatrix(&m4);
	printf("\n");
	printf("Second Matrix: \n");
	display_sparseMatrix(m4);
	printf("\n");
	sum = add_sparseMatrix(&m3, &m4);
	printf("Summation Matrix: \n");
	display_sparseMatrix(*sum);

	Polynomial p1;
    Initialize_polynomial(&p1);
    display_polynomial(p1);
    printf("\n");
    printf("For polynomial x = 3 value is: %d", evaluate_polynomial(p1, 3));
    
    Polynomial p2, p3, *p4;
    Initialize_polynomial(&p2);
    display_polynomial(p2);
    printf("\n");
    Initialize_polynomial(&p3);
    display_polynomial(p3);
    printf("\n");
    
    p4 = add_polynomial(&p2, &p3);
    display_polynomial(*p4);

	printf("\n\n");
	return 0;
}
*/