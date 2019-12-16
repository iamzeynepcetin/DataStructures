
#include <stdio.h>

#define    satir   5
#define    sutun   5

void InsertionSort(int dizi[],int diziboyu){

for(int i=1;i<=diziboyu;i++){
    for(int j=i;j>0;j--){
        if (dizi[j]<dizi[j-1]){
            yerdegis(&dizi[j],&dizi[j-1]);
}
    }
        }
            }

void yerdegis(int *birincideger , int *ikincideger){

int gecici=*birincideger;
*birincideger=*ikincideger;
*ikincideger=gecici;

}

void yazdir(int dizi[],int diziboyu){
for(int i=1;i<=diziboyu;i++){
    printf("%d ",dizi[i]);
}
}

int main()
{
int matris[satir][sutun]={{0, 3, 2,1,8},
			              {1, 2, 3,9,8},
                          {5, 6, 7,2,1},
                          {1, 2, 3,9,8},
                          {1, 2, 3,9,8}};
int p[satir*sutun];
int k=0;
int yeni[sutun];
for(int i=0;i<satir;i++){
for(int j=0;j<sutun;j++){
    p[k]=matris[i][j];
    k++;
}
}
for(int i=0;i<satir;i++){
for(int j=0;j<sutun;j++){
        printf( "%d ", matris[i][j] );
}
printf( "\n" );
}




int girilensatir;
printf(" hangi satiri alayim ?");
scanf("%d",&girilensatir);

int istenensatir=satir-(girilensatir-1);
int deger1=((satir*sutun)-(istenensatir*sutun));
int deger2=deger1+sutun;
 int a=0;
 for(int k=deger1;k<deger2;k++){
    yeni[a]=p[k];
    ++a;

}
 InsertionSort(yeni,5);
 yazdir(yeni,5);
 }
