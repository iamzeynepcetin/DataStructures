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
node*birlestir(node*agac1,node*agac2){
while(agac2->data!=NULL){
if(agac1->data<agac2->data){
    agac1->sag=ekle(agac1->sag,agac2->data);
    return agac1;
    }
    agac1->sol=ekle(agac1->sol,agac2->data);
    return agac1;
}
}





void dolas(node*agac){
if(agac==NULL)
    return;
dolas(agac->sol);
printf("%d ",agac->data);
dolas(agac->sag);
return;
}
int main()
{
node*agac1=NULL;
agac1=ekle(agac1,12);
agac1=ekle(agac1,200);
agac1=ekle(agac1,1);
agac1=ekle(agac1,10);
//dolas(agac1);
node*agac2=NULL;
agac2=ekle(agac2,5);
agac2=ekle(agac2,20);
agac2=ekle(agac2,100);
agac2=ekle(agac2,70);
//dolas(agac2);
birlestir(agac1,agac2);
dolas(agac1);


}
