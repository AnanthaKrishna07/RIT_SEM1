#include<stdio.h>
#include<stdlib.h>

void main() {
    int a, b, i, j, c;
    int arr1[100], arr2[100], arr3[200];  

   
    printf("Enter number of elements in array1: ");
    scanf("%d", &a);
    printf("Enter the elements: ");
    for (i = 0; i < a; i++) {
        scanf("%d", &arr1[i]);
    }

    
    printf("Enter number of elements in array2: ");
    scanf("%d", &b);
    printf("Enter the elements: ");
    for (j = 0; j < b; j++) {
        scanf("%d", &arr2[j]);
    }

   
    i = 0; 
    j = 0; 
    c = 0;

    while (i < a && j < b) {
        if (arr1[i] < arr2[j]) {
            arr3[c++] = arr1[i++];
        } else {
            arr3[c++] = arr2[j++];
        }
    }

  
    while (i < a) {
        arr3[c++] = arr1[i++];
    }

  
    while (j < b) {
        arr3[c++] = arr2[j++];
    }

    
    printf("Merged array: ");
    for (i = 0; i < c; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");
}
