#include <bits/stdc++.h>

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

