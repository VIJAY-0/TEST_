#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
#define ll long long


int mod = 1e9+7;
int N = 2e5+1;
vector<int>fact(N);





long long bexp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
        res = res * a;
    res%=mod;
    a = a * a;
    a%=mod;
    b >>= 1;
}
return res%mod;
}

int minv(int a){
    return bexp(a,mod-2);
}

int ncr(int n,int r){
    if(r>n) return 0 ;
    long long res  =fact[n];
    res%=mod;
    res*=minv(fact[r]);
    res%=mod;
    res*=minv(fact[n-r]);
    return res%mod;
}


int main()
{
    fact[0]=1;for(int i=1;i<N;i++)fact[i] = (1ll*i*fact[i-1])%mod;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    
    int tt=1;
    cin >> tt;
    while(tt--)
    {
    }

    return 0;
}