#include <stdio.h>

void aralik_yazidr(int arr[],int ilk, int son){
    printf("Dizinin ilgilendiğimiz kısmı : ");
    for (int i = ilk; i <= son; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}

void ikili_arama(int arr[],int boyut, int aranan){
    int ilk, son, orta;
    ilk = 0;
    son = boyut - 1;
    orta = (ilk + son) / 2;
    while (ilk <=son){
        printf("ilk : %d .eleman, \tOrta : %d .eleman, \tSon : %d .eleman\n", ilk + 1, orta+1, son+1);
        if (aranan > arr[orta]){
            ilk = orta + 1;
            printf("Aranan sayı %d, dizinin sağ tarafında bulundu... Dizinin sağ yarısını inceliyoruz...\n", aranan);
            aralik_yazidr(arr,ilk,son);
        }
        else if (aranan == arr[orta]){
            printf("%d sayisi, dizinin %d konumunda... \n", aranan, orta+1);
            aralik_yazidr(arr,ilk,son);
            break;
        } else{
            son = orta -1 ;

         printf("Aranan sayı %d, dizinin sol tarafında bulundu... Dizinin sol yarısını inceliyoruz...\n", aranan);
         aralik_yazidr(arr,ilk,son);
        }

        orta = (ilk + son) / 2;
        printf("\n");
        printf("Devam etmek için lütfen bir tuşa basınız... ");
        getchar();
    }

    if (ilk > son)
    printf("%d sayisi, dizide bulamadım aq... \n", aranan);
    printf("\n");
}

int main(){
    printf("İkili arama algoritması, elimizdeki mevcut dizinin küçükten büyüğe sıralı olduğunu kabul ederek işlem yapar\n"
           "Bu nedenle, ilk önce  dizinin eleman sayısına göre orta elemanı bulunur ve aranan sayı ile karşılaştırılır\n"
           "Büyüklük yada küçüklük durumuna göre dizinin sağ ya da sol tarafı incelemeye alınır... \n\n"
           "Aşağıdaki örnekte sizi adım adım bir tasarım ile ne olduğunu açıklamaya çalışacağım....");

    int aranan1 = 14, aranan2 = 6, aranan3 = 5;
    int dizi[] = {2,6,9,12,14,15,16,17,20,25,35,65,68,69,84,98}; //18 eleman var, bakalım hesaplayabilecek mi?
    int boyut = sizeof (dizi)/sizeof (dizi[0]);
    printf("Dizi de %d adet eleman bulunuyor...\n\n ", boyut);
    printf("Ilk arama işlemi ::\n");
    ikili_arama(dizi,boyut, aranan1);
    //printf("İkinci arama işlemi \n");
    //ikili_arama(dizi, boyut, aranan2);
    //printf("Ucuncu arama işlemi \n");
    //ikili_arama(dizi, boyut, aranan3);
}
