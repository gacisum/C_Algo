#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void bubbleSort(int arr[], int len) {
	for(int i = 0; i<len; i++) {
		for(int j = 0; j<len-i; j++) {
			if(arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}
void linearsearch(int arr[], int len, int number) {
	for(int i = 0; i<len; i++) {
		if(number == arr[i]) {
			printf("%d\n", i);
			break;
		}
		else {
			printf("Number not found\n");
			break;
		}
	}
}
void binarysearch(int arr[], int left, int len, int number) {
	if(len>=left) {
		int mid = left + (len - left)/2;
		if(arr[mid] == number) printf("%d found at index %d\n", number, mid);
		//if(arr[mid] != number) printf("%d number not found\n", number);
		else if(arr[mid] > number) binarysearch(arr, left, mid-1, number);
		binarysearch(arr, mid+1, len, number);
	}
	
}
void printarray(int arr[], int len) {
	for(int i = 0; i<len; i++) {
		printf("%d ", arr[i]);
	} printf("\n");
}
void inputarray(int arr[], int len) {
	for(int i = 0; i<len; i++) {
		printf("Index %d: ", i);
		scanf("%d", &arr[i]);
		printf("\n");
	}
}
void menu() {
	printf("Choose one of these numbers: \n");
	printf("1. Bubblesort\n");
	printf("2. Linear search\n");
	printf("3. Binary search\n");
	printf("n. Exit\n");
	printf("\n");
}
int main() {
//	int arr[] = {310, 0, 4, -9, 72, 66, 17, 52, 8, 62};
	int n;
	printf("How many element do you want to input?\n");
	scanf("%d", &n);
	int arr[n];
	inputarray(arr, n);
	int len = sizeof(arr)/sizeof(arr[0]);
	int input;
	char ch;
	
	menu();
	scanf("%d", &input);
	while(1) {
		switch(input) {
		case 1: 
			printf("Unsorted array\n");
			printarray(arr, len);
			bubbleSort(arr, len);
			printf("Sorted array\n");
			printarray(arr, len);
			menu();
			scanf("%d", &input);
		case 2:
			printf("(L)What element do you want to search? \n");
			int number;
			scanf("%d", &number);
			printf("Sorting the array first\n");
			bubbleSort(arr, len);
			linearsearch(arr, len, number);
			menu();
			scanf("%d", &input);
		case 3:
			printf("(B)What element do you want to search? \n");
			scanf("%d", &number);
			printf("Sorting the array first\n");
			bubbleSort(arr, len);	
			printarray(arr, len);
			binarysearch(arr, 0, len-1, number);
			menu();
			scanf("%d", &input);
		default:
			printf("Thank you for coming!\n");
			break;
	}
	}
	
}
