#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void quickSort(){

}


int main (){

    // Read the file to the end, using the tricky C filereading trick where you go to the bottom and jump back up
    // Find the amount of \n in the file, that should be the length of the arrays
    // Or if we add up all the numbers from each column in the data, then subtract the smaller one from the higher that that should be the distance?

    FILE *fptr;
    char* line = NULL;

    // Open a file in read mode
    fptr = fopen("TestData/day1.txt", "r");
    if(fptr == NULL){
        perror("Error operning file");
        return 1;
    }

    // Get the amount of entries I'll need to put in my arrays
    int fileSize = 0; 
    while(getline(line) != -1){
        fileSize++;
    }
    fseek(fptr, 0, SEEK_SET);

    int * leftArray = malloc(fileSize * sizeof(int));
    int * rightArray = malloc(fileSize * sizeof(int));

    int length1;
    int length2;


    // Should I sort the array as I'm adding values to it?
    // Is that even possible in a timely manner?
    // Can I merge sort as I go?
    // Is the step in a quick sort more appropriate



    // Collect the values from the file, add them to arrays
    int arrayTraverse = 0;
    while(arrayTraverse < fileSize){
        size_t read = getline(line, stdin);
        
        //Read each number backwards, times each number by 10 * reverse index
        int tens = 1;
        bool space = false;
        for(int i = read; i>=0;i++){
            int num = line[i] * tens;

            if(line[i] == ' '){
                space = true;
                continue;
            }else if (space == false){
                length1 += num; 
            }else{
                length2 += num;
            }
        
            tens *=10; 
        }

        leftArray[arrayTraverse] = length1;
        rightArray[arrayTraverse] = length2;

        if(feof(fptr)){
            break;
        }
    }


    // Sort both arrays

    // Calculate distance between the two
    arrayTraverse = 0;
    while()

    


    // Create 2 lists of scaleable length

    // Open test data file

    // Order the 2 lists

    // Compare each index of both lists, subtract the larger number from the smaller one


    return 0;
}