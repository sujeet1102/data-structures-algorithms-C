#include "main.h"

void create_LL_array(int arr[], int n, Node **first){
    int i;
    Node *t, *last;
    (*first) = (Node*)malloc(sizeof(Node));
    (*first)->data = arr[0];
    (*first)->next = NULL;
    last = (*first);
    
    for(i = 1; i < n; i++){
        t = (Node*)malloc(sizeof(Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display_LL(Node *p){
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
}

void display_LL_recursive(Node *p){
    if(p == NULL) return;
    printf("%d ", p->data);
    display_LL_recursive(p->next);
}

int count_LL(Node *p){
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
}

int sum_elements_LL(Node *p){
    int sum = 0;
    while(p != NULL){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int max_element_LL(Node *p){
    int max = p->data;
    while(p != NULL){
        if(p->data > max) max = p->data;
        p = p->next;
    }
    return max;
}

int min_element_LL(Node *p){
    int min = p->data;
    while(p != NULL){
        if(p->data < min) min = p->data;
        p = p->next;
    }
    return min;
}

//linear search on linked list
Node* linear_search_LL(Node *p, int key){
    Node *q = NULL;
    while(p != NULL){
        if(p->data == key) {
            int t = q->data;
            q->data = p->data;
            p->data = t;
            return q;
        }
        q = p;
        p = p->next;
    }
    printf("NOT FOUND");
    return NULL;
}

int get_LL(Node *p, Node *o){
    while(p != NULL){
        if(p == o) return p->data;
        p = p->next;
    }
}

/*Three cases for inserting
1. head of the linked list
    new node declaration
    new node->data = x;
    new node->next = head;
    head = new node;
2. tail of the linked list
    new node declaration
    new node->data = x;
    new node->next = NULL;
    tail->next = new node;
    tail = new node;
3. middle of the linked list
    new node declaration
    new node->data = x;
    traverse to the Node
    new node->next = p->next;
    p->next = new node;
*/
void insert_LL(Node **first, int n, int x){
    
    if((n < 0) || (n > count_LL(*first))) return;
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = x;

    Node *p = *first;
    Node *q = NULL;
    if(n == 0){
        new_node->next = *first;
        *first = new_node;
    }
    else{
        for(int i = 0; (i < n-1) && (p != NULL); i++){
            p = p->next;
        }
        if(p){
            new_node->next = p->next;
            p->next = new_node;
        }
    }
}

void insert_sorted_LL(Node **first, int x){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = x;
    Node *p = *first;
    if(*first == NULL){
        *first = new_node;
    }
    else if((*first)->data > x){
        new_node->next = *first;
        *first = new_node;
    }
    else{
        while(p != NULL && (p->next)->data < x){
            p = p->next;
        }
        new_node->next = p->next;
        p->next = new_node;
    }
}

int delete_LL(Node **first, int n){
    
    if((n < 0) && (n >= count_LL(*first))) return 0;
    Node *p = *first;
    if(n == 0){
        *first = (*first)->next;
        int r = p->data;
        free(p);
        return r;
    }
    else{
        for(int i = 0; (i < n-1) && (p != NULL); i++){
            p = p->next;
        }
        if(p->next){
            Node *s = p->next;
            p->next = s->next;
            int r = s->data;
            free(s);
            return r;
        }
    }
}

bool check_sorted_LL(Node *p){
    while(p->next != NULL){
        if((p->data) > (p->next)->data) return false;
        p = p->next;
    }
    return true;
}

void delete_duplicate_LL(Node **first){
    Node *p = *first;
    Node *q = (*first)->next;
    while(q != NULL){
        if(p->data == q->data){
            if(p == *first) (*first)->next = q->next;
            else p->next = q->next;
            free(q);
            q = p->next;
        }
        else{
            p = q;
            q = q->next;
        }
    }
}

void reverse_elements_LL(Node *p){
    Node *q = p;
    int i = 0;
    int arr[10];
    while(q != NULL){
        arr[i] = q->data;
        i++;
        q = q->next;
    }
    q = p;
    i--;
    while(q != NULL){
        q->data = arr[i];
        i--;
        q = q->next;
    }
}

void reverse_LL(Node **first){
    Node *p = *first;
    Node *q = NULL;
    Node *r = NULL;
    while(p != NULL){
        if(r == *first) r->next = NULL;
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *first = q;
}

void reverse_recusrion_LL(Node **first, Node *q, Node *p){
    if(p != NULL){
        reverse_recusrion_LL(first, p, p->next);
        p->next = q;
    }
    else *first = q;
}

void merge_sorted_LL(Node **first, Node **second, Node **third){
    
    Node *last = NULL;
    
    if((*first)->data < (*second)->data){
        last = *third = *first;
        *first = (*first)->next;
        last->next = NULL;
    }
    else{
        last = *third = *second;
        *second = (*second)->next;
        last->next = NULL;
    }
    
    while((*first != NULL) && (*second != NULL)){
        if((*first)->data > (*second)->data){
            last->next = *second;
            last = *second;
            *second = (*second)->next;
            last->next = NULL;
        }
        else{
            last->next = *first;
            last = *first;
            *first = (*first)->next;
            last->next = NULL;
        }
    }
    if(*first != NULL){
        last->next = *first;
    }
    if(*second != NULL){
        last->next = *second;
    }
}

bool check_loop_LL(Node *p){
    Node *q = p->next;
    while((p != NULL) && (q != NULL)){
        if(q == p) return true;
        q = (q->next)->next;
        p = p->next;
    }
}

void display_circular_LL(Node *head){
    Node *p = head;
    do{
        printf("%d ", p->data);
        p = p->next;
    }while(p != head);
}

void create_circular_LL_array(int arr[], int n, Node **head){
    int i;
    Node *t, *last;
    (*head) = (Node*)malloc(sizeof(Node));
    (*head)->data = arr[0];
    (*head)->next = *head;
    last = (*head);
    
    for(i = 1; i < n; i++){
        t = (Node*)malloc(sizeof(Node));
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

int count_circular_LL(Node *head){
    int count = 0;
    Node *p = head;
    do{
        count++;
        p = p->next;
    }while(p != head);
    return count;
}

void insert_circular_LL(Node **first, int n, int x){
    
    if((n < 0) || (n > count_circular_LL(*first))) return;
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = x;

    Node *p = *first;
    Node *q = NULL;
    if(*first == NULL){
        new_node->next = new_node;
        *first = new_node;
    }
    if(n == 0){
        new_node->next = *first;
        q = (*first)->next;
        while(q->next != *first){
            q = q->next;
        }
        q->next = new_node;
        *first = new_node;
    }
    else{
        for(int i = 0; (i < n-1) && (p != NULL); i++){
            p = p->next;
        }
        if(p){
            new_node->next = p->next;
            p->next = new_node;
        }
    }
}
