#include <stdio.h>
#include <stdlib.h>
struct n {
int data;
struct n*sol;
struct n*sag;
};
typedef struct n node;


node* ekle(node*agac,int x){
if(agac==NULL){
    node*root=(node*)malloc(sizeof(node));
    root->sol=NULL;
    root->sag=NULL;
    root->data=x;
    return root;
}if(agac->data<x){
    agac->sag=ekle(agac->sag,x);
    return agac;
    }
    agac->sol=ekle(agac->sol,x);
    return agac;
}

void dugumsayisisag(node*agac){
int sayac=0;
if (agac==NULL)
    return;
while(agac->sag!=NULL){
sayac++;
agac=agac->sag;
}
printf("sagdaki dugum sayisi %d",sayac);
}


void dugumsayisisol(node*agac){
if(agac==NULL)
return;
int sayac=0;
while(agac->sol!=NULL){
 sayac++;
 agac=agac->sol;
}
printf("soldaki dugum sayisi=%d",sayac);
}

int main()
{
node*agac=NULL;
agac=ekle(agac,5);
agac=ekle(agac,16);
agac=ekle(agac,23);
agac=ekle(agac,45);
agac=ekle(agac,2);
agac=ekle(agac,12);
dugumsayisisag(agac);
dugumsayisisol(agac);
}
