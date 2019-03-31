#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(a,b,t) ((t)=(a),(a)=(b),(b)=(t));
#define COMPARE(a,b) (  (   (a)<(b)  ) ? -1 : ( ((a)==(b))? 0 : 1  ) )

void sort(int* arr, int n);
int binarySearch(int list[], int searchNum, int left, int right);
int main() {
	
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");
	int n = 0;
	int* list;

	fscanf(fin, "%d", &n);

	if (n < 0) {
		fprintf(stderr, "improper n\n");
		exit(EXIT_FAILURE);
	}

	list = (int*)malloc(sizeof(int)*n);
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		
		list[i] = rand() % 1000;
	}
	sort(list, n);
	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d ", list[i]);
	}
	fprintf(fout, "\n");
	
	fprintf(fout, "%d", binarySearch(list, list[2], 0, n - 1));



	free(list);
	fclose(fin);
	fclose(fout);

	return 0;
}
void sort(int* arr, int n) {
	int min=0;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i+1; j < n; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}

		SWAP(arr[i], arr[min], temp);


	}
}
int binarySearch(int list[], int searchNum, int left, int right) {

	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		switch (COMPARE(searchNum, list[middle])) {
		case -1:
			right = middle - 1;
			break;
		case 0:
			return middle;
			break;
		case 1:
			left = middle + 1;
			break;
		}
		
	}
	exit(EXIT_FAILURE);
}