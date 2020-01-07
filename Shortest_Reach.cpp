#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define MAX 200005
#define MOD 1000000007
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
#define si set<ll>
#define mp map<ll,ll>
#define mpi map<ii,ll>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#include <unordered_map> 
#define ump unordered_map<ll,ll>
int main()
{ 
	fast 
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		vi graph[n+5];
		ll i;
		for(i=0;i<m;i++)
		{
			ll x,y;
			cin>>x>>y;
			graph[x].pb(y);
			graph[y].pb(x);
		}
		ll k;
		cin>>k;
		ll vis[n+5];
		ll dis[n+5];
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		queue<ll> q;
		q.push(k);
		dis[k]=0;
		vis[k]=1;
		while(!q.empty())
		{
			ll s=q.front();
			q.pop();
			for(i=0;i<graph[s].size();i++)
			{
				if(vis[graph[s][i]]==0)
				{
					dis[graph[s][i]]=dis[s]+6;
					vis[graph[s][i]]=1;
					q.push(graph[s][i]);
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(i!=k)
			{
				if(vis[i]==0)
			{
				cout<<"-1"<<" ";
			}
			else
			{
				cout<<dis[i]<<" ";
			}
			}
			
		}
		cout<<endl;
	}
}