#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e5
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,k=0;
const int mxN=1e3+3,mod=1e9+7;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int dp[mxN][mxN],N,M;
char ch[mxN][mxN];
bool check(int i,int j)
{
    return (~i and ~j and i<N and j<M and dp[i][j]==-1 and (ch[i][j]=='.' or ch[i][j]=='B'));
}
bool ck(int i,int j)
{
    return (~i and ~j and i<N and j<M);
}
void bfs(int a,int b,int c,int d)
{
    bool f=false;
    queue<pair<int,int>>q;
    q.push({a,b});
    mem(dp,-1);
    dp[a][b]=0;
    while(!q.empty())
    {
        int X=q.front().first,Y=q.front().second;
        q.pop();if(X==c and Y==d)break;
        for(int i=0; i<4; i++)
        {
            int x=X+dx[i],y=Y+dy[i];
            if(check(x,y))dp[x][y]=dp[X][Y]+1,q.push({x,y});
        }
    }
    /*for(int i=0;i<N:i++)
    {
        for(int j=0;j<M;j++)cout<<dp[i][j]<<" ";cout<<endl;
    }*/
    int cn=dp[c][d],cn1;cn1=cn;
    if(cn==-1)
    {
        cout<<"NO"<<endl;
        return;
    }
    string s;
    while(cn)
    {
        if(ck(c+1,d) and dp[c+1][d]==cn-1)s+='U',c++;
        if(ck(c,d-1) and dp[c][d-1]==cn-1)s+='R',d--;
        if(ck(c-1,d) and dp[c-1][d]==cn-1)s+='D',c--;
        if(ck(c,d+1) and dp[c][d+1]==cn-1)s+='L',d++;
        cn--;
    }
    reverse(s.begin(),s.end());
    cout<<"YES"<<endl<<cn1<<endl<<s<<endl;;
}
signed main()
{
    //fast;
    //w(t)
    //{
        int n,m,a,b,c,d,e,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1;
        string s,ss,sr;
        bool f=false,ff=false;
        cin>>N>>M;
        for(i=0;i<N;i++)
        {
            for(j=0;j<M;j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='A')cn=i,cn1=j;  //Source
                if(ch[i][j]=='B')sm=i,sm1=j;  //Target
            }
        }
        bfs(cn,cn1,sm,sm1);
    //}
    return 0;
}
