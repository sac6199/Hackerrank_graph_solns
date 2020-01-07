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
	ll t;
	cin>>t;
	while(t--)
	{
		ll citynum,roadnum,libcost,roadcost;
		cin>>citynum>>roadnum>>libcost>>roadcost;
		ll i;
		for(i=1;i<=citynum;i++)
		{
			make_set(i);
		}
		for(i=0;i<roadnum;i++)
		{
			ll x,y;
			cin>>x>>y;
			union_sets(x,y);
		}
		mp ma;
		ll totalcost=0;
		for(i=1;i<=citynum;i++)
		{
			ll h=find_set(i);
			if(ma[h]==0)
			{
				ma[h]++;
				totalcost+=(sizee[h]-1)*roadcost+libcost;
			}
		}
		ll y=citynum*libcost;
		totalcost=min(totalcost,y);
		cout<<totalcost<<endl;
		
	}
}