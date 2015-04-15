///// USE BFS


#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

class Tree
{
public:
    struct node *root;
    Tree();
    struct node *insert(struct node *root, int data);
    void print(struct node *root);
    struct node *toDLL(struct node *root);
    void printDLL(struct node *head);
};

void Tree::printDLL(struct node *head)
{
    if(head==NULL)
        return;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
}

Tree::Tree()
{
    root = NULL;
}

struct node* Tree::insert(struct node *root, int data)
{
    if(root==NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if(root->data > data)
    {
        root->left = insert(root->left, data);
    }
        
    else
    {   
        root->right = insert(root->right, data);
    }
        

    return root;
}

void Tree::print(struct node *root)
{
    if(root==NULL)
        return;
    else
    {
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
}

struct node* Tree::toDLL(struct node *root)  
{

    struct node *head = NULL;
    head = root;
    queue<struct node *> q;

    if(root->left!=NULL)
        q.push(root->left);

    if(root->right!=NULL)
        q.push(root->right);

    head->left = NULL;

    struct node *temp=NULL;

    while(!q.empty())
    {   
        temp = q.front();  
        q.pop();

        if(temp->left!=NULL)
            q.push(temp->left);

        if(temp->right!=NULL)
            q.push(temp->right);

        head->right = temp;
        temp->left = head;
        head = temp;
    }
    return root;
}

int main()
{
    Tree tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 11);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 5);
    cout<<"Printing Inorder traversal: ";
    tree.print(tree.root);
    cout<<endl;
    tree.root = tree.toDLL(tree.root);
    cout<<"Printing doubly linked list: ";
    tree.printDLL(tree.root);
    cout<<endl;
    return 0;
}