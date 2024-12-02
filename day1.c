#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int crawl(int * arr, int arrSize, int index){

    int multiplier = 1;
    int val = arr[index];
    
    int i = index;
    while(arr[i+1] == val){
        i++;
        multiplier++;
    }
    i = index;
    while(arr[i-1] == val){
        i--;
        multiplier++;
    }


    return multiplier;
}

int calculateSimilarityScore(int * arr,int arrSize, int val){

    int multiplier = 0;

    // Because the lists are ordered, we should be able to just find the value, count instances
    // and then stop traversing the array

    // This is few lines but INSANELY SLOW
    // int i = 0;
    // while(i<arrSize){
    //     if(arr[i]>val) break;
    //     if(arr[i]==val) multiplier ++;
    // }
    // So of course we need to use a search algorithm, hit em with the binary search brother
   
    int max = arrSize;
    int min = 0;

    while(min<=max){
        int pivot = min +(max-min)/2;

        if(arr[pivot] == val){
            multiplier = crawl(arr, arrSize,pivot);
            break;
        }else if(arr[pivot] > val){
            max = pivot - 1;
        }else{
            min = pivot + 1;
        }

    }

    // If we hit a bogey, crawl up and down in both directions until you hit a different value or arr bounds

    return val * multiplier;
}

int distance(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

void mutantInsertionSort(int *arr, int len, int val) {
    int i = len;
    int j = i - 1;

    while (j >= 0 && arr[j] > val) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = val;
}

int main() {
    FILE *fptr;
    size_t len = 0;
    char *line = NULL;

    // Open the file in read mode
    fptr = fopen("TestData/day1.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Count lines to determine array size
    int fileSize = 0;
    while (getline(&line, &len, fptr) != -1) {
        fileSize++;
    }
    fseek(fptr, 0, SEEK_SET);

    // Allocate arrays
    int *leftArray = malloc(fileSize * sizeof(int));
    int *rightArray = malloc(fileSize * sizeof(int));
    if (!leftArray || !rightArray) {
        perror("Memory allocation failed");
        fclose(fptr);
        free(line);
        return 1;
    }

    // Collect values from the file
    int arrayTraverse = 0;
    while (arrayTraverse < fileSize && getline(&line, &len, fptr) != -1) {
        int length1 = 0, length2 = 0;
        sscanf(line, "%d %d", &length1, &length2);

        // Sort arrays while adding values
        mutantInsertionSort(leftArray, arrayTraverse, length1);
        mutantInsertionSort(rightArray, arrayTraverse, length2);

        arrayTraverse++;
    }

    // Calculate distance
    int distanceTraveled = 0;
    for (int i = 0; i < fileSize; i++) {
        distanceTraveled += distance(leftArray[i], rightArray[i]);
    }

    printf("Total distance traveled: %d\n", distanceTraveled);

    
    // Calculate left val * number of occurences in right array
    int similarityScore = 0;
    for (int i = 0; i < fileSize; i++) {
        similarityScore += calculateSimilarityScore(rightArray, fileSize,leftArray[i]);
    }

    printf("Total similarity score: %d\n", similarityScore);


    // Cleanup
    fclose(fptr);
    free(leftArray);
    free(rightArray);
    free(line);

    return 0;
}
