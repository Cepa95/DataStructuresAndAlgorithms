#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	void* ignore;
	int priority;

}element;

void element_switch(element* arr, int left, int right)
{
	element temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void fix_top(element* arr, int i) {
	if (i == 0)
	{
		return;
	}
	int parent = (i - 1) / 2;
	if (arr[parent].priority < arr[i].priority)
	{
		element_switch(arr, parent, i);
		fix_top(arr, parent);
	}
}

void add(element* arr, int* N)
{
	for (int i = 0; i < *N; i += 1)
	{
		arr[i].priority = rand() % *N;
		//printf("%d\t", arr[i].priority);
		fix_top(arr, i);
	}
}

void fix_end(element* arr, int i, int* N)
{
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;
	if (right_child >= *N && left_child >= *N)
	{
		return;
	}
	else if (left_child < *N && right_child >= *N)
	{
		if (arr[i].priority < arr[left_child].priority)
		{
			element_switch(arr, i, left_child);
			fix_end(arr, left_child, N);
		}

	}
	else if (right_child < *N)
	{
		if (arr[i].priority < arr[left_child].priority && arr[left_child].priority >= arr[right_child].priority)
		{
			element_switch(arr, i, left_child);
			fix_end(arr, left_child, N);
		}
		else if (arr[i].priority < arr[right_child].priority && arr[right_child].priority >= arr[left_child].priority)
		{
			element_switch(arr, i, right_child);
			fix_end(arr, right_child, N);
		}
	}
}

void remove_from_top(element* arr, int* N)
{
	arr[0] = arr[*N - 1];
	*N -= 1;
	/*arr = (element*)realloc(arr, *N * sizeof(element));
	if (!arr)
	{
		printf("Error");
	}*/
	fix_end(arr, 0, N);
}

void print(element* arr, int* N)
{
	for (int i = 0; i < *N; i += 1)
	{
		printf("Element[%d]: %d\n", i, arr[i].priority);
	}
}

element* add_it(element* it, int* NN)
{
	for (int i = 0; i < *NN; i += 1)
	{
		it[i].priority = rand() % *NN;
	}
	return it;
}

void add_iterative(element* ite, int* NN)
{
	element* it = add_it(ite, NN);
	for (int i = 0; i < *NN; i += 1)
	{
		int parent = (i - 1) / 2;
		element parentelement = it[parent];
		if (i != 0)
		{
			if (parentelement.priority < it[i].priority)
			{
				element temp = it[parent];
				it[parent] = it[i];
				it[i] = temp;
				i = 0;
			}
		}
	}
}

element* remove_el(element* it, int* NN)
{
	it[0] = it[*NN - 1];
	*NN -= 1;
	return it;
}

void remove_from_top_iterative(element* ite, int* NN)
{
	int i = 0;
	element* it = remove_el(ite, NN);
	/*it = (element*)realloc(it, *NN * sizeof(element));
	if (!it)
	{
		printf("Error");
	}*/

	while (1)
	{
		int left_child = 2 * i + 1;
		int right_child = 2 * i + 2;
		if (right_child >= *NN && left_child >= *NN)
		{
			break;
		}
		else if (left_child < *NN && right_child >= *NN)
		{
			if (it[i].priority < it[left_child].priority)
			{
				element temp = it[i];
				it[i] = it[left_child];
				it[left_child] = temp;
				i = left_child;
				continue;
			}
		}
		else if (right_child < *NN)
		{
			if (it[i].priority < it[left_child].priority && it[left_child].priority >= it[right_child].priority)
			{
				element temp = it[i];
				it[i] = it[left_child];
				it[left_child] = temp;
				i = left_child;
				continue;
			}
			else if (it[i].priority < it[right_child].priority && it[right_child].priority >= it[left_child].priority)
			{
				element temp = it[i];
				it[i] = it[right_child];
				it[right_child] = temp;
				i = right_child;
				continue;
			}
		}
		i += 1;	
	}
}

void print_iterative(element* it, int* NN)
{
	for (int i = 0; i < *NN; i += 1)
	{
		printf("Element[%d]: %d\n", i, it[i].priority);
	}
}

int main(void)
{
	int N = 100; //10000
	element* arr = (element*)malloc(N * sizeof(element));
	if (!arr)
	{
		printf("Error");
		return NULL;
	}
	add(arr, &N);
	print(arr, &N);
	printf("\n");
	remove_from_top(arr, &N);
	print(arr, &N);
	free(arr);

	int NN = 100; // 10000
	element* it = (element*)malloc(NN * sizeof(element));
	if (!it)
	{
		printf("Error");
		return NULL;
	}
	printf("\n");
	add_iterative(it, &NN);
	print_iterative(it, &NN);
	printf("\n");
	remove_from_top_iterative(it, &NN);
	print_iterative(it, &NN);
	free(it);

	return 0;
}