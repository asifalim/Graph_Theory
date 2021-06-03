//Problem link---> https://cses.fi/problemset/task/1134/
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e9
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,kk=0;
const int mxn=2e5+3,mod=1e9+7;
signed main()
{
    //fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX;
    string s,ss,sr;
    bool f=true,ff=false;
    cin>>n;int ar[n+2];map<int,int>mp;set<int>st;
    for(i=0;i<n-2;i++)cin>>ar[i],mp[ar[i]]++;
    for(i=1;i<=n;i++)if(!mp[i])st.insert(i);      //Those node aren't present, they must be leaf node.
    for(i=0;i<n-2;i++)
    {
        cout<<*st.begin()<<" "<<ar[i]<<endl;
        st.erase(*st.begin());
        mp[ar[i]]--;
        if(!mp[ar[i]])st.insert(ar[i]);
    }
    cout<<*st.begin()<<" "<<*st.rbegin()<<endl;
    //}
    return 0;
}
