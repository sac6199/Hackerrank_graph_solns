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
ll parent[MAX];
ll sizee[MAX];
void make_set(int v) {
    parent[v] = v;
    sizee[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizee[a] < sizee[b])
            swap(a, b);
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}
int main()
{ 
	fast 
	ll n,m;
	cin>>n>>m;
	vector<pair<ll,pair<ll,ll>>> v;
	ll i;
	for(i=0;i<m;i++)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		v.pb(make_pair(z,make_pair(x,y)));
	}
	ll j;
	cin>>j;
	sort(v.begin(),v.end());
	for(i=1;i<=n;i++)
	{
		make_set(i);
	}
	ll sum=0;
	for(i=0;i<v.size();i++)
	{
		if(find_set(v[i].second.first)!=find_set(v[i].second.second))
		{
			sum+=v[i].first;
			union_sets(v[i].second.first,v[i].second.second);
		}
	}
	cout<<sum<<endl;
}