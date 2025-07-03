#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()
#define ll long long


class SegTree{

    int N; 
  public:
    vector<long long> t;
    SegTree(int N){
        t=  vector<long long>(4*(N+1));
    }
long long f(long long x , long long y){ return x+y;}
    void build(vector<int>&a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = f(t[v*2] ,t[v*2+1]);
        }
    }
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = f(t[v*2] , t[v*2+1]);
        }
    }
    ll sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return f(sum(v*2, tl, tm, l, min(r, tm))
            , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};
  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    int tt=1;
    cin >> tt;
    while(tt--)
    {
    }

    return 0;
}