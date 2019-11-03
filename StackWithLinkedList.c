#include <stdio.h>
#include <stdlib.h>

struct Node{
    int x;
    struct Node* next;
};
typedef struct Node node;

node* push(node* root, int x){
    if(root == NULL){ //Bos olmasi durumunu kontrol ediyoruz.
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = NULL;
        return temp;
    }
    else{ //sona eklemektense basa eklemek (algoritma analizine gore) daha avantajlidir.
        node* temp = (node*)malloc(sizeof(node));
        temp->x = x;
        temp->next = root;
        return temp;
    }
}

node* pop(node* root){
    if(root == NULL){
        printf("bos yigin.\n");
    }
    node* temp; //free() fonksiyonunu calistirmak icin silinen dugumun adresi gecici bir sure icin saklanmalý.
    printf("%d silindi.\n", root->x);
    temp = root;
    root = root->next;
    free(temp);
    return root;

}
void bastir(node*root){
while(root!=NULL){
        printf("%d ->",root->x);
        root=root->next;
        }
}
int main(){
    node* root = NULL;
    bastir(root);
    root = push(root, 10);
    root = push(root, 20);
    root = push(root, 30);
    root = push(root, 40);
    root = push(root, 50);
    bastir(root);
    root = pop(root);
    bastir(root);
    root = pop(root);
    bastir(root);

}
