#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>v[1004];
const int mx=15;
int lca[1004][mx],level[1004],par[1004];
void dfs(int n,int l,int from)
{
    level[n]=l;                   //Time_complexity O(logn) and space_complexity O(nlogn)
    par[n]=from;
    for(auto i:v[n])
    {
        if(i!=from)dfs(i,l+1,n);
    }
}
void build_table(int n)
{
    for(int i=1; i<=n; i++)lca[i][0]=par[i];
    for(int j=1; 1<<j<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            lca[i][j]=lca[lca[i][j-1]][j-1];
        }
    }
}
int dis(int a,int b)
{
    if(level[b]<=level[a])swap(b,a);
    int d=log2(level[b]);
    for(int i=d; i>=0; i--)
    {
        if(level[b]-(1<<i)>=level[a])b=lca[b][i];
    }
    if(a==b)return a;
    for(int i=d; i>=0; i--)
    {
        if(lca[a][i]!=lca[b][i])a=lca[a][i],b=lca[b][i];

    }
    return par[b];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,a,b,c,q,l,r;
        cin>>n>>a;
        while(a--)
        {
            cin>>b>>c;
            v[b].pb(c);
            v[c].pb(b);
        }
        dfs(1,0,1);
        build_table(n);
        cin>>q;
        while(q--)
        {
            cin>>l>>r;
            cout<<dis(l,r)<<endl;
        }
        for(i=1; i<=n; i++)v[i].clear();
    }
}
