#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int* ptr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i != n-1)
		{
			printf("%d-", ptr[i]);
		}
		else
		{
			printf("%d", ptr[i]);
		}
	}
	printf("\n");
}

void randomFill(int* ptr, int n)
{
	for (int i = 0; i < n; i++)
	{
		ptr[i] = rand() % 50;
	}
}

void bubbleSort(int *ptr, int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (ptr[i] < ptr[j])
			{
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}

int main()
{
	int* ptr;
	int n;
	srand(time(NULL));
	printf("Enter size: ");
	scanf_s("%d", &n);
	ptr = (int*)calloc(n, sizeof(int));

	if (ptr == NULL)
	{
		printf("Memory not allocated");
	}
	else
	{
		printf("Memory succesfully allocated\n");
	}

	printf("Array printing.\n");
	print(ptr, n);
	printf("Array random filling\n");
	randomFill(ptr, n);
	print(ptr, n);
	bubbleSort(ptr, n);
	print(ptr, n);
	free(ptr);
	return 0;
}