#include<bits/stdc++.h>
using namespace std;
int vis[10001],in[100001],out[100001],t;
vector<int>v[10001];
set<int>st;
void dfs(int n,int par)
{
    vis[n]=1;
    int child=0;
    in[n]=out[n]=t++;
    for(auto i:v[n])
    {
        if(i==par)continue;
        if(vis[i])out[n]=min(out[n],in[i]);
        else
        {
            dfs(i,n);
            child++;
            out[n]=min(out[n],in[i]);
            if(out[i]>=in[n] and par!=-1)st.insert(n);
        }
    }
    if(par==-1 and child>1)st.insert(n);
}
int main()
{
    int a,b,c,d,i;
    while(1)
    {
        cin>>a>>b;
        if(a==0 and b==0)break;
        for(i=1;i<=a;i++)v[i].clear(),vis[i]=0;st.clear();t=1;
        while(b--)
        {
            cin>>c>>d;
            v[c].push_back(d);
            v[d].push_back(c);
        }
        for(i=1; i<=a; i++)
        {
            if(!vis[i])
            dfs(i,-1);
        }
        cout<<st.size()<<endl;
    }
}
