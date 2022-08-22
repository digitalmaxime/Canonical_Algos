#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap (int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quicksort(int arr[], int left, int right) {
    if (right - left >= 1) {
        int pivot = arr[right];
        int i=left-1; // i represente la ieme position qui est assurement plus petite que pivot
        int j=left; // j balaie tout le array de droite a gauche sans interruption
        for (int j=left; j<right; j++) {
            if (arr[j] <= pivot) {
                i++; //avance vers le prochain 'trop grand' -non-adequat
                swap(arr, i, j); // maintenant i pointe vers l'element adequat (decouvert a date) le plus a droite 
                //printing
                // for (int i=0; i<right+1; i++) {
                //     printf("%d ", arr[i]);
                // }
                // printf("i : %d\n", i);
            }
        }
        swap(arr, ++i, right);
        quicksort(arr, 0, i-1);
        quicksort(arr, i+1, right);
    }
}
int main(int argc, char** argv) {
    write(1,"Sorting numbers passed through command line\n",\
        45 );     
    int* arr = malloc(argc * sizeof(int));
    for (int i=1; i<argc; i++) {
        arr[i-1] = atoi(argv[i]);
    }
    //printing
    // for (int i=0; i<argc-1; i++) {
    //     printf("%d\n", arr[i]);
    // }
    
    

    //int arr[] = {3, 6, 1, 2, 5, 7, 8, 4};
    // int size = sizeof(arr)/sizeof(arr[0]);
    int size = argc -1;
    quicksort(arr, 0, size-1);
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}