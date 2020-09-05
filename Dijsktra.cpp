#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll,ll>>adj[10001];
vector<ll>dis;
void ans(ll n)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,n});
    dis[n]=0;
    while(!pq.empty())
    {
        int node=pq.top().second;
        int node_dis=pq.top().first;
        pq.pop();
        for(pair<ll,ll>edge:adj[node])
        {
            if(node_dis+edge.second<dis[edge.first])
            {
                dis[edge.first]=node_dis+edge.second;
                pq.push({dis[edge.first],edge.first});
            }
        }
    }
}
int main()
{
    ll k;
    cin>>k;
    while(k--)
    {
        ll t,n,a,b,w,i,j,c,d;
        cin>>t>>n;
        dis.assign(t+1,1999999999);
        memset(adj,0,sizeof(adj));
        for(i=0; i<n; i++)
        {
            cin>>a>>b>>w;
            adj[a].push_back({b,w});
        }
        cin>>c>>d;
        ans(c);
        if(dis[d]==1999999999)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<dis[d]<<endl;
    }
}
