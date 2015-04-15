#include<iostream>

using namespace std;

void print(string &str,int i,int n,bool visited[])
{
    if(i==n)
    {
        int j=0;
        for(j=0;j<n;j++)
        {
            if(visited[j])
                cout<<str[j];
        }
        cout<<endl;
    }
    else
    {
        visited[i]=true;//include it 
        print(str,i+1,n,visited);

        visited[i]=false;//exclude it
        print(str,i+1,n,visited);
    }
}

int main()
{
    string str="prashant";
    bool visited[str.length()];
    unsigned int i=0;
    for(i=0;i<str.length();i++)
        visited[i]=false;

    print(str,0,str.length(),visited);
    return 0;

}
