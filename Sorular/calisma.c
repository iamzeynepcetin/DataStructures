#include <stdio.h>
#include <stdlib.h> //malloc kullanabilmek icin kullanmak gerek

struct n{
 int x;
 struct n * next;
};

typedef struct n node; //node isimli bir n struct yapisi


void bastir( node * r){ //bagli listeyi yazdiran fonksiyon
 while (r != NULL){
  printf("%d ", r->x);
  r = r -> next;
 }
 printf("\n");
}

void ekle( node * r, int x){//bagli listeye eleman ekleyen fonksiyon
 while( r -> next != NULL){ //r->nexte dikkat et .. r nin gosterdiginin sonraki null olmali
  r =r -> next;
 }
 r -> next = ( node *) malloc (sizeof (node ) );
 r -> next -> x = x;
 r -> next -> next = NULL;

}

void birlestir(node*r ,node* x){
while(r->next!=NULL){
    r=r->next;
}
if (r->next==NULL){
    r->next=x;
    x=x->next;
}

}




int main ()
{

 node * root;
 root=NULL;
 root = (node*)malloc(sizeof(node));
 root->x=50;
 root->next=NULL;

 ekle(root,500);
 ekle(root,500);
 bastir(root);


 node * diger;
 diger=NULL;
 diger = (node*)malloc(sizeof(node));
 diger->x=10;
 diger->next=NULL;


 ekle(diger,20);
 ekle(diger,30);
 bastir(diger);
 birlestir(root,diger);
 bastir(root);


}
