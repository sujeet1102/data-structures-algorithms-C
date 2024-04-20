#include "main.h"

// Arrays ADT (Abstract Data Type)
dynamicArray Initialize_d(int size){
    dynamicArray arr;
    arr.size = size;
    arr.length = 0;
    arr.A = (int *)malloc((arr.size)*sizeof(int));
    return arr;
}

//Display array
void display_array_d(dynamicArray arr){
    int i;
    printf("\nElements are:\n");
    for(i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
}

void display_array_s(staticArray arr){
    int i;
    printf("\nElements are:\n");
    for(i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
}

//Add/Append element in array
void add_element_d(dynamicArray *arr_ptr, int x){
    if(!(arr_ptr->array_full = (arr_ptr->size == arr_ptr->length))){
        arr_ptr->A[arr_ptr->length] = x;
        arr_ptr->length++;
    }
    else printf("\nERROR: ARRAY_FULL\n");
}

void add_element_s(staticArray *arr_ptr, int x){
    if(!(arr_ptr->array_full = (arr_ptr->size == arr_ptr->length))){
        arr_ptr->A[arr_ptr->length] = x;
        arr_ptr->length++;
    }
    else printf("\nERROR: ARRAY_FULL\n");
}

//Insert element in array
void insert_element_d(dynamicArray *arr_ptr, int index, int x){
    if(!(arr_ptr->array_full = (arr_ptr->size == arr_ptr->length))){
        for (int i = arr_ptr->length; i > index; i--){
            arr_ptr->A[i] = arr_ptr->A[i-1];
        }
        arr_ptr->A[index] = x;
        arr_ptr->length++;
    }
    else printf("\nERROR: ARRAY_FULL\n");
}

void insert_element_s(staticArray *arr_ptr, int index, int x){
    if(!(arr_ptr->array_full = (arr_ptr->size == arr_ptr->length))){
        for (int i = arr_ptr->length; i > index; i--){
            arr_ptr->A[i] = arr_ptr->A[i-1];
        }
        arr_ptr->A[index] = x;
        arr_ptr->length++;
    }
    else printf("\nERROR: ARRAY_FULL\n");
}

//Delete element in array
int delete_element_d(dynamicArray *arr_ptr, int index){
    if(index >= 0 && index < arr_ptr->length){
        int x = arr_ptr->A[index];
        for (int i = index; i < arr_ptr->length - 1; i++){
            arr_ptr->A[i] = arr_ptr->A[i+1];
        }
        arr_ptr->length--;
        return x;
    }
    else printf("\nERROR: INDEX OUT OF BOUND\n");
    return -1;
}

int delete_element_s(staticArray *arr_ptr, int index){
    if(index >= 0 && index < arr_ptr->length){
        int x = arr_ptr->A[index];
        for (int i = index; i < arr_ptr->length - 1; i++){
            arr_ptr->A[i] = arr_ptr->A[i+1];
        }
        arr_ptr->length--;
        return x;
    }
    else printf("\nERROR: INDEX OUT OF BOUND\n");
    return -1;
}

//Search in array

//--linear search with improvement (transposition)
int linear_search_d(dynamicArray *arr_ptr, int key){
    int i;
    for (int i = 0; i < arr_ptr->size; i++){
        if(key == arr_ptr->A[i]){
            if(i != 0){
                swap(&(arr_ptr->A[i]), &(arr_ptr->A[i-1]));
                return i-1;
            }
            return i;
        }
    }
    return -1;
}
//--binary search - array must be sorted
int binary_search(dynamicArray arr, int key){
    int low = 0, high = arr.length-1;
    int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(key == arr.A[mid]) return mid;
        else if(key < arr.A[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

//Get element in array
int get_array(dynamicArray arr, int index){
    if (index >= 0 && index < arr.length){
        return arr.A[index];
    }
    else printf("\nERROR: INDEX OUT OF BOUND\n");
    return -1;
}

//Set element in array
void set_array(dynamicArray *arr_ptr, int index, int x){
    if (index >= 0 && index < arr_ptr->length){
        arr_ptr->A[index] = x;
    }
    else printf("\nERROR: INDEX OUT OF BOUND\n");
}

//Max element in array
int max_array(dynamicArray arr){
    int max = arr.A[0];
    for(int i = 1; i < arr.length; i++){
        if(arr.A[i] > max) max = arr.A[i];
    }
    return max;
}

int max_array_s(staticArray arr){
    int max = arr.A[0];
    for(int i = 1; i < arr.length; i++){
        if(arr.A[i] > max) max = arr.A[i];
    }
    return max;
}

//Reverse an array
void reverse_array(dynamicArray *arr_ptr){
    int i = 0, j = arr_ptr->length - 1, temp;
    while(i < j){
        temp = arr_ptr->A[i];
        arr_ptr->A[i] = arr_ptr->A[j];
        arr_ptr->A[j] = temp;
        i++;
        j--;
    }
}

//Shift/Rotate an array
void rotate_array(dynamicArray *arr_ptr, int d, int z){
    int temp;
    if(d > 0){
        while(z){
            temp = arr_ptr->A[arr_ptr->length-1];
            for(int i = arr_ptr->length-1; i > 0; i--){
                arr_ptr->A[i] = arr_ptr->A[i-1];
            }
            arr_ptr->A[0] = temp;
            z--;
        }
    }
    else{
        while(z){
            temp = arr_ptr->A[0];
            for(int i = 0; i < arr_ptr->length-1; i++){
                arr_ptr->A[i] = arr_ptr->A[i+1];
            }
            arr_ptr->A[arr_ptr->length-1] = temp;
            z--;
        }
    }
}

//Check sorted array & insert into sorted position
bool check_sortedArray(dynamicArray arr){
    for(int i = 0; i < arr.length-1; i++){
        if(!(arr.A[i] < arr.A[i+1])) return false;
    }
    return true;
}

void insert_sortedArray(dynamicArray *arr_ptr, int x){
    if(!(arr_ptr->array_full = (arr_ptr->size == arr_ptr->length))){
        int i = arr_ptr->length-1;
        while(arr_ptr->A[i] > x){
            arr_ptr->A[i+1] = arr_ptr->A[i];
            i--;
        }
        arr_ptr->A[i+1] = x;
        arr_ptr->length++;
    }
    else printf("\nERROR: ARRAY_FULL\n");
}

//Merging of arrays
dynamicArray merge_sortedArray(dynamicArray P, dynamicArray Q){
    dynamicArray arr = Initialize_d(P.size + Q.size);
    int i = 0, j = 0, k = 0;
    while((i < P.length) && (j < Q.length)){
        if(P.A[i] < Q.A[j]){
            arr.A[k] = P.A[i];
            i++;
        }
        else {
            arr.A[k] = Q.A[j];
            j++;
        }
        k++;
        arr.length++;
    }
    for(; i < P.length; i++){
        arr.A[k] = P.A[i];
        k++;
        arr.length++;
    }
    for(; j < Q.length; j++){
        arr.A[k] = Q.A[j];
        k++;
        arr.length++;
    }
    return arr;

}

//----------Student-Challenges---------

// 1. Find Single Missing element in array
int missingSingle_array(staticArray arr){
    int sum = 0, ideal_sum = 0;
    int max = max_array_s(arr);
    for(int i = 0; i < arr.size; i++){
        sum += arr.A[i];
    }
    ideal_sum = (max*(max+1))/2;
    return ideal_sum - sum;
}

// 2. Find Multiple Missing element in array
//sorted array starting from any element
void missingMultiple_array(staticArray arr){
    int diff = arr.A[0] - 0;
    for(int i = 0; i < arr.size; i++){
        if(arr.A[i]-i != diff){
            while(diff < arr.A[i]-i){
                printf("%d ",i+diff);
                diff++;
            }
        }
    }
}

// 3. Find duplicates in a sorted/unsorted array using hashing
void find_duplicate(staticArray arr){
    int H[max_array_s(arr)];
    for(int i = 1; i <= max_array_s(arr); i++){
        H[i] = 0;
    }
    for(int i = 0; i < arr.size; i++){
        H[arr.A[i]]++;
    }
    for(int i = 1; i <= max_array_s(arr); i++){
        if(H[i] > 1) printf("%d ", i);
    }
}

// 4. Find pair of elements with sum k
void sum_k_array(staticArray arr, int k){
    int H[max_array_s(arr)];
    for(int i = 1; i <= max_array_s(arr); i++){
        H[i] = 0;
    }
    for(int i = 0; i < arr.size; i++){
        if(H[k-arr.A[i]] != 0){
            printf("%d + %d = %d\n", arr.A[i], k-arr.A[i], k);
        }
        H[arr.A[i]]++;
    }
}

//main for basic arrays
/*
int main(void)
{
	//Create functions and structures for each of the tasks 
	//in respective header files and call them here
    
	//Dynamic array
	int *p = (int *)malloc(5*sizeof(int));
	for(int i = 0; i < 5; i++) *(p + i) = i;
	for(int i = 0; i < 5; i++) printf("%d ", *(p + i));
	printf("\n");
	printf("\n");
	free(p);
	
	//Dynamic 2D array - Only ptr is in stack rest are all in heap
	int **ptr = (int**)malloc(3*sizeof(int*));
	*(ptr) = (int*)malloc(4*sizeof(int));
	*(ptr+1) = (int*)malloc(4*sizeof(int));
	*(ptr+2) = (int*)malloc(4*sizeof(int));
	
	for(int i = 0; i < 3; i++){
	    for(int j = 0; j < 4; j++){
	        ptr[i][j] = rand() % (10);
	        printf("%d ",ptr[i][j]);
	    }
	    printf("\n");
	}
	
	return 0;
}
*/

// main function for array ADT concepts
/*
int main(void)
{
    //Create functions and structures for each of the tasks 
    //in respective header files and call them here
    
//  dynamicArray arr;
//  printf("Enter Size: ");
//  scanf("%d", &(arr.size));
//  arr.A = (int *)malloc((arr.size)*sizeof(int));
//  arr.length = 0;
    
//  int n, i;
//  printf("\nEnter no. of elements: ");
//  scanf("%d", &(n));
    
//  printf("\nEnter all elements:\n");
//  for(i = 0; i < n; i++){
//      scanf("%d", &(arr.A[i]));
//  }
//  arr.length = n;
    
//  display_array_d(arr);
    
//  staticArray app = {{2,3,4,5,6}, 20, 5, 0};
//  display_array_s(app);
    
//  add_element_s(&(app), 69);
//  display_array_s(app);
//  insert_element_s(&(app), 3, 666);
//  display_array_s(app);
//  int popped_element = delete_element_s(&(app), 4);
//  printf("\npopped_element: %d", popped_element);
//  display_array_s(app);
    
    // dynamicArray arr = Initialize_d(11);
    
    // for(int i = 0; i < arr.size; i++){
    //     arr.A[i] = (i * 3) + 17;
    //     arr.length++;
    // }
    // display_array_d(arr);
    // printf("\n\n%d", linear_search_d(&(arr), 41));
    // display_array_d(arr);
    // printf("\n\n%d", binary_search(arr, 41));
    // printf("\n%d", get_array(arr, 2));
    // printf("\n%d", max_array(arr));
    // reverse_array(&(arr));
    // display_array_d(arr);
    // rotate_array(&(arr), 1, 3);
    // display_array_d(arr);
    // printf("\n%d\n", check_sortedArray(arr));
    // rotate_array(&(arr), -1, 3);
    // display_array_d(arr);
    // printf("\n%d\n", check_sortedArray(arr));
    // insert_sortedArray(&(arr), 25);
    // dynamicArray P = Initialize_d(8);
    // for(int i = 0; i < P.size; i++){
    //     P.A[i] = (i * 3) + 17;
    //     P.length++;
    // }
    // dynamicArray Q = Initialize_d(4);
    // for(int i = 0; i < Q.size; i++){
    //     Q.A[i] = (i * 17) + 3;
    //     Q.length++;
    // }
    // display_array_d(P);
    // display_array_d(Q);
    // dynamicArray Z = merge_sortedArray(P, Q);
    // display_array_d(Z);

    printf("\n\n");
    return 0;
}
*/

//student challenges
/*
int main(void)
{
    //Create functions and structures for each of the tasks 
    //in respective header files and call them here
    
    staticArray arr1 = {{1,2,3,4,5,7,8,9}, 20, 8};
    printf("%d\n", missingSingle_array(arr1));
    staticArray arr2 = {{4,5,7,8,10,11,12,14,15}, 20, 9};
    missingMultiple_array(arr2);
    printf("\n");
    staticArray arr3 = {{1,2,3,3,5,7,7,7}, 20, 8};
    find_duplicate(arr3);
    printf("\n");
    staticArray arr4 = {{1,6,3,9,5,7,2,4}, 20, 8};
    sum_k_array(arr4, 10);

    printf("\n\n");
    return 0;
}
*/