struct node *append(struct node *a,struct node *b)
{
    if(a==NULL) 
        return b;

    if(b==NULL) 
        return a;

    struct node *aLeft=a->left;
    struct node *bLeft=b->left;
    aLeft->right=b;
    b->left=aLeft;
    a->left=bLeft;
    bLeft->right=a;
    return a;
}
 
struct node *TreeToList(struct node *root)
{
    if(root=NULL) 
       return NULL;
    struct node *aList=TreeToList(root->left);
    struct node *bList=TreeToList(root->right);
    root->left=root;
    root->right=root;
    aList=append(aList,root);
    aList=append(aList,bList);
    return aList;
}
