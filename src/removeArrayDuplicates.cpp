/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void deletedup(int *Arr, int *len);
void deletepos(int *Arr, int *len, int pos);
void sortArray(int *Arr, int len);
void swap(int *a, int *b);
void * removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len < 0)
		return NULL;
	else
	{
		sortArray(Arr, len);
		deletedup(Arr, &len);
	}
}

void sortArray(int *Arr, int len){
	int counter1 = 0, counter2 = 0;
	for (counter1 = 0; counter1 < len - 1; counter1++){
		for (counter2 = counter1 + 1; counter2 < len; counter2++){
			if (Arr[counter1] > Arr[counter2]){
				swap(&Arr[counter1],&Arr[counter2]);
			}
		}
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void deletedup(int *Arr,int *len)
{
	int p, q;
	for (p = 0; p < *len - 1; p++){
		for (q = p + 1; q < *len;){
			if (Arr[p] == Arr[q])
				deletepos(Arr, len, q);
			else
				q++;
		}
	}
}

void deletepos(int *Arr, int *len,int p)
{
	int i;
	for (i = p; i<*len - 1; i++)
		Arr[i] = Arr[i + 1];
	*len-=1;
}