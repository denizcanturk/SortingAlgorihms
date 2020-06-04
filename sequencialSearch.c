/*
 * NAME         : sequentialSort Algorithm
 * AUTHOR       : Annonymous
 * Narrator     : Deniz CANTÜRK
 * Date         : 04 Jun 2020
 * O Notation   : O(n)
 * DESCRIPTION  : This snippet gives the oversight
 * on usage of sequential Sort Algo... One of the 
 * simpliest one, just going through all the elements
 * in the array to find it... O(n)
*/


#include <stdio.h>

void ardisik_arama(int arr[], int aranan){
    int sizeofit = sizeof (arr)/ sizeof (arr [0]);

    int i = 0;
    for (i = 0; i < sizeofit ; i++){
        if (arr[i]== aranan){
            printf("%d sayisi, dizinin %d konumunda ...\n ", arr[i], i+1);
            break;
        }

    }
     if (i == sizeofit)
         printf("%d sayısı dizi de bulunamadı\n", aranan);
}

int main(){
   int aranan1 = 11, aranan2 = 8;
   int arr[] = {10,14,11,226,13};
   ardisik_arama(arr,aranan1);
   ardisik_arama(arr,aranan2);
   printf("Please press any key to continue...");
   getchar();
}
