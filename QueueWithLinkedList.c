#include <stdio.h>
#include <stdlib.h>
struct n{
int data;
struct n *next;

};
typedef struct n node;
node *root=NULL;
node *son=NULL;
void enqueu(int x){
if(root==NULL){
    root=(node*)malloc(sizeof(node));
    root->data=x;
    root->next=NULL;
    son=root;
}else{
son->next=(node*)malloc(sizeof(node));
son->next->data=x;
son=son->next;
son->next=NULL;


}
}
 int dequeue(){
     if (root==NULL){
     printf("liste boss");
     return -1;
     }
     int rvalue=root->data;
     node*temp=root;
     root=root->next;
     free(temp);
     return rvalue;
 }
void bastir(){
    if(root == NULL){
        printf("Bos kuyruk\n");
        return;
    }else{
       node*iter = root;
       while(iter != NULL){
        printf("%d ", iter->data);
        iter = iter->next;
       }
       printf("\n");
       return;
    }

}


int main()
{
enqueu(10);
enqueu(20);
enqueu(30);
dequeue();
dequeue();
bastir();

}
