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

void ekle( node * r, int x){ //bagli listeye eleman ekleyen fonksiyon
 while( r -> next != NULL){ //r->nexte dikkat et .. r nin gosterdiginin sonraki null olmali
  r =r -> next;
 }
 r -> next = ( node *) malloc (sizeof (node ) );
 r -> next -> x = x;
 r -> next -> next = NULL;

}

node * ekleSirali ( node * r, int x){
 if( r == NULL){ //linklist bossa
  r = (node *) malloc ( sizeof ( node) );
  r -> next = NULL;
  r -> x = x;
  return r;
 }
 if(r -> x > x){ //ilk elemandan kucuk eleman ekleme(basa eleman ekleme)
                //root degisiyor
  node * temp = ( node * ) malloc ( sizeof ( node ) );
  temp -> x = x;
  temp -> next = r;
  r = temp;
  return temp;
 }
 node * iter = r; //linklist bos degil ve basa eleman eklemiyorum
 while( iter -> next != NULL && iter -> next -> x < x ){ //araya,sona eleman ekleme
  iter = iter -> next;
 }

 node * temp = (node*)malloc(sizeof(node));
 temp->next = iter->next;
 iter->next = temp;
 temp->x = x;
 return r;

}

node * sil(node *r, int x){
 node *temp;
 node *iter = r;
 if( r->x == x){ //ilk eleman aradigim degerse
  temp = r;
  r = r->next;
  free (temp);
  return r;
 }

 while ( iter->next != NULL && iter->next->x != x){ //null elemanina kadar x i bulmak icin gez
  iter = iter->next;
 }
 if ( iter->next == NULL){ //sayi bulunamadiysa
  printf( "Sayi bulunamadi!\n" );
  return r;
 }
 temp = iter->next; //silmek istedigimiz dugumu bulduysak
 iter->next = iter->next->next; // ya da iter->next = temp->next
 free (temp);                   //silmek istedigin dugumden sonrakine gec
 return r;
}

int main ()
{

 node * root;
 root = NULL;

 root = ekleSirali( root, 400);
 root = ekleSirali( root, 40);
 root = ekleSirali( root, 4);
 root = ekleSirali( root, 450);
 root = ekleSirali( root, 50);
 bastir(root);
 root = sil( root, 50);
 bastir(root);
 root = sil( root, 999);
 bastir(root);
 root = sil( root, 4);
 bastir(root);
 root = sil( root, 450);
 bastir(root);
}
