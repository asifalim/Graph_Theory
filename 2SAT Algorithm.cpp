#include<bits/stdc++.h>
using namespace std;
const int mxN=2e5+2;
vector<int>adj[mxN],revadj[mxN],v,vv,vis;
void dfs1(int n)
{
    vis[n]=1;
    for(auto i:adj[n])if(!vis[i])dfs1(i);
    v.push_back(n);
}
void dfs2(int n,int m)
{
    vis[n]=0;vv[n]=m;
    for(auto i:revadj[n])if(vis[i])dfs2(i,m);
}
int main()
{
    int n,m,i,a,b,j;
    char c1,c2,ans[mxN];
    cin>>n>>m;vis.assign(2*m,0);vv.assign(2*m,0);
    for(i=0;i<n;i++)
    {
        cin>>c1>>a>>c2>>b;
        a--;b--;
        a*=2;b*=2;
        if(c1=='-')a^=1;     //to make a'
        if(c2=='-')b^=1;     //to make b'
        adj[a^1].push_back(b);
        adj[b^1].push_back(a);
    }
    for(i=0;i<2*m;i++)
    for(auto j:adj[i])revadj[j].push_back(i);
    for(i=0;i<2*m;i++)if(!vis[i])dfs1(i);
    for(i=2*m-1;i>=0;i--)if(vis[v[i]])dfs2(v[i],i);
    for(i=0;i<m;i++)
    {
        if(vv[2*i]==vv[2*i+1])
        {
            cout<<"IMPOSSIBLE"<<endl;return 0;
        }
        ans[i]=(vv[2*i]<vv[2*i+1]?'+':'-');
    }
    for(i=0;i<m;i++)cout<<ans[i];cout<<endl;
    return 0;
}
