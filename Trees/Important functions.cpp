#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int maxHeight(struct node *root);
void deleteTree(struct node *node);
int size(struct node *node);
void mirror(struct node *node);
void inorder(struct node *node);
void preorder(struct node *node);
void postorder(struct node *node);
void printAllPathsFromRootToLeaf(struct node *node, vector<int>& v);
struct node * lowestCommonAncestor(struct node *root, int n1, int n2);
void levelOrder(struct node *root, queue<struct node *>& q);
void spiralOrder(struct node *root, stack<struct node *>& s1, stack<struct node *>& s2);
int minVal(struct node *root);
int maxVal(struct node *root);
bool isBST(struct node *root);
bool childrenSumProperty(struct node *node);
void convertArbitraryBinaryTreeToHoldChildremSumProperty(struct node *node);
int diameter(struct node *node);
bool isHeightBalanced(struct node *node);
bool check(Node *root,int max, int lvl); // checking if all the leaf nodes are at the same level.


struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int val)
{
    struct node *node=(struct node *)malloc(sizeof(struct node));
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int abs(int a)
{
    if(a<0)
        return -a;
    else
        return a;
}
int max(int a, int b, int c)
{
    int max;
    if(a>b)
        max=a;
    else
        max=b;
    
    if(max>c)
        return max;
    else
        return c;
}

bool check(Node *root,int max, int lvl)
{
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)
    {
        if(lvl != max-1)
            return false;
        else
            return true;
    }
    else
    {
        return   (check(root->left,max,lvl+1)&&check(root->left,max,lvl+1)); 
    }
}

int maxHeight(struct node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lheight = maxHeight(root->left);
        int rheight = maxHeight(root->right);
        
        if(lheight>rheight)
            return (lheight+1);
        else
            return (rheight+1);
    }
}

void deleteTree(struct node *node)
{
    if(node==NULL)
        return;
    
    //Delete using postorder traversal because before deleting a node its childrens should be deleted;
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}

int size(struct node *node)
{
    if(node==NULL)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));
}

void mirror(struct node *node)
{
    if(node==NULL)
        return;
    
    mirror(node->left);
    mirror(node->right);
    
    struct node *temp=node->left;
    node->left=node->right;
    node->right=temp;
        
}

void inorder(struct node *node)
{
    if(node==NULL)
        return;
    
    inorder(node->left);
    cout<<node->data<< " ";
    inorder(node->right);
}

void preorder(struct node *node)
{
    if(node==NULL)
        return;
    
    cout<<node->data<< " ";
    inorder(node->left);
    inorder(node->right);
}

void postorder(struct node *node)
{
    if(node==NULL)
        return;
    
    inorder(node->left);
    inorder(node->right);
    cout<<node->data<< " ";
}

void printAllPathsFromRootToLeaf(struct node *node, vector<int>& v)
{
    if(node==NULL)
        return;
    
    v.push_back(node->data);
    
    if(node->left==NULL && node->right==NULL)
    {
        if(v.size()==0)
            return;
        else
        {
            vector<int>::iterator it;
            for(it=v.begin(); it!=v.end(); it++)
                cout<<*it<<" ";
            cout<<endl;
        }
            
    }
    else
    {
        
        printAllPathsFromRootToLeaf(node->left, v);
        v.pop_back();
        printAllPathsFromRootToLeaf(node->right, v);
        v.pop_back();
        
    }
}

struct node * lowestCommonAncestor(struct node *root, int n1, int n2)
{

    if (root == NULL) return NULL;
 
    // If both n1 and n2 are greater than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lowestCommonAncestor(root->left, n1, n2);
 
    // If both n1 and n2 are smaller than root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lowestCommonAncestor(root->right, n1, n2);
 
    return root;
}    

void levelOrder(struct node *root, queue<struct node *>& q) // using a queue and doing bfs
{
    q.push(root);
    
    while(!q.empty())
    {
        struct node *temp=(struct node *)q.front();
        q.pop();
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            q.push(temp->left);
            q.push(temp->right);
        }
        
    }
}

void spiralOrder(struct node *root, stack<struct node *>& s1, stack<struct node *>& s2) // Done using 2 stacks
{
    s1.push(root);
    int i=0;
    while(!(s1.empty() && s2.empty()))
    {
        while(!s1.empty())
        {
            struct node *temp = s1.top();
            s1.pop();
            if(temp!=NULL)
            {
                cout<<temp->data<<" ";
                s2.push(temp->left);
                s2.push(temp->right);
            }   
        }
        
        while(!s2.empty())
        {
            struct node *temp = s2.top();
            s2.pop();
            if(temp!=NULL)
            {
                cout<<temp->data<<" ";
                s1.push(temp->right);
                s1.push(temp->left);
            }
        }
    }
}

int minVal(struct node *root)
{
    if(root->left==NULL)
        return root->data;
    
    return(minVal(root->left));
}

int maxVal(struct node *root)
{
    if(root->right==NULL)
        return root->data;
    
    return(maxVal(root->right));
}

bool isBST(struct node *root)
{
    if(root==NULL)
        return true;
    if(root->left!=NULL && maxVal(root->left) > root->data)
        return false;
    if(root->right!=NULL && minVal(root->right) < root->data)
        return false;
    if(!isBST(root->left) || !isBST(root->right))
        return false;
    return true;
}

/*

isBST-----------------------------------------------

(Using In-Order Traversal)
Thanks to LJW489 for suggesting this method.
1) Do In-Order Traversal of the given tree and store the result in a temp array.
3) Check if the temp array is sorted in ascending order, if it is, then the tree is BST.

Time Complexity: O(n)

We can avoid the use of Auxiliary Array. While doing In-Order traversal, we can keep track of previously visited node. 
If the value of the currently visited node is less than the previous value, then tree is not BST. 

bool isBST(struct node* root)
{
    static struct node *prev = NULL;
     
    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
          return false;
 
        // Allows only distinct valued nodes 
        if (prev != NULL && root->data <= prev->data)
          return false;
 
        prev = root;
 
        return isBST(root->right);
    }
 
    return true;
}

*/

bool childrenSumProperty(struct node *node)
{
    if(node->left==NULL && node->right==NULL)
        return true;
    if(node->left==NULL && node->data!=node->right->data)
        return false;
    if(node->right==NULL && node->data!=node->left->data)
        return false;
    if(node->data != node->left->data + node->right->data)
        return false;
    
    if((node->data == node->left->data + node->right->data) && 
       childrenSumProperty(node->left) && 
       childrenSumProperty(node->right))
        return true;
    else
        return false;
    
}

void convertArbitraryBinaryTreeToHoldChildremSumProperty(struct node *node)
{
    if(node->left==NULL && node->right==NULL)
        return;
    convertArbitraryBinaryTreeToHoldChildremSumProperty(node->left);
    convertArbitraryBinaryTreeToHoldChildremSumProperty(node->right);
    
    if(node->left==NULL && node->data != node->right->data)
        node->data = node->right->data;
    
    if(node->right==NULL && node->data != node->left->data)
        node->data = node->left->data;
    
    if(node->data!=node->left->data + node->right->data)
        node->data=node->left->data + node->right->data;
            
    
}

int diameter(struct node *node)
{
    if(node==NULL)
        return 0;
    
    return max(diameter(node->left), diameter(node->right), maxHeight(node->left) + 1 + maxHeight(node->right));
}

bool isHeightBalanced(struct node *node)
{
    if(node == NULL)
        return true;
    

    if (isHeightBalanced(node->left) && isHeightBalanced(node->right) && 
        abs(maxHeight(node->left)-maxHeight(node->right))<=1)
        return true;
    
    return false;
}

int main() {
  struct node *root  = newNode(6);
  root->left         = newNode(2);
  root->right        = newNode(4);
  root->right->left  = newNode(1);
  root->right->right = newNode(3); 
  //root->right->left->right  = newNode(9);
  //root->left->right = newNode(10); 
  
    
    /*cout<<maxHeight(root);
    cout<<size(root);
    inorder(root);
    mirror(root);
    cout<<endl;
    inorder(root);
    vector<int> v;
    printAllPathsFromRootToLeaf(root, v);
    cout<<lowestCommonAncestor(root, 3, 5);
     * queue<struct node *> q;
       levelOrder(root, q);
     * stack<struct node *> s1;
       stack<struct node *> s2;
       spiralOrder(root, s1, s2);
     * cout<<maxVal(root)<<endl;
        cout<<minVal(root);
     * cout<< childrenSumProperty(root);
     * convertArbitraryBinaryTreeToHoldChildremSumProperty(root);
        queue<struct node *> q;
        levelOrder(root, q);
     * cout<<diameter(root);
    */
  
  cout<<isHeightBalanced(root);
  
  return 0;
}

