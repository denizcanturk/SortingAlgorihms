/*
 * NAME         : Combining Search Algorithm
 * AUTHOR       : Annonymous
 * Narrator     : Deniz CANTÜRK
 * Date         : 05 Jun 2020
 * O Notation   : O(n*log(n))
 * Stable       : YES
 * DESCRIPTION  : This snippet gives the oversight
 * on usage of CombiningSearchAlgo mainly on dividing
 *  the array to 2 pieces and making the comparison
 *  as a result sorting...
*/


/* birlestirerek_siralama.c */
#include <stdio.h>

int dizi[] = { 21, 13, 9, 12, 4 };
int boyut = sizeof(dizi) / sizeof(int);


/* Verilen diziyi ekrana yazdiran fonksiyon */
void dizi_yazdir(int dizi[], int boyut){
    int i;
    for (i = 0; i < boyut; i++){
        printf("%d\t", dizi[i]);
    }
    printf("\n");
}

/* Alt diziler sirali olarak birlestiriliyor*/
void birlestir(int dizi[], int ilk, int orta, int son){
    int* gecici = (int*) malloc((son - ilk + 1)*sizeof(int));
    int i = ilk;
    int j = orta + 1;
    int k = 0;
    while (i <= orta && j <= son)
    {
        if (dizi[i] <= dizi[j])
            gecici[k++] = dizi[i++];
        else
            gecici[k++] = dizi[j++];
    }
    while (i <= orta) gecici[k++] = dizi[i++];
    while (j <= son) gecici[k++] = dizi[j++];
        k--;

while (k >= 0)
{
    dizi[ilk + k] = gecici[k];
    k--;
}
free(gecici);
}
/* Dizi, orta noktadan ikiye ayrilarak alt diziler elde ediliyor*/

void birlestirerek_siralama(int dizi[], int ilk, int son)
{
    if (ilk < son) {
        int orta = (son + ilk) / 2;
        birlestirerek_siralama(dizi, ilk, orta);
        birlestirerek_siralama(dizi, orta + 1, son);
        birlestir(dizi, ilk, orta, son);
    }
}
int main()
{
    printf("\nSirasiz: ");
    dizi_yazdir(dizi, boyut);
    printf("-----------------------------------------\n");
    birlestirerek_siralama(dizi, 0, boyut - 1);
    printf("\nSirali: ");
    dizi_yazdir(dizi, boyut);
    printf("-----------------------------------------\n");
}
