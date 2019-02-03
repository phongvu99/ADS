#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *tLeft;
    struct TreeNode *tRight;
} Node;

typedef struct _Tree{
    int height;
    int leaf;
} Tree;

void initTree(Tree *t, int n)
{
   t->height = ceil(log2(n));
   t->leaf = pow(2, t->height);
}

Node* initNode(int data)
{
    Node *node = (Node*) malloc(sizeof *node);
    node->val = data;
    node->tLeft = NULL;
    node->tRight = NULL;
    return node;
}

Node* BST(int a[], int low, int high)
{
    Node *root = NULL;
//    printf("Low: %d \n", low); printf("High: %d \n", high); // DEBUGGING PURPOSE
    int mid = (low+high)/2;
//    printf("Mid: %d \n", mid); // DEBUGGING PURPOSE
    if (low > high)
    {
//        printf("Low > High %d > %d \n", low, high); // DEBUGGING PURPOSE
        return NULL;
    }
    if (root == NULL)
    {
       root = initNode(a[mid]);
//       printf("Root value: %d \n", root->val); // DEBUGGING PURPOSE
    }
//    printf("Step 1 \n"); // DEBUGGING PURPPOSE
    root->tLeft = BST(a, low, mid-1); // Recursively construct the left subtree
//    printf("Step 2 \n"); // DEBUGGING PURPOSE
    root->tRight = BST(a, mid+1, high); // Recursively construct the right subtree
    return root;
}

Node* maxBST(Node *node)
{
    while(node->tRight != NULL)
    {
        node = node->tRight;
    }
    return node;
}

Node* insert(Node* node, int x) // "node" is the current node, x is the node that we want to insert.
{
    if (node == NULL)
    {
        node = initNode(x);
    }
    else if (x <= node->val)
        {
            node->tLeft = insert(node->tLeft, x); // insert to the left if x is less than node's key.
        }
    else
        {
            node->tRight = insert(node->tRight, x); // insert to the right if x is greater than node's key
        }
    return node;
}

Node* removeNode(Node *node, int x) // "node" is the current node, x is the node that we want to remove.
{
    if (node == NULL) // if the node does not exist or has became the new root.
    {
        return node;
    }
    if (node->val > x) //recursively looking for x.
    {
        node->tLeft = removeNode(node->tLeft, x); // go left if node's key is greater than x.
    }
    else if (node->val < x) //recursively looking for x.
    {
        node->tRight = removeNode(node->tRight, x); // go right if node's key is less than x.
    }
    else // this only happens when current node == x, which mean we have found the node to be deleted
    {
        // node with 1 child or no child.
        if (node->tLeft == NULL)
        {
            Node *temp = node->tRight;
            free(node);
            return temp;
        }
        else if (node->tRight == NULL)
        {
            Node *temp = node->tLeft;
            free(node);
            return temp;
        }
        else // node with 2 child.
        {
            Node *temp = maxBST(node->tLeft); // find max value of the left subtree.
            node->val = temp->val;
            node->tLeft = removeNode(node->tLeft, temp->val);
        }
    }
    return node;
}

void preorder(Node *node)
{
    if (node != NULL)
    {
        printf("   %d", node->val);
        preorder(node->tLeft);
        preorder(node->tRight);
    }
}

void inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->tLeft);
        printf("   %d", node->val);
        inorder(node->tRight);
    }
}

void postorder(Node *node)
{
    if (node != NULL)
    {
        postorder(node->tLeft);
        postorder(node->tRight);
        printf("   %d", node->val);
    }
}

void find(Node *node, int x)
{
    if (node == NULL) // if the node does not exist or has been removed.
    {
        printf("\n   Too bad, your node was not found");
        return;
    }
    if (node->val > x) //recursively looking for x.
    {
        find(node->tLeft, x); // go left if node's key is greater than x.
    }
    else if (node->val < x) //recursively looking for x.
    {
        find(node->tRight, x); // go right if node's key is less than x.
    }
    else
    {
        printf("\n   Found it! \n");
        printf("\n   Your node is: %d \n", node->val);
    }
}

int main()
{
    int a[100], temp, start, end, n = 0;
    bool check = true;
    Node* node = NULL;
    Tree *t, p;
    t = &p;
    printf("\n   Enter total number of node in BST: ");
    scanf("%d", &n);
    start = 0; end = n-1;
    initTree(t, n);
    printf("\n   Tree height: %d \n", t->height);
    printf("\n   Tree leaf nodes: %d \n", t->leaf);
    for (int i = 0; i < n; i++)
    {
        printf("\n   Enter the value of %d Node : ",i+1);
        scanf("%d", &a[i]);
    }
    while (check) // Cocktail shaker in TT5. Neat!
    {
        check = false;
        for (int i = start+1; i <= end; i++)
        {
            if (a[i-1] > a[i])
            {
                temp = a[i-1];
                a[i-1] = a[i];
                a[i] = temp;
                check = true;
            }
        }
        if (check == false)
        {
            break;
        }
        check = false;
        end--;
        for(int b = end; b > start; b--)
        {
            if (a[b-1] > a[b])
            {
                temp = a[b-1];
                a[b-1] = a[b];
                a[b] = temp;
                check = true;
            }
        }
        start++;
    }
    while (t->leaf != n) // make sure the number of node == the number of leaf node
    {
        for (int i = n; i < t->leaf; i++)
        {
            a[i] = a[n-1];
            n++;
        }
    }
    printf("\n   Your array: ");
    for (int i = 0; i < t->leaf; i++)
    {
        printf("   %d", a[i]);
    }
    printf("\n   ");
    node = BST(a, 0, n-1); // Creating the BST.
    printf("\n   Add node (0:NO) (1:YES): ");
    scanf("%d", &n);
    if (n)
    {
        printf("\n   Enter number of new node: ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("\n   Enter value of the node: ");
            scanf("%d", &a[i]);
            node = insert(node, a[i]);
        }
    }
    printf("\n   Remove node (0:NO) (1:YES): ");
    scanf("%d", &n);
    if (n)
    {
        printf("\n   Enter number of node you want to remove: ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("\n   Enter value of the node: ");
            scanf("%d", &a[i]);
            node = removeNode(node, a[i]);
        }
    }
    printf("\n   BST created! \n");
    printf("\n   Pre-order traversal: \n\n"); preorder(node); printf("\n");
    printf("\n   In-order traversal: \n\n"); inorder(node); printf("\n");
    printf("\n   Post-order traversal: \n\n"); postorder(node); printf("\n");
    printf("\n   Search node (0:NO) (1:YES): ");
    scanf("%d", &n);
    if (n)
    {
        printf("\n   Enter number of node you want to find: ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("\n   Enter value of the node: ");
            scanf("%d", &a[i]);
            find(node, a[i]);
        }
    }
    printf("\n   Thank you for using! \n");
    return 0;
}



