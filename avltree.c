#include <stdio.h>
#include <stdlib.h>

typedef struct _AVLTreeNode{
    int val;
    struct _AVLTreeNode *left;
    struct _AVLTreeNode *right;
    int altura;
}AVLTreeNode;

AVLTreeNode *create_node(int x){
    AVLTreeNode *raiz = (AVLTreeNode*)calloc(1, sizeof(AVLTreeNode));
    if(raiz){
        raiz->val = x;
        raiz->left = NULL;
        raiz->right = NULL;
        raiz->altura = 0;
    }else{
        printf("Erro ao criar novo node.\n");
    }
    return raiz;
}

int maior(int a, int b){
    return (a > b) ? a : b;
}

int altura_no(AVLTreeNode *raiz){
    if(raiz == NULL){
        return -1;
    }else{
        return raiz->altura;
    }
}

int fator_de_balanceamento(AVLTreeNode *raiz){
    if(raiz){
        return altura_no(raiz->left) - altura_no(raiz->right);
    }else{
        return 0;
    }
}

AVLTreeNode *rotacao_esquerda(AVLTreeNode *raiz){
    AVLTreeNode *y;
    AVLTreeNode *f;

    y = raiz->right;
    f = y->left;

    y->left = raiz;
    raiz->right = f;

    raiz->altura = maior(altura_no(raiz->left), altura_no(raiz->right)) + 1;
    y->altura = maior(altura_no(y->left), altura_no(y->right)) + 1;

    return y; // nova raiz
}

AVLTreeNode *rotacao_direita(AVLTreeNode *raiz){
    AVLTreeNode *y;
    AVLTreeNode *f;

    y = raiz->left;
    f = y->right;

    y->right = raiz;
    raiz->left = f;

    raiz->altura = maior(altura_no(raiz->left), altura_no(raiz->right)) + 1;
    y->altura = maior(altura_no(y->left), altura_no(y->right)) + 1;

    return y; // nova raiz


}

AVLTreeNode *rotacao_direita_esquerda(AVLTreeNode *raiz){

    raiz->right = rotacao_direita(raiz->right);
    return rotacao_esquerda(raiz);

}

AVLTreeNode *rotacao_esquerda_direita(AVLTreeNode *raiz){
    
    raiz->left = rotacao_esquerda(raiz->left);
    return rotacao_direita(raiz);

}

