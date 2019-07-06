#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


#define LEN 10
int arr[LEN] = {5, 3 , 4, 8, 7, 6, 2, 1, 0, 9};
#define LEN1 9
int arr1[LEN1] = {3, 2, 4, 5, 8, 9, 7, 6, 1};
void output(int arr[], int len)
{
	int i;
	for(i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int* i, int* j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

void select_sort(int arr[], int len)
{
	int i, j;
	int min;

	for(i = 0; i < len; i++)
	{
		min = i;
		for(j = i; j < len; j++)
			if(arr[min] > arr[j])
				min = j;

		if(i != min)
			swap(&arr[i], &arr[min]);
		output(arr, len);
	}
}

void bubble_sort(int arr[], int len)
{
	int i, j;
	int idx;

	for(i = 0; i < len; i++)
	{
		for(j = 0; j < len - i - 1; j++)
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		output(arr, len);
	}
}

void insert_sort(int arr[], int len)
{
	int i, j;
	int temp;
	
	for(i = 1; i < len; i++)
	{
		temp = arr[i];
		for(j = i-1; j >= 0; j--)
		{
			if (temp < arr[j])
				arr[j+1] = arr[j];
			else
				break;
		}
		arr[j+1] = temp;
		output(arr, len);
	}
}

void q_sort(int arr[], int p, int q)
{
	int i, j;
	int key;

	printf("q_sort called p = %d q = %d\n", p, q);
	if (p >= q)
		return;
	
	i = p;
	j = q;
	key = arr[p];
	while(i < j)
	{
		while (i < j)
		{
			if (arr[j] < key)
			{
				swap(&arr[i], &arr[j]);
				break;
			} else
			{
				j--;
				continue;
			}
		}

		while (i < j)
		{
			if (arr[i] > key)
			{
				swap(&arr[i], &arr[j]);
				break;
			} else
			{
				i++;
				continue;
			}
		}
	}
	arr[i] = key;


	if (i == p)
		q_sort(arr, i + 1, q);
	else if (i == q)
		q_sort(arr, p, i - 1);
	else
	{
		q_sort(arr, p, i - 1);
		q_sort(arr, i + 1, q);
	}
}

void quick_sort(int arr[], int len)
{
	q_sort(arr, 0, len - 1);	
}

void _merge(int a1[], int len1, int a2[], int len2)
{
	int i, j, k;

	int *a3;
	a3 = (int *)malloc((len1 + len2) * sizeof(int));

	i = j = k = 0;
	while(i < len1 && j < len2)
	{
		if (a1[i] > a2[j])
			a3[k++] = a2[j++];
		else
			a3[k++] = a1[i++];
	}

	if (i == len1)
		while (j < len2)
			a3[k++] = a2[j++];
	else if (j == len2)
		while (i < len1)
			a3[k++] = a1[i++];
	
	output(a3, len1 + len2);
	
	free(a3);
}

void merge(int arr[], int p, int q, int r)
{
	int i, j, k;
	int *temp;

	printf("call merge p = %d q = %d, r = %d\n", p, q, r);
	if (p == q && p == r)
		return;

	temp = (int *)malloc((r - p + 1) * sizeof(int));
	if (!temp)
	{
		printf("malloc failed failure, no merge\n");
		return;
	}
	memset(temp, 0, (r - p + 1) * sizeof(int));

	i = p;
	j = q + 1;
	k = 0;
	while (i < q + 1 && j < r + 1)
	{
		if (arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];

		output(temp, r - p + 1);
		output(arr + p, r - p + 1);
		printf("3---------------------------\n");
	}

	if (i == q + 1)
		while (j < r + 1)
			temp[k++] = arr[j++];
	else if (j == r + 1)
		while (i < q + 1)
			temp[k++] = arr[i++];
	else
		printf("impossible\n");

	for(i = 0; i < r - p + 1; i++)
		arr[p + i] = temp[i];

	output(temp, r - p + 1);
	output(arr + p, r - p + 1);
	printf("4---------------------------\n\n\n");
	free(temp);
}

void merge_sort(int arr[], int p, int r)
{
	int q;

	if (p < r)
	{
		q = (p + r) / 2;

		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

void bucket_sort()
{}

void heap_sort()
{}

void shell_sort(int arr[], int len)
{
	int i, j, k;
	int d, temp;

	for(d = len/2; d >= 1; d = d/2)
	{
		for(i = 0; i < d; i++)
		{
			for(j = 1; (i + j * d) < len; j++)
			{
				temp = arr[i + j * d];
				for (k = j - 1; k >= 0; k--)
				{
					if (arr[i + k * d] > temp)
						arr[i + (k + 1) * d] = arr[i + k * d];
					else
						break;
				}
				arr[i + (k + 1) * d] = temp;
			}
		}
	}
}

int main()
{
	int a1[3] = {1, 3, 5};
	int a2[6] = {2, 4, 6, 7, 8, 9};
	int a3[1] = {5};
	int a4[4] = {3};
	output(arr, LEN);
	//insert_sort(arr, LEN);
	//select_sort(arr, LEN);
	//bubble_sort(arr, LEN);
	//merge_sort(arr, 0, LEN - 1);
	//quick_sort(arr, LEN);
	shell_sort(arr, LEN);
	output(arr, LEN);
//	output(arr1, LEN1);
	return 0;
}

