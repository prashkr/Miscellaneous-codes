#include <algorithm> //min(), max(), reverse(), sort(), next_permutation(), prev_permutation(), swap()
//make_heap(), pop_heap(), push_heap(), sort_heap()
#include <iostream>
#include <cassert> //assert()
#include <cmath> //cos(in radians), sin(), tan(), acos(), asin(), atan(), modf(break into frac and inte parts)
//log(), log10(), log2(), pow(), sqrt(), cbrt(), ceil(), floor(), fmod(), abs()
#include <cstdio> //fclose(), fopen(), fprintf(), fscanf(), printf(), scanf(), gets(), puts()
#include <cstdlib> //srand(time(NULL)), rand(), itoa(), malloc(), free()
#include <cstring> //memcpy(), strcpy(), strcat(), strcmp(), memset(), strlen(), strtok(), strrchr()
#include <sstream>
#include <string> //to_string(any numerical value), stoi(), stoll()
#include <ctime>
#include <deque> //iterators: begin(), end(), rbegin(), rend()
//access: operator[], at(), front(), back()
//modifiers: push_back(), push_front(), pop_back(), pop_front(), erase(), clear()
#include <list> //begin(), end(), push_back(), pop_back()
#include <map> //begin(), end(), rbegin(), rend(), operator[], at(), clear(), find()
//priority_queue: top(), push(), pop()
#include <queue> //front(), back(), push(), pop()
#include <set> //begin(), end(), rbegin(), rend(), insert(), erase(), clear(), find()
#include <stack> //top(), push(), pop()
#include <vector> //iterators: begin(), end(), rbegin(), rend()
//access: operator[], at(), front(), back()
//modifiers: push_back(), pop_back(), erase(), clear()
#include <climits> // INT_MAX, INT_MIN
#include <iomanip> //setPrecison(x), cout<<fixed<<setPrecison(2)

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
#define MAX 50000
#define MOD 1000000007

int clevel=0;

typedef struct node 
{
    int x;
    struct node *left;
    struct node *right;
}Node;

Node *addNode(int val)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->x=val;
    head->left=NULL;
    head->right=NULL;
}

void LeftView(Node *head, int level)
{
    if(head==NULL)
    {
        return;
    }
    
    if(level>clevel)
    {
        cout<<head->x<<" ";
        clevel=level;
    }
    LeftView(head->left,level+1);
    LeftView(head->right,level+1);
}

int main()
{
    Node *head=NULL;
    head=addNode(12);
    head->left=addNode(10);
    head->right=addNode(30);
    head->right->left=addNode(25);
    head->right->right=addNode(40);
    cout<<head->x<<" ";
    LeftView(head, 0);
    return 0;
}

