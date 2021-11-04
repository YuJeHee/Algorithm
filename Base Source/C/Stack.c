#include <stdio.h>
#include "IntStack.h"

typedef struct {
	int max;
	int ptr;
	int* stk;
} IntStack;

int Initialize(IntStack* s, int max);
int Push(IntStack* s, int x);
int Pop(IntStack* s, int* x);
int Peek(const IntStack* s, int* x);
void Clear(IntStack* s);
int Capacity(const IntStack* s);
int Size(const IntStack* s);
int IsEmpty(const IntStack* s);
int IsFull(const IntStack* s);
int Search(const IntStack* s, int x);
void Print(const IntStack* s);
void Terminate(IntStack* s);

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		printf("Stack Init Error!\n");
		return -1;
	}
	while (1)
	{
		int menu, x, index;
		printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("1. Push\n2. Pop\n3. Peek\n4. Print\n5. Search\n6. IsEmpty\n7. IsFull\n0. Terminate\nMenu Input : ");
		scanf("%d", &menu);

		if (menu == 0) break;

		switch (menu)
		{
		case 1:
			printf("Push Data : ");
			scanf("%d", &x);
			if (Push(&s, x) == 1)
			{
				printf("Push Error!\n");
			}
			break;
			
		case 2:
			if (Pop(&s, &x) == -1)
			{
				printf("Pop Error!\n");
			}
			else
			{
				printf("Pop Data : %d\n", x);
			}
			break;

		case 3:
			if (Peek(&s, &x) == 1)
			{
				printf("Peek Error!\n");
			}
			else
			{
				printf("Peek Data : %d \n", x);
			}
			break;

		case 4:
			Print(&s);
			break;

		case 5:
			printf("Search Data : ");
			scanf("%d", &x);
			if ((index = Search(&s, x)) == 1)
			{
				printf("Search Error!\n");
			}
			else
			{
				printf("Search Data : %d to index", index);
			}
			break;

		case 6:
			if(IsEmpty(&s) <= 0)
			{
				printf("Not Empty!\n");
			}

			else
			{
				printf("Is Empty!\n");
			}
			break;
		case 7:
			if(IsFull(&s) <= 0)
			{
				printf("not Full!\n");
			}
			else
			{
				printf("Is Full!\n");
			}
			break;
		}
	}

	Terminate(&s);

	return 0;
}


int Initialize(IntStack* s, int max)
{
	s->ptr = 0;
	if ((s->stk = (int*)malloc(sizeof(int) * max)) == NULL)
		//if((s->stk = calloc(max, sizeof(int))) == NULL)
	{
		s->max = 0;
		return -1;
	}
	s->max = max;
	
  return 0;
}

int Push(IntStack* s, int x)
{
	if (s->ptr >= s->max)
		return -1;

	s->stk[s->ptr++] = x;
	return 0;
}

int Pop(IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr--];
	return 0;
}

int Peek(const IntStack* s, int* x)
{
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1];
	return 0;
}

void Clear(IntStack* s)
{
	s->ptr = 0;
}

int Capacity(const IntStack* s)
{
	return s->max;
}

int Size(const IntStack* s)
{
	return s->ptr;
}

int IsEmpty(const IntStack* s)
{
	return s->ptr <= 0;
}

int IsFull(const IntStack* s)
{
	return s->ptr >= s->max;
}

int Search(const IntStack* s, int x)
{
	int i;
	for (i = s->ptr - 1; i >= 0; i--)
	{
		if (s->stk[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void Print(const IntStack* s)
{
	int i;
	for (i = 0; i < s->ptr; i++)
	{
		printf("%d ", s->stk[i]);
	}
	printf("\n");
}

void Terminate(IntStack* s)
{
	if (s->stk != NULL)
	{
		free(s->stk);
	}
	s->max = s->ptr = 0;
}
