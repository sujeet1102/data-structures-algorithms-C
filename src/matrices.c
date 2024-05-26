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

Polynomial* add_polynomial(Polynomial *p1, Polynomial *p2){
    int i,j,k;
    Polynomial *sum;
    sum=(Polynomial*)malloc(sizeof(Polynomial));
    sum->T=(Term *)malloc((p1->n+p2->n)*sizeof(Term));
    i=j=k=0;
    while(i<p1->n && j<p2->n)
    {
    if(p1->T[i].expo>p2->T[j].expo) sum->T[k++]=p1->T[i++];
    else if(p1->T[i].expo < p2->T[j].expo) sum->T[k++]=p2->T[j++];
    else
    {
    sum->T[k].expo=p1->T[i].expo;
    sum->T[k++].coeff=p1->T[i++].coeff+p2->T[j++].coeff;
    }
    }
    for(;i<p1->n;i++)sum->T[k++]=p1->T[i];
    for(;j<p2->n;j++)sum->T[k++]=p2->T[j];
    sum->n=k;
    return sum;
}

void display_polynomial(Polynomial p){
    printf("Polynomial: ");
    for(int i = 0; i < p.n - 1; i++){
        printf("%d.x^(%d) + ", p.T[i].coeff, p.T[i].expo);
    }
    printf("%d.x^(%d)", p.T[p.n-1].coeff, p.T[p.n-1].expo);
}

//sparse matrix and polynomial using linked list

sparseMatrix_Node** sparse_matrix_LL(int A[][6], int m, int n){
    
    sparseMatrix_Node *p = NULL, *q = NULL;
    sparseMatrix_Node **a_ptr = (sparseMatrix_Node **)malloc(m*sizeof(sparseMatrix_Node*));
    
    for(int i = 0; i < m; i++){
        a_ptr[i] = NULL;
        for(int j = 0; j < n; j++){
            if(A[i][j] != 0){
                p = (sparseMatrix_Node*)malloc(sizeof(sparseMatrix_Node));
                p->col = j;
                p->val = A[i][j];
                p->next = NULL;
                if(a_ptr[i] == NULL){
                    a_ptr[i] = p;
                    q = p;
                }else{
                    q->next = p;
                    q = q->next;
                }
            }
        }
        
        p->next = NULL;
    }
    return a_ptr;
}

void display_sparseMatrix_LL(sparseMatrix_Node **p, int m, int n){
    for(int i = 0; i < m; i++){
        sparseMatrix_Node *s = p[i];
        for(int j = 0; (j < n); j++){
            if(s){
                if(j == s->col){
                    printf("%d ", s->val);
                    s = s->next;
                }
                else printf("0 ");
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

//polynomial representation in linked list
void Initialize_polynomial_LL(Polynomial_Node **p){
    Polynomial_Node *s, *last = *p;
    printf("No. of non-zero elements\n");
    int a;
    scanf("%d", &a);
    printf("Enter term as coeff and expo\n");
    for(int i = 0; i < a; i++){
        s = (Polynomial_Node*)malloc(sizeof(Polynomial_Node));
        printf("Coeff Expo: ");
        scanf("%d %d", &(s->coeff), &(s->expo));
        if(*p == NULL){
            *p = last = s; 
        }
        else{
            last->next = s;
            last = last->next;
        }
    }
    
}

void display_polynomial_LL(Polynomial_Node *p){
    while(p->next){
        printf("%d.x^%d + ", p->coeff, p->expo);
        p = p->next;
    }
    printf("%d.x^%d", p->coeff, p->expo);
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
    
    // int A[5][6] = { {0,0,0,0,8,0},
    //                 {0,0,0,7,0,0},
    //                 {5,0,0,0,9,0},
    //                 {0,0,0,0,0,3},
    //                 {6,0,0,4,0,0}
    // };
    // sparseMatrix_Node **ans = sparse_matrix_LL(A, 5, 6);
    // display_sparseMatrix_LL(ans, 5, 6);
    // Polynomial_Node *p = NULL;
    // Initialize_polynomial_LL(&p);
    // display_polynomial_LL(p);

    printf("\n\n");
    return 0;
}
*/