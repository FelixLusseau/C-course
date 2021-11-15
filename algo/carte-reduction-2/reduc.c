# include <stdio.h>
# include <stdlib.h>

/* int main(){
    int M=1000000;
    int N=0;
    scanf("%i", &N);
    int tab[M];
    for (int i=0; i<M; i++){
        tab[i]=0;
    }
    printf("\n");
    int numero=0;
    for (int i=0; i<N; i++){
        scanf("%i", &numero);
        if (tab[numero]!=0){
            printf("%i\n", numero);
            return 0;
            }
        tab[numero]=numero;
    }
    printf("-1\n");
    return 0;
} */


typedef struct node
{
    unsigned long long int key;
    struct node *left;
    struct node *right;    
} node;

void addNode(node **tree, unsigned long long int key)
{
    node *tmpNode;
    node *tmpTree = *tree;

    node *elem = malloc(sizeof(node));
    if (elem==NULL) return ;
    elem->key = key;
    elem->left = NULL;
    elem->right = NULL;

    if(tmpTree)
    do
    {
        tmpNode = tmpTree;
        if(key > tmpTree->key )
        {
            tmpTree = tmpTree->right;
            if(!tmpTree) tmpNode->right = elem;
        }
        else
        {
            tmpTree = tmpTree->left;
            if(!tmpTree) tmpNode->left = elem;
        }
    }
    while(tmpTree);
    else  *tree = elem;
}

int searchNode(node *tree, unsigned long long int key)
{
    while(tree)
    {
        if(key == tree->key) return 1;

        if(key > tree->key ) tree = tree->right;
        else tree = tree->left;
    }
    return 0;
}

void printTree(node *tree)
{
    if(!tree) return;

    if(tree->left)  printTree(tree->left);

    printf("Cle = %lld\n", tree->key);

    if(tree->right) printTree(tree->right);
}

void clearTree(node **tree)
{
    node *tmpTree = *tree;

    if(!tree) return;

    if(tmpTree->left)  clearTree(&tmpTree->left);

    if(tmpTree->right) clearTree(&tmpTree->right);

    free(tmpTree);      

    *tree = NULL;
}

int main(){
    node * arbre=NULL;
    unsigned long long int N=0;
    scanf("%lli", &N);    
    unsigned long long int numero=0;
    for (unsigned long long int i=0; i<N; i++){
        scanf("%lli", &numero);
        if (searchNode(arbre, numero)){
            printf("%lli\n", numero);
            clearTree(&arbre);
            return 0;
        }
        addNode(&arbre, numero);
    }
    printf("-1\n");
    clearTree(&arbre);
    return 0;
}