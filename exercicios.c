#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int val;
    struct _node *left;
    struct _node *right;
}TreeNode;

TreeNode *create_tree(int val){
    TreeNode *raiz = (TreeNode*)calloc(1, sizeof(TreeNode));

    raiz->val = val;
    raiz->left = NULL;
    raiz->right = NULL;

    return raiz;
}

TreeNode *insere_no(TreeNode *raiz, int val){
    if(raiz == NULL){

        TreeNode *aux =(TreeNode*)calloc(1, sizeof(TreeNode));
        aux->val = val;
        aux->left = NULL;
        aux->right = NULL;

        return aux;
    }else{
        if(val < raiz->val){
            raiz->left = insere_no(raiz->left, val);
        }else{
            raiz->right = insere_no(raiz->right, val);
        }
        return raiz;
    }
}

// 1) Considerando estruturas de árvores binárias que armazenam valores inteiros, implemente uma função que, 
//    dada uma árvore, retorne a quantidade de nós que guardam números pares. Essa função deve obedecer ao protótipo:

int qtd_even_node(TreeNode *raiz){
    if(raiz == NULL){
        return 0;
    }

    int count = 0;
    if(raiz->val % 2 == 0){
        count++;
    }

    count += qtd_even_node(raiz->left);
    count += qtd_even_node(raiz->right);

    return count;
}

// 2) Implemente uma função que retorne a quantidade de folhas de uma árvore binária. Essa função deve obedecer ao protótipo:

int qnt_leaf_tree(TreeNode *raiz){
    if(raiz == NULL){
        return 0;
    }else if(raiz->left == NULL && raiz->right == NULL){
        return 1;
    }else{
        return qnt_leaf_tree(raiz->left) + qnt_leaf_tree(raiz->right);
    }
}

// 3) Implemente uma função que retorne a quantidade de nós de uma árvore binária que possuem apenas um filho. Essa função deve obedecer ao protótipo:

int qnt_node_tree(TreeNode *raiz){
    int count = 0;
    if(raiz == NULL){
        return 0;
    }else if((raiz->left == NULL && raiz->right != NULL) || (raiz->left != NULL && raiz->right == NULL)){
        count++;
    }else{
        count += qnt_node_tree(raiz->left);
        count += qnt_node_tree(raiz->right);
    }
    return count;

}

// 4) Implemente uma função que compare se duas árvores binárias são iguais. Essa função deve obedecer ao protótipo:

// 6) Implemente uma função que retorne o número de nós folhas maiores do que um valor x, considerando uma árvore binária de busca. Essa função deve obedecer ao protótipo:

int nfolhas_maiores(TreeNode *raiz, int x){

    if(raiz == NULL){
        return 0;
    }
    int count = 0;

    if(raiz->left == NULL && raiz->right == NULL){
        if(raiz->val > x){
            count++;
        }
    }

    count += nfolhas_maiores(raiz->left, x);
    count += nfolhas_maiores(raiz->right, x);

    return count;
}

int main(){

    TreeNode *raiz = NULL;

    raiz = insere_no(raiz, 30);
    raiz = insere_no(raiz, 20);
    raiz = insere_no(raiz, 25);
    raiz = insere_no(raiz, 40);

    int qtd = qnt_node_tree(raiz);
    printf("Quantidade: %d\n", qtd);

    int even = qtd_even_node(raiz);
    printf("Even node: %d\n", even);

    int maior = nfolhas_maiores(raiz, 20);
    printf("Maiores: %d\n", maior);


}
