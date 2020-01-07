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
	ll i;
	vi v;
	for(i=0;i<n;i++)
	{
		make_set(i);
	}
	for(i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		union_sets(x,y);
	}
	mp ma;
	for(i=0;i<n;i++)
	{
		ll h;
		h=find_set(i);
		if(ma[h]==0)
		{
			v.pb(sizee[h]);
			ma[h]++;
		}
	}
	ll total=0;
	ll a[v.size()+5];
	for(i=0;i<v.size();i++)
	{
		if(i!=0)
		{a[i]=a[i-1]+v[i];}
		else
		{
			a[i]=v[i];
		}
	}
	for(i=v.size()-1;i>=1;i--)
	{
		total+=(v[i]*a[i-1]);
	}
	cout<<total<<endl;
}