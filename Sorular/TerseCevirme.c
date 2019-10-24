#include <stdio.h>
#include <stdlib.h>

struct node{
    int veri;
    struct node *sonraki;
};

struct node* baslangic = NULL;
struct node* geciciDegisken;

struct node* dugumOlustur()
{
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    return yeniDugum;
}

void sonaEkle(int x)
{
    struct node* element = dugumOlustur();
    element->veri = x;
    element->sonraki = NULL;

    if(baslangic == NULL)
    {
        baslangic = element;
    }
    else
    {
        geciciDegisken = baslangic;
        while(geciciDegisken->sonraki != NULL)
        {
            geciciDegisken = geciciDegisken->sonraki;
        }
        geciciDegisken->sonraki = element;
    }

}

void tersCevir()
{
    struct node* oncekiDugum = NULL;
    struct node* sonrakiNode;
    geciciDegisken = baslangic;
    while(geciciDegisken != NULL)
    {
        sonrakiNode = geciciDegisken->sonraki;
        geciciDegisken->sonraki = oncekiDugum;
        oncekiDugum = geciciDegisken;
        geciciDegisken = sonrakiNode;
    }
    baslangic = oncekiDugum;
}

void yazdir()
{
    if(baslangic == NULL)
    {
        printf("\n Listede Hic dugum yok, lutfen dugum ekleyin");
    }
    else
    {
        geciciDegisken = baslangic;
        printf("\n********************\n");
        while(geciciDegisken->sonraki != NULL)
        {
            printf("%d ", geciciDegisken->veri);
            geciciDegisken = geciciDegisken->sonraki;
        }
        printf("%d ", geciciDegisken->veri);
        printf("\n");
    }

}

int main(){

sonaEkle(30);
sonaEkle(40);
sonaEkle(50);
sonaEkle(60);
yazdir();
tersCevir();
yazdir();
}
