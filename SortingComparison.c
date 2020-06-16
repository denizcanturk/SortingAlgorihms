/*
 * NAME         : Sorting Algorithm Comparison
 * AUTHOR       : Annonymous
 * Narrator     : Deniz CANTÜRK
 * Date         : 16 Jun 2020
 * Exec Time    : Calculated at the End
 * O Notation   : Calculated at the End  -> This still needs to be created...
 * Stable       : Varies
 * DESCRIPTION  : This snippet gives the oversight
 * on Time Complexity and quickness of the different
 * sorting algorithms...
 */

#include <stdio.h>
#include <stdlib.h>
#include <obstack.h>
#include <time.h>

#define seperator printf("\n");for (int i = 0; i <106 ; i++) printf("-");printf("\n");  /*I love macros...*/


int moved = 0;
int N=0,R=0;
clock_t quickSortBegin=0, divideSortBegin=0, bubbleSortBegin=0, combineSortBegin=0, selectSortBegin=0, stackSortBegin=0;
clock_t quickSortEnd=0, divideSortEnd=0, bubbleSortEnd=0, combineSortEnd=0, selectSortEnd=0, stackSortEnd=0;

/* Let's Prototype */
void printArray(const int[],int);
int *createArray();
int *copyArray(const int[],int);
int divide(int[],int,int );
void quickSort(int[],int,int);
void bubbleSorting(int[], int);
void combineSort(int[], int, int);
void selectionSort(int[], int);
void StackSort(int[], int);
void StackToMax(int[], int, int);
void keepMainClean(const int[],int);
/* End Of Prototype's */

/* Pretty Clean Main :) */
int main(){
    int *orig = createArray();
    keepMainClean(orig,N);
    free(orig);
    return 0;
}

/* Creates one original Array of N elemantes asked by the user */
int* createArray(){
    printf("How many elements do you want in an Array : ");
    scanf("%d", &N);

    printf("What is the MAX_RANGE for Random Numbers : ");
    scanf("%d", &R);

    // fflush(stdin);
    int *createdArray = malloc (N * sizeof (int));

    for (int i = 0; i < N ; i++){
        createdArray[i] = (rand() % R);
    }
    return createdArray;
}

/* Copies Original Array to thread the Algorithms equally */
int *copyArray(const int arr[], int N){
    int *copy = malloc(N * sizeof (int));
    for (int i = 0; i < N ;i++){
        copy[i] = arr[i];
    }
    return copy;
}

/* Just prints the Array... Used Debugging purposes... */
void printArray(const int dizi[], int N){
    int i=0;
    do {
        printf("|%d|\t\t", dizi[i]);
        i++;
        if (i % 12 == 0)
            printf ("\n");
    }while (i < N);
    seperator;              //My Fancy Macro
}


/* Divide Function for QUICK SORT Algorithm */
int divide(int arr[], int frst, int lst){
    int i = frst;
    int j = lst;
    int temp;
    int pivot = arr[(frst + lst) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j){
            //printf("Swapping : [%d] <-> [%d]\n",dizi[j], dizi[i]);
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

/* QUICK SORT Algorithm */
void quickSort(int arr[], int frst, int lst){
    int pos = divide(arr, frst, lst);

    if (frst < pos - 1)
        quickSort(arr, frst, pos - 1);

    if (pos < lst)
        quickSort(arr, pos, lst);
}


/* BUBBLE SORT Algorithm */
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
        }

    }
    moved = 0;
}


/* Combining Function for COMBINING SORT Algorithm */

void combineThem(int arr[], int frst, int mid, int lst){
    int* temp = (int*) malloc((lst - frst + 1)*sizeof(int));
    int i = frst;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= lst)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= lst) temp[k++] = arr[j++];
    k--;

    while (k >= 0)
    {
        arr[frst + k] = temp[k];
        k--;
    }
    free(temp);
}

/* COMBINING SORT Algorithm */
void combineSort(int dizi[], int ilk, int son)
{
    if (ilk < son) {
        int orta = (son + ilk) / 2;
        combineSort(dizi, ilk, orta);
        combineSort(dizi, orta + 1, son);
        combineThem(dizi, ilk, orta, son);
    }
}


/* SELECTION SORT Algorithm */
void selectionSort(int arr[], int size){
    int smallest, temp;

    for (int i = 0 ; i < size -1 ; i++){
        smallest = i;

        for(int j = i +1; j < size ; j++){
            if (arr[j] < arr[smallest])
                smallest = j;
        }

        if (smallest != i){
            temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
        }
    }


}

/* STUCK SORT Algorithm */
void StackToMax(int arr[], int n, int i) {
    int maxi = i;
    int lefty = 2 * i + 1;
    int righty = 2 * i + 2;
    int temp;

    if (lefty < n && arr[lefty] > arr[maxi])
        maxi = lefty;

    if (righty < n && arr[righty] > arr[maxi])
        maxi = righty;
    if (maxi != i)
    {
        temp = arr[i];
        arr[i] = arr[maxi];
        arr[maxi] = temp;
    }
}

void StackSort(int arr[], int N)
{
    int i, temp;
    for (i = N / 2 - 1; i >= 0; i--)
        StackToMax(arr, N, i);
    for (i = N - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        StackToMax(arr, i, 0);
    }
}


/* Trying to Keep Main Clean */
void keepMainClean(const int orig[] , int N){
    int *copy = copyArray(orig,N);
    printf("\n"
           "A New array with %d element just created...\n\n",N);

    printf("Starting QUICK SORT Algo...\n");
    quickSortBegin = clock();
    quickSort(copy,0,N-1);
    quickSortEnd = clock();
    printf("QUICK SORT Algorithm\t\t[ COMPLETED ]\n\n");

    copy = copyArray(orig,N);

    printf("Starting BUBBLE SORT Algo...\n");
    bubbleSortBegin = clock();
    bubbleSorting(copy,N);
    bubbleSortEnd = clock();
    printf("BUBBLE SORT Algorithm\t\t[ COMPLETED ]\n\n");

    copy = copyArray(orig,N);

    printf("Starting SELECTION SORT Algo...\n");
    selectSortBegin = clock();
    selectionSort(copy,N);
    selectSortEnd = clock();
    printf("SELECTION SORT Algorithm\t[ COMPLETED ]\n\n");

    copy = copyArray(orig,N);

    printf("Starting COMBINE SORT Algo...\n");
    combineSortBegin = clock();
    combineSort(copy,0,N-1);
    combineSortEnd = clock();
    printf("COMBINE SORT Algorithm\t\t[ COMPLETED ]\n\n");

    copy = copyArray(orig,N);

    printf("Starting STACK SORT Algo...\n");
    stackSortBegin = clock();
    StackSort(copy,N);
    stackSortEnd = clock();
    printf("STACK SORT Algorithm\t\t[ COMPLETED ]\n\n");

    printf("RUNTIME COMPARISON for %d Elements : \n"
           "QUICK SORT\t\tBUBBLE SORT\t\tSELECTION SORT\t\tCOMBINE SORT\t\tSTACK SORT"
           ,N);
    seperator;
    printf("%f\t\t%f\t\t%f\t\t%f\t\t%f\n\n",
           (double)(quickSortEnd-quickSortBegin)/CLOCKS_PER_SEC,
           (double)(bubbleSortEnd-bubbleSortBegin)/CLOCKS_PER_SEC,
           (double)(selectSortEnd-selectSortBegin)/CLOCKS_PER_SEC,
           (double)(combineSortEnd-combineSortBegin)/CLOCKS_PER_SEC,
           (double)(stackSortEnd-stackSortBegin)/CLOCKS_PER_SEC);
    free(copy);
}
