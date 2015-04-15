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

void print(int n, int m, vector<string>& ans)
{
    
    if(n==0 && m==0)
    {
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    if(n>0)
    {
        ans.push_back("Right");
        print(n-1,m,ans);
        ans.pop_back();
    }
    if(m>0)
    {
        ans.push_back("left");
        print(n,m-1,ans);
        ans.pop_back();
    }
    
}

int main() {
    int n;
	int m;
	/*
			  (n,m)
		--------
		--------
		--------
		--------
		--------
	 (0,0)
		
		bottom left corner is (0,0) 
		top right corner is (n,m)
	
	*/
    
    cin>>n>>m;
    
    vector<string> ans;
    
    print(n,m,ans);
   
    
    return 0;
    
}
