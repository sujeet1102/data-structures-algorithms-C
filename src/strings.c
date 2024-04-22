#include "main.h"

int string_length(char *s){
	int i;
	for(i = 0; s[i] != '\0'; i++);
	return i;
}

void convert_lowercase(char *s){
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] >= 65 && s[i] <= 90) s[i] = s[i] + 32;
	}
}

void convert_uppercase(char *s){
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] >= 97 && s[i] <= 122) s[i] = s[i] - 32;
	}
}

bool validate_string(char *s){	//Alphanumerical only
	for(int i = 0; s[i] != '\0'; i++){
		if(!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] >= 48 && s[i] <= 57)) return false;
	}
	return true;
}

void reverse_string(char *s){
	int i, j;
	char t;
	for(j = 0; s[j] != '\0'; j++);
	j = j - 1;
	for(i = 0; i < j; i++, j--){
		t = s[j];
		s[j] = s[i];
		s[i] = t;
	}
}

bool check_palindromeString(char *s){
	int i, j;
	for(j = 0; s[j] != '\0'; j++);
	j = j - 1;
	for(i = 0; i < j; i++, j--){
		if(s[i] != s[j]) return false;
	}
	return true;
}

void duplicate_string(char *s){		//for lowercase only
	int H = 0, x = 1;
	for(int i = 0; s[i] != '\0'; i++){
		x = 1;
		x = x << s[i] - 97;
		if(x & H) printf("%c is duplicate\n", s[i]);
		else H = H | x;
	}
}

int check_anagramstring(char *s, char *t){	//assume both strings of equal length and lowercase
	int H = 0;
	for(int i = 0; s[i] != '\0'; i++){
		H |= (1 << (s[i] - 97));
	}
	for(int i = 0; t[i] != '\0'; i++){
		H &= ~(1 << (t[i] - 97));
	}
	if(H == 0){
		printf("anagram\n");
		return 1;
	}
	else return 0;
}

void perm_string(char *s, int k){
	static int A[10] = {0};
	static char Res[10];
	int i;

	if(s[k] == '\0'){
		Res[k] = s[k];
		printf("%s\n", Res);
	}
	else{
		for(i = 0; s[i] != '\0'; i++){
			if(A[i] == 0){
				Res[k] = s[i];
				A[i] = 1;
				perm_string(s, k+1);
				A[i] = 0;
			}
		}
	}

}

//main function for strings
/*
int main(void)
{
	//Create functions and structures for each of the tasks 
	//in respective header files and call them here
    
	char name[10] = "Sujeet";
	char one[10] = "decimal";
	char two[10] = "medical";
	printf("Name is: %s\n", name);
	printf("Re-enter name:\n");
	fgets(name, 10, stdin);
	printf("New name is:\n%s", name);
	printf("String length is %d\n", string_length(name));
	convert_uppercase(name);
	printf("Name is: %s\n", name);
	printf("%s\n", one);
	printf("%s\n", two);
	printf("%d\n", validate_string(name));
	reverse_string(name);
	printf("%s\n", name);
	printf("%d\n", check_palindromeString(name));
	duplicate_string(name);
	printf("\n%d", check_anagramstring(one, two));
	char str[] = "ABC";
	printf("\n");
	perm_string(str, 0);

	printf("\n\n");
	return 0;
}
*/