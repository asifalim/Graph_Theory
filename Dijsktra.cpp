#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define endl "\n"
#define INF 1e18
const int mxN=1e5+3;
vector<pair<int,int>>adj[mxN];
vector<ll>dis,vis,par,v;
void dij(int n)
{
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,n});
    dis[n]=0;
    par[n]=0;
    while(!pq.empty())
    {
        ll node=pq.top().second,node_dis=pq.top().first;
        pq.pop();
        if(vis[node])continue;
        vis[node]=1;
        for(pair<int,int>edge:adj[node])
        {
            if(node_dis+edge.second<dis[edge.first])dis[edge.first]=node_dis+edge.second,pq.push({dis[edge.first],edge.first}),par[edge.first]=node;
        }
    }
}
int main()
{
    int n,a,b,c,m,i,j,cn=0,sm=0,mx=INT_MIN,mn=INT_MAX,k;
    string s,st,st1;
    cin>>n>>m;
    dis.assign(n+1,INF);
    vis.assign(n+1,0),par.assign(n+1,0);
    for(i=0; i<m; i++)cin>>a>>b>>c,adj[a].push_back({b,c}),adj[b].push_back({a,c});
    dij(1);
    v.push_back(n);
    if(dis[n]==INF)
    {
        cout<<-1<<endl;
        return 0;
    }
    while(par[n])v.push_back(par[n]),n=par[n];
    for(i=v.size()-1; i>=0; i--)cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}

