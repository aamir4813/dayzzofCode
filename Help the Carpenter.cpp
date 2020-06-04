/*
https://www.codechef.com/PCO12020/problems/HELCARP
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define t_case ll test;cin>>test;while(test--)
#define left(nod) 2*nod
#define right(nod) 2*nod+1
#define ss second
#define ff first
#define pb push_back
#define maxN 100009
#define pll pair<ll,ll>

vector <ll> g[101];

ll vis[101];bool isans;vector <ll> ans;

void dfs(ll node)
{
	vis[node]=1;
	
	for(auto it:g[node])
	{
		if(vis[it]==1)isans=false;
		if(vis[it]==0)dfs(it);
	}
	vis[node]=2;
	ans.pb(node);
}
	
	

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	t_case
	{
		for(ll i=0;i<101;i++)g[i].clear();
		memset(vis,0,sizeof(vis));
		
		ll n;cin>>n;ll m;cin>>m;
		for(ll i=1;i<=m;i++)
		{
			string s1,s2;cin>>s1>>s2;s1=s1.substr(1,s1.length());s2=s2.substr(1,s2.length());
			
			ll x,y;x=stoi(s1),y=stoi(s2);
			
			
			g[x].pb(y);
		}
		isans=true;ans.clear();
		
		for(ll i=1;i<=n;i++)
		{
			if(vis[i]==0)
			dfs(i);
		}
		if(isans)
		{
			cout<<"YES\n";
			for(auto it:ans)
			cout<<"k"<<it<<endl;
		}
		else
		cout<<"NO\n"<<endl;
	}
		
		
		
}