#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 1000001
#define max(a,b) (a>b)?a:b
long long int fact[MAX];
long long int ifact[MAX];

long long int modular_pow(long long int base, long long int exponent)
{
    long long int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % MOD;
        exponent = exponent >> 1;
        base = (base * base) % MOD;
    }
    return result;
}

long long int coeff(int n, int r)
{
    
}

int main()
{
    memset(ifact, 0, sizeof(ifact));
    memset(fact, 0, sizeof(fact));
    ifact[1]=1;
    fact[1]=1;
    fact[0]=1;
    int n;
    cin>>n;
    if(n<13)
    {
        cout<<"0"<<endl;
        return 0;   
    }
    int m = n-13;
    int k = m/2;
    if(k==0)
    {
        cout<<"1"<<endl;
        return 0;
    }
    n = 7+k-1;
    int r = k;

    int i;
    int limit = max(n,r);
    for(i=2; i<=limit; i++)
    {
        fact[i] = (i*fact[i-1])%MOD;
        ifact[i] = (modular_pow(i, MOD-2)*ifact[i-1])%MOD;
    }
    long long int ans = (((fact[n]*ifact[r])%MOD)*ifact[n-r])%MOD;
    cout<<ans<<endl;
    return 0;
}