#include <stdio.h>
#include <stdlib.h>
struct n {
int data;
struct n*sol;
struct n*sag;
};
typedef struct n node;
int x;

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


void enbuyukeleman(node*agac){
if(agac==NULL)
    return;
while(agac->sag!=NULL){
        agac=agac->sag;
       }
       printf("en buyuk eleman=%d",agac->data);
}


void enkucukeleman(node*agac){
if(agac==NULL)
    return;
while(agac->sol!=NULL){
    agac=agac->sol;
}
 printf("\nen kucuk eleman=%d",agac->data);

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
enbuyukeleman(agac);
enkucukeleman(agac);
}
