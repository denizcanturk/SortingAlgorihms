/*
 * NAME         : QuickSort Algorithm
 * AUTHOR       : Annonymous
 * Narrator     : Deniz CANTÜRK
 * Date         : 04 Jun 2020
 * O Notation   : O(n^2)
 * DESCRIPTION  : This snippet gives the oversight
 * on usage of QuickSearchrunning mainly on dividing
 *  the array to 2 piecesand making the comparison
 *  as a result sorting...
*/


#include <stdio.h>

int sirasiz_dizi[] = { 21, 13, 9, 12, 4 };
int boyut = sizeof(sirasiz_dizi) / sizeof(int);

/* Verilen diziyi ekrana yazdiran fonksiyon */
void dizi_yazdir(int dizi[], int boyut){
    int i;
    for (i = 0; i < boyut; i++)
    {
        printf("[%d]\t", dizi[i]);
    }
    printf("\n\n");
 }

    /* Bölümleme algoritması içeren fonksiyon*/
    int bolumle(int dizi[], int ilk, int son){
        int i = ilk;
        int j = son;
        int gecici;
        int pivot = dizi[(ilk + son) / 2];
        printf("Pivot Location : %d & Value : %d\n", (ilk+son)/2, dizi[(ilk+son)/2]);
        while (i <= j)
        {
            while (dizi[i] < pivot) i++;
            while (dizi[j] > pivot) j--;
            if (i <= j){
                printf("Swapping : [%d] <-> [%d]\n",dizi[j], dizi[i]);
                gecici = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = gecici;
                i++;
                j--;
            }
            dizi_yazdir(dizi,boyut);
        }
        return i;
    }
    /* Hizli siralama fonksiyonu */
    void hizli_siralama(int dizi[], int ilk, int son){
        int konum = bolumle(dizi, ilk, son);

        if (ilk < konum - 1)
            hizli_siralama(dizi, ilk, konum - 1);

        if (konum < son)
            hizli_siralama(dizi, konum, son);

   }

    int main(){
        printf("\nSirasiz: ");
        dizi_yazdir(sirasiz_dizi, boyut);
        printf("-----------------------------------------\n");
        hizli_siralama(sirasiz_dizi, 0, boyut - 1);
        printf("-----------------------------------------\n");
        printf("Sirali: ");
        dizi_yazdir(sirasiz_dizi, boyut);
    }
