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

void add(element* arr, int n, int* position)
{
	arr[*position].priority = n;
	int current_index = *position;
	*position += 1;
	fix_top(arr, current_index);
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

void print(element* arr, int* position)
{
	for (int i = 0; i < *position; i += 1)
	{
		printf("Element[%d]: %d\n", i, arr[i].priority);
	}
}

void add_iterative(element* arr, int num, int* position)
{
	arr[*position].priority = num;
	*position += 1;
}

void iterative_fix_add(element* arr, int* position)
{

	int i = *position - 1;
	while (1) {
		if (i == 0)
		{
			break;
		}
		int parent = (i - 1) / 2;
		if (arr[parent].priority < arr[i].priority)
		{
			element_switch(arr, parent, i);
			i = parent;
		}
		else if (arr[parent].priority >= arr[i].priority)
		{
			break;
		}
	}
}
void remove_iterative(element* arr, int* position)
{
	arr[0] = arr[*position - 1];
	*position -= 1;
}

void fix_remove_element_iterative(element* arr, int* position)
{
	int i = 0;
	while (1)
	{
		int left_child = 2 * i + 1;
		int right_child = 2 * i + 2;
		if (right_child >= *position && left_child >= *position-1)
		{
			break;
		}
		else if (left_child < *position  && right_child >= *position )
		{
			if (arr[i].priority < arr[left_child].priority)
			{
				element_switch(arr, i, left_child);
				i = left_child;
			}
		}
		else if (right_child < *position ) {
			if (arr[i].priority < arr[left_child].priority && arr[left_child].priority >= arr[right_child].priority)
			{
				element_switch(arr, i, left_child);
				i = left_child;
			}
			else if (arr[i].priority <= arr[right_child].priority && arr[right_child].priority >= arr[left_child].priority) {
				element_switch(arr, i, right_child);
				i = right_child;
			}
		}
	}
}


int main(void)
{
	int N = 100; //10000
	element* arr = (element*)malloc(N * sizeof(element));
	int position = 0;
	if (!arr)
	{
		printf("Error");
		return NULL;
	}

	add(arr, 5, &position);
	add(arr, 7, &position);
	add(arr, 2, &position);
	add(arr, 201, &position);
	add(arr, 18, &position);
	add(arr, 22, &position);
	add(arr, 6, &position);
	add(arr, 3, &position);
	add(arr, 300, &position);
	add(arr, 3010, &position);

	print(arr, &position);
	printf("\n");
	remove_from_top(arr, &position);
	print(arr, &position);
	free(arr);

	/*int NN = 100; // 10000
	element* it = (element*)malloc(NN * sizeof(element));
	int iterative_position = 0;
	add_iterative(it, 55, &iterative_position);
	iterative_fix_add(it, &iterative_position);
	add_iterative(it, 15, &iterative_position);
	iterative_fix_add(it, &iterative_position);
	add_iterative(it, 10, &iterative_position);
	iterative_fix_add(it, &iterative_position);
	add_iterative(it, 3, &iterative_position);
	iterative_fix_add(it, &iterative_position);
	add_iterative(it, 13, &iterative_position);
	iterative_fix_add(it, &iterative_position);
	add_iterative(it, 18, &iterative_position);
	iterative_fix_add(it, &iterative_position);
	add_iterative(it, 89, &iterative_position);
	iterative_fix_add(it, &iterative_position);
	add_iterative(it, 180, &iterative_position);
	iterative_fix_add(it, &iterative_position);
	remove_iterative(it, &iterative_position);
	fix_remove_element_iterative(it, &iterative_position);
	print(it, &iterative_position);
	free(it);*/
	return 0;
}




