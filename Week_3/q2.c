#include<stdio.h>
#include<string.h>

int string_matching(char* s, char* t){
	int n=strlen(s);
	int m=strlen(t);
	for (int i = 0; i < n-m; i++){
		int j = 0;
		while (j < m && s[i+j] == t[j]){
			j++;
		}
		if (j == m) return i;
	}
	printf("No match found");
	return -1;
}
int main(){
	char* s="hellabcomyabccdnameisa";
	char* t="abcd";
	printf("%d\n", string_matching(s,t));
}