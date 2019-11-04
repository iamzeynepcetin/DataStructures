#include<stdio.h>
#include<stdlib.h>

#define enfazla 5

struct stack{
int elemansayisi;
int eleman[enfazla];
}stack;

int koy(int veri){
if(stack.elemansayisi>=enfazla){
    printf("aq stagi dolu\n");
}
else{
stack.eleman[stack.elemansayisi]=veri;
stack.elemansayisi++;

}
}

void bastir(){
for(int i=0;i<=enfazla-1;i++){
    printf("\n %d\n",stack.eleman[i]);
    }
}

int al(){
return stack.eleman[--stack.elemansayisi];
}

void temizle(){
stack.eleman[stack.elemansayisi]=NULL;
}

int main(){
struct stack s;
koy(10);
koy(20);
koy(30);
koy(40);
koy(50);
bastir();
printf("\nalinan eleman:\n%d",al());
temizle();
printf("\nalinan eleman:\n%d",al());
temizle();
printf("\nalinan eleman:\n%d",al());
temizle();
printf("\nlistenin yeni hali");
bastir();
}
