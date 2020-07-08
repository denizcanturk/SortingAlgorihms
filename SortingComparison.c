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
 * sorting algorithms including :
 *      Quick Sort
 *      Bubble Sort
 *      Merge Sort
 *      Selection Sort
 *      Stack Sort
 *      Gnome Sort
 *      Heap Sort
 *      Count Sort
 *      Radix Sort
 *      Bucket Sort
 *      Shell Sort
 *      Cocktail Sort
 *      Pancake Sort
 */


// "LIBS += -L/usr/lib -lpthread"
// ^MUST BE ADDED TO QT .pro FILE FOR SUCCESFULL COMPILATION

#include <stdio.h>
#include <stdlib.h>
#include <obstack.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <pthread.h>
#include <stdbool.h>


#define seperator for (int i = 0; i <40 ; i++) printf("-");printf("\n");  /*I love macros...*/


int moved = 0;
int N=0,R=0;
clock_t quickSortBegin=0, divideSortBegin=0, bubbleSortBegin=0, combineSortBegin=0, selectSortBegin=0, stackSortBegin=0,
gnomeSortBegin=0, heapSortBegin=0,countSortBegin=0, radixSortBegin=0, bucketSortBegin=0, shellSortBegin=0, cocktailSortBegin=0, pancakeSortBegin=0;

clock_t quickSortEnd=0, divideSortEnd=0, bubbleSortEnd=0, combineSortEnd=0, selectSortEnd=0, stackSortEnd=0,
gnomeSortEnd=0, heapSortEnd=0,countSortEnd=0, radixSortEnd=0, bucketSortEnd=0, shellSortEnd=0, cocktailSortEnd=0, pancakeSortEnd=0;

/* Start of Prototype */
// Array Function
void printArray(const int[],int);
int *createArray();
int *copyArray(const int[],int);
//End Of Array Function
/*Start of Sorting Functions*/
int divide(int[],int,int );
void quickSort(int[],int,int);
void bubbleSorting(int[], int);
void combineSort(int[], int, int);
void selectionSort(int[], int);
void StackSort(int[], int);
void StackToMax(int[], int, int);
void gnomeSort(int[], int);
void heapify(int[], int, int);
void heapSort(int[], int);
int getMax(int[], int);
void countSort(int[], int, int);
void radixsort(int[], int);
void Bucket_Sort(int[],int);
void shellSort(int[],int);
void CocktailSort(int[], int);
void pancakeSort(int *arr, int);
void keepMainClean(const int[],int);
void * spinner(void * u);
/*End of Sorting Functions*/

/* Color Definitions */
void red ();
void yellow();
void green();
void magenta();
void cyan();
void reset ();
/* End of Color Definitions */

//* End Of Prototype's *//

/* Pretty Clean Main :) */
int main(){
    int *orig = createArray();
    keepMainClean(orig,N);
    //printArray(orig,N);    //Do you really need to display 100000 elements on the terminal... No! You don't want to... 
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
        usleep(999);
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
/* GNOME Sort*/

void gnomeSort(int arr[], int n)
{
    int index = 0;
    int temp;
    
    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1]= temp;
            index--;
        }
    }
    return;
}

/* HEAP Sort */
void heapify(int arr[], int n, int i)
{
    int temp;
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
    
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    // If largest is not root
    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest]= temp;
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int temp;
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // One by one extract an element from heap
    for (int i=n-1; i>0; i--)
    {
        // Move current root to end
        temp = arr[0];
        arr[0] = arr[i];
        arr[i]=arr[0];
        
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* Radix Sort */

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
    
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
    
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

/* Bucket Sort */
void Bucket_Sort(int array[], int n)
{
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        (count[array[i]])++;
    for (i = 0, j = 0; i < n; i++)
        for(; count[i] > 0; (count[i])--)
            array[j++] = i;
}

/* SHELL Sort */

void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
            
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}

/* Cocktail Sort */

void CocktailSort(int a[], int n)
{
    int temp;
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    
    while (swapped) {
        
        swapped = false;
        
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                
                swapped = true;
            }
        }
        if (!swapped)
            break;
        
        swapped = false;
        
        --end;
        
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swapped = true;
            }
        }
        ++start;
    }
}


/* PANCAKE Sort */

void flip(int arr[], int i)
{
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int findMax(int arr[], int n)
{
    int mi, i;
    for (mi = 0, i = 0; i < n; ++i)
        if (arr[i] > arr[mi])
            mi = i;
    return mi;
}

void pancakeSort(int *arr, int n)
{
    for (int curr_size = n; curr_size > 1; --curr_size)
    {
        int mi = findMax(arr, curr_size);
        
        if (mi != curr_size-1)
        {
            flip(arr, mi);
            flip(arr, curr_size-1);
        }
    }
}

/* Trying to Keep Main Clean */
void keepMainClean(const int orig[] , int N){
    pthread_t tid;
    
    int *copy = copyArray(orig,N);
    printf("\n"
           "A New array with %d element just created...\n\n",N);
    
    pthread_create(&tid, NULL,&spinner,NULL);
    
    printf("Starting QUICK SORT Algo...\n");
    quickSortBegin = clock();
    quickSort(copy,0,N-1);
    quickSortEnd = clock();
    printf("QUICK SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting BUBBLE SORT Algo...\n");
    bubbleSortBegin = clock();
    bubbleSorting(copy,N);
    bubbleSortEnd = clock();
    printf("BUBBLE SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting SELECTION SORT Algo...\n");
    selectSortBegin = clock();
    selectionSort(copy,N);
    selectSortEnd = clock();
    printf("SELECTION SORT Algorithm\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting COMBINE SORT Algo...\n");
    combineSortBegin = clock();
    combineSort(copy,0,N-1);
    combineSortEnd = clock();
    printf("COMBINE SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting STACK SORT Algo...\n");
    stackSortBegin = clock();
    StackSort(copy,N);
    stackSortEnd = clock();
    printf("STACK SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting GNOME SORT Algo...\n");
    gnomeSortBegin = clock();
    gnomeSort(copy,N);
    gnomeSortEnd = clock();
    printf("GNOME SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting HEAP SORT Algo...\n");
    heapSortBegin = clock();
    heapSort(copy,N);
    heapSortEnd = clock();
    printf("HEAP SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting COUNT SORT Algo...\n");
    countSortBegin = clock();
    countSort(copy,0,N);
    countSortEnd = clock();
    printf("COUNT SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting RADIX SORT Algo...\n");
    radixSortBegin = clock();
    radixsort(copy,N);
    radixSortEnd = clock();
    printf("RADIX SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting BUCKET SORT Algo...\n");
    bucketSortBegin = clock();
    Bucket_Sort(copy,N);
    bucketSortEnd = clock();
    printf("BUCKET SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting SHELL SORT Algo...\n");
    shellSortBegin = clock();
    shellSort(copy,N);
    shellSortEnd = clock();
    printf("SHELL SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting COCKTAIL SORT Algo...\n");
    cocktailSortBegin = clock();
    CocktailSort(copy,N);
    cocktailSortEnd = clock();
    printf("COCKTAIL SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    copy = copyArray(orig,N);
    
    printf("Starting PANCAKE SORT Algo...\n");
    pancakeSortBegin = clock();
    pancakeSort(copy,N);
    pancakeSortEnd = clock();
    printf("PANCAKE SORT Algorithm\t\t[ "); green(); printf("COMPLETED"); reset(); printf(" ]\n\n");
    free(copy);
    
    pthread_cancel(tid);
    
    printf("RUNTIME COMPARISON for %d Elements : \n",N);
    seperator;
    
    printf("QUICK SORT\t: %f\n",(double)(quickSortEnd-quickSortBegin)/CLOCKS_PER_SEC);
    printf("BUBBLE SORT\t: %f\n",(double)(bubbleSortEnd-bubbleSortBegin)/CLOCKS_PER_SEC);
    printf("SELECTION SORT\t: %f\n",(double)(selectSortEnd-selectSortBegin)/CLOCKS_PER_SEC);
    printf("MERGE SORT\t: %f\n",(double)(combineSortEnd-combineSortBegin)/CLOCKS_PER_SEC);
    printf("STACK SORT\t: %f\n",(double)(stackSortEnd-stackSortBegin)/CLOCKS_PER_SEC);
    printf("GNOME SORT\t: %f\n",(double)(gnomeSortEnd-gnomeSortBegin)/CLOCKS_PER_SEC);
    printf("HEAP SORT\t: %f\n",(double)(heapSortEnd-heapSortBegin)/CLOCKS_PER_SEC);
    printf("COUNT SORT\t: %f\n",(double)(countSortEnd-countSortBegin)/CLOCKS_PER_SEC);
    printf("RADIX SORT\t: %f\n",(double)(radixSortEnd-radixSortBegin)/CLOCKS_PER_SEC);
    printf("BUCKET SORT\t: %f\n",(double)(bucketSortEnd-bucketSortBegin)/CLOCKS_PER_SEC);
    printf("SHELL SORT\t: %f\n",(double)(shellSortEnd-shellSortBegin)/CLOCKS_PER_SEC);
    printf("COCKTAIL SORT\t: %f\n",(double)(cocktailSortEnd-cocktailSortBegin)/CLOCKS_PER_SEC);
    printf("PANCAKE SORT\t: %f\n",(double)(pancakeSortEnd-pancakeSortBegin)/CLOCKS_PER_SEC);
    
    
}

void * spinner(void * u){
    
    char spr[4]={"\\|/-"};
    int i =0;
    while(i<5){
        printf("Running...%c\r", spr[i]);
        fflush(stdout);
        
        usleep(99999);
        i++;
        if (i == 4)
            i = 0;
        //printf("\r\r");
    }
    return 0;
}
void red () {
    printf("\033[1;31m");
}

void green(){
    printf("\033[0;32m");
}

void yellow(){
    printf("\033[1;33m");
}
void magenta(){
    printf("\033[0;35m");
}
void cyan(){
    printf("\033[0;36m");
}
void reset () {
    printf("\033[0m");
}
