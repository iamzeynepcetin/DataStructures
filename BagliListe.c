#include <stdio.h>
#include <stdlib.h> //malloc kullanabilmek icin kullanmak gerek

struct n{
 int x;
 struct n * next;
};

typedef struct n node; //node isimli bir n struct yapisi

node* ekle(node* root, int x){ //bu fonksiyon yeni gelen elemanlari listin sonua ekler.
    if(root == NULL){ //listte eleman yoksa calisir.
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL; //onemli
        root = temp;
        return root;
    }else{
        node* iter = root;
        while(iter->next != NULL){ //Burada iteratorun nexti kontrol etmesi onemli cunku iteri NULL bir degere atamak istemeyiz.
            iter = iter->next;
        }//son dugume gelindi
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL;
        iter->next = temp;
        return root;
    }
}

node * sil(node *root, int x){
 node *temp;
 node *iter = root;
 if( root->x == x){ //ilk eleman aradigim degerse
  temp = root;
  root = root->next;
  free (temp);
  return root;
 }

 while ( iter->next != NULL && iter->next->x != x){ //null elemanina kadar x i bulmak icin gez
  iter = iter->next;
 }
 if ( iter->next == NULL){ //sayi bulunamadiysa
  printf( "Sayi bulunamadi!\n" );
  return root;
 }
 temp = iter->next; //silmek istedigimiz dugumu bulduysak
 iter->next = iter->next->next; // ya da iter->next = temp->next
 free (temp);                   //silmek istedigin dugumden sonrakine gec
 return root;
}

void bastir( node * root){ //bagli listeyi yazdiran fonksiyon
 while (root != NULL){
  printf("%d ", root->x);
  root = root -> next;
 }
 printf("\n");
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



int main ()
{

 node * root;
 root = NULL;

 root = ekle( root, 400);
 root = ekle( root, 40);
 root = ekle( root, 4);
 root = ekle( root, 450);
 root = ekle( root, 50);
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

