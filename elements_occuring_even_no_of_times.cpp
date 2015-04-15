//Create a BST and and keep inserting elements from the array thereby increasing the count of 
//each number. Finally do an inorder traversal with a check if the count is even or not 
//and print the number if the count of that number is even.

#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data; 
    int count;
    struct node *left;
    struct node *right;
};

struct node *Insert(struct node *root, int value)
{
    if(root==NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = value;
        temp->count = 1;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    struct node *temp;
    if(root->data > value)
    {
        temp = Insert(root->left,value);
        root->left = temp;
    }
        
    else if(root->data < value)
    {
        temp = Insert(root->right, value);
        root->right = temp;
    }
        
    else
    {
        root->count = root->count + 1;
    }

}

void Inorder(struct node *root)
{
    if(root==NULL)
        return;

    Inorder(root->left);
    if((root->count)%2==0)
         cout<<root->data<<" ";
    Inorder(root->right);
}


int main()
{

    int n;
    cin>>n;
    int a[n];
    int i;
    struct node *root = NULL;
    root = (struct node *)malloc(sizeof(struct node));
    root->left = NULL;
    root->right = NULL;

    for(i=0; i<n; i++)
    {
        cin>>a[i];
        if(i==0)
        {
            root->data = a[i];
            root->count = 1;
            continue;
        }
        root = Insert(root, a[i]);
    }
    
    Inorder(root);
    cout<<endl;

    return 0;
}




///////////////////////////////////////////////////////////////////////////
//Another Method using vector and sorting/////////////////////////////////
//////////////////////////////////////////////////////////////////////////

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int i;
    for(i=0; i<n; i++)
    {
        int inp;
        cin>>inp;
        v.push_back(inp);
    }
        
    sort(v.begin(), v.end());

    vector<int>::iterator it;
    for(it=v.begin(); it!=v.end(); it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;

    
    int x = v[0];
    int count = 1;
    for(it=v.begin()+1; it!=v.end(); it++)
    {
        if((*it)==x)
            count++;
        else
        {
            if(count%2==0)
                cout<<x<<" ";
            x = (*it);
            count = 1;
        }
    }


    return 0;
}

*/