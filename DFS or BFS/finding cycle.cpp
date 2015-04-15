/* Template by
Ashwin Kumar
IIT Delhi */
#include <algorithm> //min(), max(), reverse(), sort(), next_permutation(), prev_permutation(), swap()
//make_heap(), pop_heap(), push_heap(), sort_heap()
# include <iostream>
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
 
int cycleCount=0;

typedef long long LL;
typedef pair<int, int> pii;
#define MAX 50000
#define MOD 1000000007
 
class Graph
{
    int V;
    vector<int> *adj;
public:
    void add_edge(int v, int w);
    void DFS();
    void DFSUtil(int s, bool *visited, bool *recStack);
    Graph(int v);
};

Graph::Graph(int v)
{
    this->V=v;
    adj = new vector<int>[V];
}

void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int s, bool *visited, bool *recStack)
{
    visited[s]=true;
    recStack[s]=true;
    cout<<s<<" ";
    vector<int>::iterator i;
    for(i=adj[s].begin(); i!=adj[s].end();++i)
    {
        if(!visited[*i])
            DFSUtil(*i, visited, recStack);
        else if(recStack[*i])
        {
            cout<<*i<<" ";
            cycleCount++;
        }
    }
    recStack[s]=false;
}

void Graph::DFS()
{
    bool *visited = new bool[V];
    memset(visited, false, V);
    
    bool *recStack = new bool[V];
    memset(recStack, false, V);
    
    for(int i=V-1;i>=0;i--)
    {
        if(!visited[i])
        {
            cout<<"New component"<<endl;
            DFSUtil(i, visited, recStack);
        }
        
    }
} 

int main()
{
    Graph g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
    
    g.DFS();
    cout<<"Number of Cycles: "<<cycleCount<<endl;
    return 0;
}

