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
void dolas(node*agac){
if(agac==NULL)
    return;
dolas(agac->sol);
printf("%d ",agac->data);
dolas(agac->sag);
return;
}
int bul(node*agac,int aranan){
if(agac==NULL)
    return -1;
if(agac->data==aranan)
    return 1;
if(bul(agac->sag,aranan)==1)
    return 1;
if (bul(agac->sol,aranan)==1)
    return 1;
return -1;
}
int max(node*agac){
while(agac->sag!=NULL)
    agac=agac->sag;
return agac->data;
}
int min(node*agac){
while(agac->sol!=NULL)
      agac=agac->sol;
      return agac->data;
      }
node*sil(node*agac,int x){
    if(agac==NULL) //agac nullsa null dondur
        return NULL;
    if (agac->data==x){//aradigim degeri buldum sagini solunu null yaptim
        if(agac->sol==NULL && agac->sag==NULL)//agacin solu ve sagi null
            return NULL;
    if(agac->sag!=NULL){//agacin solu null saginda degerler var
        agac->data=min(agac->sag);//sagindaki en kucuk degeri bul o degerin yerine koy
        agac->sag=sil(agac->sag,min(agac->sag)); //sonra o degeri agactan sil
        return agac;
    }                     //agacin sagi null solunda deger var
    agac->data=max(agac->sol);//soldaki en buyuk degeri bul o degerin yerine koy
    agac->sol=sil(agac->sol,max(agac->sol));//degeri agactan sil
    return agac;
    }
    if (agac->data<x){ //Deger henüz bulunmadi,deger agacin saginda
        agac->sag=sil(agac->sag,x);//xi agacin sagindaki agactan sil
        return agac;
    }
    agac->sol=sil(agac->sol,x);//deger henüz bulunmadi, x degeri büyükse sol agacta ara
    return agac;

}


int main()
{
node*agac=NULL;
agac=ekle(agac,12);
agac=ekle(agac,200);
agac=ekle(agac,1);
agac=ekle(agac,10);
dolas(agac);
printf("arama sonucu %d",bul(agac,100));
printf("arama sonucu %d",bul(agac,12));
printf("max value %d min %d ",max(agac),min(agac));
agac=sil(agac,12);
dolas(agac);
}
