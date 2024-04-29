#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int val;
    struct _node *left;
    struct _node *right;
}TreeNode;

TreeNode *insere_versao_1(TreeNode *raiz, int val){
    if(raiz == NULL){
        TreeNode *aux = (TreeNode*)calloc(1, sizeof(TreeNode));
        aux->val = val;
        aux->left = NULL;
        aux->right = NULL;

        return aux;
    }else{
        if(val < raiz->val){
            raiz->left = insere_versao_1(raiz->left, val);
        }else{
            raiz->right = insere_versao_1(raiz->right, val);
        }
        return raiz;
    }
}

void insere_versao_2(TreeNode **raiz, int val){
    if(*raiz == NULL){
        *raiz =(TreeNode*)calloc(1, sizeof(TreeNode));
        (*raiz)->val = val;
        (*raiz)->left = NULL;
        (*raiz)->right = NULL;
    }else{
        if(val < (*raiz)->val){
            insere_versao_2(&((*raiz)->left), val);
        }else{
            insere_versao_2(&((*raiz)->right), val);
        }
    }
}

TreeNode *busca_versao_1(TreeNode *raiz, int val){
    if(raiz){
        if(val == raiz->val){
            return raiz;
        }else if(val < raiz->val){
            return busca_versao_1(raiz->left, val);
        }else{
            return busca_versao_1(raiz->right, val);
        }

    }
    return NULL;
}

int altura(TreeNode *raiz){
    if(raiz == NULL){
        return -1;
    }else{
        int esq = altura(raiz->left);
        int dir = altura(raiz->right);
        if(esq > dir){
            return esq + 1;
        }else{
            return dir + 1;
        }
    }
}

int quantidade_nos(TreeNode *raiz){
    if(raiz == NULL){
        return 0;
    }else{
        return 1 + quantidade_nos(raiz->left) + quantidade_nos(raiz->right);
    }
}

int quantidade_nos_pares(TreeNode *raiz){

    if(raiz == NULL){
        return 0;
    }
    
    int count = 0;

    if(raiz->val % 2 == 0){
        count++;
    }

    count += quantidade_nos_pares(raiz->left);
    count += quantidade_nos_pares(raiz->right);

    return count;

}

int quantidade_folhas(TreeNode *raiz){
    if(raiz == NULL){
        return 0;
    }else if(raiz->left == NULL && raiz->right == NULL){
        return 1;
    }else{
        return quantidade_folhas(raiz->left) + quantidade_folhas(raiz->right);
    }
}

TreeNode *remover(TreeNode *raiz, int chave){
    if(raiz == NULL){ // se a raiz nao tiver elementos
        printf("Valor nao encontrado.\n");
        return NULL;
    }else{
        if(raiz->val == chave){ // se o valor da raiz for igual ao valor a ser retirado
            if(raiz->left == NULL && raiz->right == NULL){ // se o no q possui o valor a ser retirado nao tiver filhos
                free(raiz);
                return NULL;
            }else{
                if(raiz->left != NULL && raiz->right != NULL){
                    TreeNode *aux = raiz->left;
                    while(raiz->right != NULL){
                        aux = aux->right;
                    }
                    raiz->val = aux->val;
                    aux->val = chave;
                    raiz->left = remover(raiz->left, chave);
                    return raiz;

                }else{
                    TreeNode *aux;
                    if(raiz->left != NULL){
                        aux = raiz->left;
                    }else{
                        aux = raiz->right; 
                    }
                    free(raiz);
                    return aux;
                }

            }
        }else{
            if(chave < raiz->val){ // se o elemento a ser retirado for menor q a raiz
                raiz->left = remover(raiz->left, chave);
            }else{
                raiz->right = remover(raiz->right, chave);
            }
            return raiz;
        }
    }
}

void imprime_versao_1(TreeNode *raiz){
    if(raiz){
        printf("%d ", raiz->val);
        imprime_versao_1(raiz->left);
        imprime_versao_1(raiz->right);

    }
}

void imprime_versao_2(TreeNode *raiz){
    if(raiz){
        imprime_versao_2(raiz->left);
        printf("%d ", raiz->val);
        imprime_versao_2(raiz->right);

    }
}


int main(){

    TreeNode *raiz = NULL;
    TreeNode *aux = NULL;

    // raiz = insere_versao_1(raiz, 50);
    // raiz = insere_versao_1(raiz, 25);
    // raiz = insere_versao_1(raiz, 100);
    // raiz = insere_versao_1(raiz, 30);

    insere_versao_2(&raiz, 583);
    insere_versao_2(&raiz, 245);
    insere_versao_2(&raiz, 123);
    insere_versao_2(&raiz, 389);
    insere_versao_2(&raiz, 278);
    insere_versao_2(&raiz, 731);
    insere_versao_2(&raiz, 684);
    insere_versao_2(&raiz, 893);

    imprime_versao_1(raiz);
    puts("");
    imprime_versao_2(raiz);

    aux = busca_versao_1(raiz, 278);
    printf("\nValor %d encontrado.", aux->val);

    int alt = altura(raiz);
    printf("\n%d", alt);

    int tamanho = quantidade_nos(raiz);
    printf("\n%d", tamanho);

    int folhas = quantidade_folhas(raiz);
    printf("\n%d", folhas);

    puts("");
    imprime_versao_2(raiz);
    puts("\nRemovendo 389:");
    raiz = remover(raiz, 389);
    imprime_versao_2(raiz); 

}