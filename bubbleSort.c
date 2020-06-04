/*
 * Subject    : Bubble Sort
 * Orijinator : Anonymous
 * Narrator   : Deniz CANTÜRK
 * O Natation : O(n^2)
 * Purpose    : Simplification and visualisation of Bubble Sorting
*/
#define hold printf("Press any key..."); getchar();                       /*I love macros..*/
#define seperator for (int i = 0; i <122 ; i++) printf("-");printf("\n"); /*I love macros...*/
#include <stdio.h>
int moved = 0; //Global  Variable
/* Prints the Array to the Screen*/
void printArray(int arr[], int size){
    for (int i = 0; i < size ; i++){
        if (arr[i]== moved){
        printf("|%d|\t\t",arr[i]);
        }else
        printf(" %d\t\t",arr[i]);
    }
    printf("\n");
}

/* Sorting with Bubble Algo */

void bubbleSorting(int arr[], int size){
    int temp;

    for (int i = 0; i < size-1 ; i++){
        for (int j = 0 ; j < size -i -1 ; j++){
           if(arr[j] > arr[j+1]) {
               temp = arr[j];
               arr[j]=arr[j+1];
               moved = arr[j];
               arr[j+1]=temp;
           }
           moved= arr[j+1];
           printArray(arr,size);
           hold; /*Just a macro to keep it simple*/
        }

    }
    seperator;
    printf("\nSirali : \n");
    moved = 0;
    printArray(arr,size);
}

int main (){

    int unsortedArray[] = {65,4,58,98,32,1,6,7,85};
    int size = sizeof (unsortedArray)/sizeof (unsortedArray[0]);

    printf("Sırasız : \n");
    seperator;
    printArray(unsortedArray, size);
    bubbleSorting(unsortedArray, size);
}
