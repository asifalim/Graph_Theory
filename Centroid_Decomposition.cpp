#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;        //O(nlogn)
int par[N],sub[N],nn;    //This algorithm makes n height tree in logn hieght
set<int>ar[N];
void dfs1(int n,int p)
{
    sub[n]=1;
    nn++;
    for(auto i:ar[n])
    if(i!=p)
    dfs1(i,n),sub[n]+=sub[i];
}
int dfs2(int n,int p)
{
    for(auto i:ar[n])
    if(i!=p and sub[i]>nn/2)return dfs2(i,n);
    return n;
}
void decompos(int n,int p)
{
    nn=0;
    dfs1(n,n);
    int centroid=dfs2(n,n);
    if(p==-1)p=centroid;
    par[centroid]=p;
    for(auto i:ar[centroid])
    ar[i].erase(centroid),decompos(i,centroid);
    ar[centroid].clear();
}
int main()
{
    int n,m,i,j,a,b;
    cin>>n;
    for(i=1;i<n;i++)cin>>a>>b,ar[a].insert(b),ar[b].insert(a);
    decompos(1,-1);
    for(i=1;i<=n;i++)cout<<par[i]<<" ";
    return 0;
}
