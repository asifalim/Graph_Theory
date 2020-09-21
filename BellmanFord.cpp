#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define   INF  (1LL<<61)
vector<ll>dis,v,par;
struct edge
{
    ll u,v,w;
};
int main()
{
    ll n,m,i,j,x;
    cin>>n>>m;
    vector<edge>edges(m);
    for(auto &i:edges)cin>>i.u>>i.v>>i.w;
    dis.assign(n+1,INF);dis[1]=0;par.assign(n+1,-1);
    for(i=1;i<=n;i++)
    {
       x=-1;
       for(auto &e:edges)
            if(dis[e.u]+e.w<dis[e.v])dis[e.v]=dis[e.u]+e.w,par[e.v]=e.u,x=e.v;
    }
    if(x==-1){cout<<"NO"<<endl;return 0;}
    for(i=1;i<=n;i++)x=par[x];
    for(i=x;;i=par[i])
    {
        v.push_back(i);
        if(v.size()>1 and i==x)break;
    }
    reverse(v.begin(),v.end());cout<<"YES"<<endl;
    for(auto i:v)cout<<i<<" ";cout<<endl;
    return 0;
}
