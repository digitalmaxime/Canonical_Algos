#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void insertionsort(int arr[], int size) {
    int j, temp;
    for (int i=1; i<size; i++) {
        temp = arr[i];
        for (j=i; j>0 && arr[j-1] > temp; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}
int main() {
    int arr[] = {2, 3, 1, 4, 5, 9, 10, 5};
    int size = 8;
    insertionsort(arr, size);
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}