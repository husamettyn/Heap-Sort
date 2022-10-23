#include <stdio.h>
#include <time.h>
#include <math.h>
#define MAX 10000
void swap(int *a, int *b);
void heapify(int array[], int n, int i);
void heapSort(int array[], int n);
void printArray(int array[], int n);
void inputArray(int array[], int n);
int main(){
	int array[MAX], n;
	srand(time(NULL));
	printf("---------------------------------------------Heap Sort Algorithm---------------------------------------------\n\n");
	printf("Please Enter Numbers There will Be: ");
	scanf("%d", &n);
	inputArray(array, n);
	heapSort(array, n);
	printf("Sorted Array: ");
	printArray(array, n);
	return 0;
}
void heapify(int array[], int n, int i){
	// Assign root, left and right
	// left = 2*i + 1
	// right = 2*i + 2
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i+2;
	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;
	if(largest != i){
		swap(&array[i], &array[largest]);
		heapify(array, n, largest);
	}	
}
void heapSort(int array[], int n){
	int i;
	// Max Heap
	for(i=n/2-1;i>=0;i--)
		heapify(array, n, i);
	// Heap Sort
	for(i = n - 1; i >= 0; i--){
		swap(&array[0], &array[i]);
		// Heapify Again
		heapify(array, i, 0);
	}
}
void inputArray(int array[], int n){
	int i, j;
	int min, max;
	system("cls");
	printf("1- Manuel Input\n2- Create Random Numbers\n");
	scanf("%d", &j);
	if(j==1){
		for(i=0;i<n;i++){
			printf("%d. number: ", i);
			scanf("%d", &array[i]);
		}
	}
	else{
		printf("Please Enter Higher and Lower Limit(exp: 1 20): ");
		scanf("%d %d", &min, &max);		
		for(i=0;i<n;i++){
			do{
				array[i] = (rand())*pow(-1,rand());
			}
			while(array[i] < min || array[i] > max);			
		}
		printf("Random Created Array:  ");
		printArray(array, n);
	}
}
void printArray(int array[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
