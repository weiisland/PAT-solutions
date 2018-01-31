#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 20000
using namespace std;

char A[MAXN], B[MAXN], C[MAXN];

void reverse(char A[], char B[], int n)
{
	for (int i = n-1; i >= 0; i--) {
		B[i] = A[n-i-1];
	}
}

bool isPalindromic_number(char A[], int n)
{
	int mid = n / 2;
	for (int i = 0; i < mid; i++) {
		if (A[i] != A[n-i-1]) {
			return false;
		}
	}
	return true;
}

void plusAB(char A[], char B[], char C[], int n)
{
	int carry = 0;
	int j = 0;
	for (int i = n-1; i >= 0; i--) {
		int a = A[i] - '0';
		int b = B[i] - '0';
		C[j++] = '0' + ((a + b +carry) % 10);//注意这里要先+carry
		carry = (a + b + carry) / 10;//同样要注意carry
	}
	if (carry > 0) {//carry大于0才加到C
		C[j] = '0' + carry;
	}
	
}

int main(int argc, char *argv[]) {
	scanf("%s", A);
	reverse(A, B, strlen(A));
	int i;
	int flag = false;
	for (i = 0; i < 10; i++) {
		//提前检测A是不是回文数
		if (isPalindromic_number(A, strlen(A))) {
			printf("%s is a palindromic number.\n", A);
			flag = true;
			break;
		}
		plusAB(A, B, C, strlen(A));
		printf("%s + %s = ", A, B);
		strcpy(B, C);
		reverse(C, A, strlen(C));
		printf("%s\n", A);

	}
	if (!flag) {
		printf("Not found in 10 iterations.\n");
	}	
	return 0;
}
