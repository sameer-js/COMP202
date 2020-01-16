#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/* Printing nodes by in-order traversal (LNR) */
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;

    // recurring left subtree
    printInorder(node->left);

    // visiting node
    cout << node->data << " ";

    // recurring right subtree
    printInorder(node->right);
}

/* Printing nodes by pre-order traversal (NLR) */
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;

    // visiting node
    cout << node->data << " ";

    // recurring left subtree
    printPreorder(node->left);

    // recurring right subtree
    printPreorder(node->right);
}

/* Printing nodes by post-order traversal (LRN) */
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;

    // recurring left subtree
    printPostorder(node->left);

    // recurring right subtree
    printPostorder(node->right);

    //visiting node
    cout << node->data << " ";
}

/* Program to test above functions*/
int main()
{
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    cout << "\nInorder traversal of the given binary tree is :- \n";
    printInorder(root);

    cout << "\nPreorder traversal of the given binary tree is :- \n";
    printPreorder(root);

    cout << "\nPostorder traversal of the given binary tree is :- \n";
    printPostorder(root);

    cout << "\n \n Time Complexity for all Traversals is given by O(n), since all the algorithms finish in Linear Time." << endl;
    cout << " 'n' being the number of nodes in the tree." << endl;

    return 0;
}
