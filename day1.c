#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int calculateSimilarityScore(int * leftArr, int * rightArr, int val){

    // Because the lists are ordered, we should be able to just find the value, count instances
    // and then stop traversing the array



    return;
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



    // Here we examine the similarity score between the left list and right list
    // Go over each index, count number of time it appears in right
    // add to total

    int similarityScore = 0;
    for (int i = 0; i < fileSize; i++) {
        similarityScore +=calculateSimilarityScore(leftArray, rightArray,leftArray[i]);   
    }


    // Cleanup
    fclose(fptr);
    free(leftArray);
    free(rightArray);
    free(line);

    return 0;
}
