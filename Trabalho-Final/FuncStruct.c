#include "header.h"
int contextonum=1;

struct node* newNode(char* item,int number)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct posicoes* temp2=(struct posicoes*)malloc(sizeof(struct node));
    strcpy(temp->key, item);
    temp->tail=temp2;
    temp2->pos=number;
    temp2->next= NULL;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node, char* key,int number){
    strtobase_u8(key,key);

    if (node == NULL)
        return newNode(key,number);

    if(!strcmp(key,node->key)){
        struct posicoes* temp=(struct posicoes*)malloc(sizeof(struct node));
        temp->pos=number;
        temp->next=node->tail;
        node->tail=temp;
        return node;
    }
    if (strlen(key) <= strlen(node->key))
        node->left = insert(node->left, key,number);
    else if (strlen(key) >= strlen(node->key))
        node->right = insert(node->right, key,number);


    return node;
}
void byte_palavra(struct node* node, char* key, int k, FILE* ficheiro){
    if (node != NULL) {

        byte_palavra(node->left, key, k, ficheiro);
        if (k==1){
            if (!strcmp(key, node->key)){
                struct posicoes* ptr= node->tail;
                while (ptr){
                    printf("%dº contexto: ",contextonum);
                    contextonum++;
                    mostra_contexto(ptr->pos,ficheiro);
                    ptr=ptr->next;}
            }
        }else{
            if (compara(key, node->key)){
                struct posicoes* ptr= node->tail;
                while (ptr){
                    printf("%dº contexto: ",contextonum);
                    contextonum++;
                    mostra_contexto(ptr->pos,ficheiro);
                    ptr=ptr->next;}
            }
        }
        byte_palavra(node->right, key, k, ficheiro);
    }
}

