#define _CRT_SECUER_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	int grade;

	printf("학번 입력 : ");
	scanf("%d", &num);
	//getchar();
	fflush(stdin);
	printf("학점 입력 : ");
	grade = getchar();
	printf("학번 : %c, 학점 : %c", num, grade);

}