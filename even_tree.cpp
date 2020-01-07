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
vi tree[105];
ll vis[105];
ll i;
void bfs(ll s)
{
	queue<ll> q;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		ll h=q.front();
		q.pop();
		for(i=0;i<tree[h].size();i++)
		{
			if(vis[tree[h][i]]==0)
			{
				vis[tree[h][i]]=1;
				q.push(tree[h][i]);
			}
		}
	}

}
int main()
{ 
	fast 
	ll n,m;
	cin>>n>>m;
	ll i,j;
	for(i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		tree[x].pb(y);
		tree[y].pb(x);
	}
	ll ans=0;
	ll count=0;
	for(i=1;i<=n;i++)
	{
		count=0;
		bfs(i);
		for(j=i+1;j<=n;j++)
		{
			if(vis[j]==1)
			{
				count++;
			}
			vis[j]=0;
		}
		if(count%2==1)
		{
			ans++;
		}
	}
	cout<<ans-1<<endl;

}