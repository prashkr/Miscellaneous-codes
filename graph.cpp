#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;
#define Graph vector< vector<int> >

typedef struct node 
{
    int inDegree;
    int outDegree;
}Degree;

void printGraph(Graph &g)

{    
    cout<<"Printing Graph: "<<endl;
    int n = g.size();
    unsigned int i, j;
    for(i=1; i<n; i++)
    {
        //sort(g[i].begin(), g[i].end());
        int size = g[i].size();
        cout<<i<<": ";
        for(j=0; j<size; j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }

}

void printQueue(queue<int> Q)
{
    while(!Q.empty())
    {
        int q = Q.front();
        cout<<q<< " ";
        Q.pop();
    }
    cout<<endl;
}

void bfs(Graph &g, int start)
{
    int n = g.size();
    bool visited[n];
    memset(visited, false, sizeof(visited));

    queue<int> Q;
    visited[start] = true;
    Q.push(start);
    vector<int>::iterator it;
    cout<<start<<" ";
    while(!Q.empty())
    {   
        // cout<<"Printing Queue:"<<endl; 
        // printQueue(Q);
        start = Q.front();
        Q.pop();

        for(it=g[start].begin(); it!=g[start].end(); it++)
        {
            if(!visited[*it])
            {
                cout<<(*it)<<" ";
                visited[*it] = true;
                Q.push(*it);
            }    
        }
    }
    cout<<endl;
}

void dfs(Graph &g, int start)
{
    int n = g.size();
    bool visited[n];
    memset(visited, false, sizeof(visited));

    stack<int> s;
    visited[start] = true;
    s.push(start);
    vector<int>::iterator it;
    cout<<start<<" ";
    while(!s.empty())
    {
        start = s.top();
        s.pop();

        for(it=g[start].begin(); it!=g[start].end(); it++)
        {
            if(!visited[*it])
            {
                cout<<(*it)<<" ";
                visited[*it] = true;
                s.push(*it);
            }
        }

    }
    cout<<endl;
}

void rec_dfs(Graph &g, int start, bool visited[])
{
    cout<<start<<" ";
    visited[start] = true;
    vector<int>::iterator it;
    for(it=g[start].begin(); it!=g[start].end(); it++)
    {
        if(!visited[*it])
        {
            rec_dfs(g, *it, visited);
        }
    }
}

void dfsUtil(Graph &g, int start)
{
    int n = g.size();
    bool visited[n];
    memset(visited, false, sizeof(visited));
    rec_dfs(g, start, visited);
    cout<<endl;
}

void calcDegree(Graph &g, Degree degree[])
{
    int n = g.size();
    unsigned int i, j;
    for(i=1; i<n; i++)
    {
        int size = g[i].size();
        degree[i].outDegree = size;
        for(j=0; j<size; j++)
        {
            degree[g[i][j]].inDegree += 1;
        }
    }
}

int main()
{
    int n, m;
    //cout<<"Number of nodes"<<endl;
    cin>>n;
    Graph g(n+1);

    //cout<<"Enter no. of edges"<<endl;
    cin>>m;
    // cout<<"Enter edges"<<endl;
    unsigned int i, j;
    for(i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        //g[b].push_back(a);
    }

    //bfs using queue
    bfs(g, 1);

    //dfs using stack
    dfs(g, 1);

    //rec_dfs
    dfsUtil(g, 1);

    //print Graph
    printGraph(g);

    //Degree
    Degree degree[n+1];
    memset(degree, 0, sizeof(degree));
    calcDegree(g, degree);
    cout<<"Printing Degree:"<<endl;
    for(i=1; i<=n; i++)
    {
        cout<<i<<": "<<degree[i].inDegree<<" "<<degree[i].outDegree<<endl;
    }

    

    return 0;
}