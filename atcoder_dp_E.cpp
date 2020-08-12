#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vll vector<ll> 
#define vpll vector<pair<ll ,ll>>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define map map<ll ,ll>
#define umap unordered_map<ll , ll>
#define endl "\n"
#define set set<ll> 
#define setC set<char>
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fastcout ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define testcases int tt = 1 ; cin >> tt ; for(int i = 1 ; i <= tt ; ++i)
#define codejam cout << "Case #"<<i <<": "; 
#define FOR(i,a,n) for(int i = a ; i <= n ; ++i)
#define FORback(i,a,n) for(int i = n ; i >= a ; --i)
#define ll long long int 
const ll INF = 1e13 + 7 ;
 
void solv(){
    ll n,w;
    cin>>n>>w;
    vpll v(n);
    ll sum=0;
 
    for(ll i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        sum+=v[i].second;
    }
 
    vector<vector<ll> > dp(n+1,vector<ll>(sum+1,INF));
 
    for(ll i=0;i<=n;i++){
        dp[i][0]=0;
    }
 
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(j >= v[i-1].second)
                dp[i][j]=min(dp[i][j],v[i-1].first+dp[i-1][j-v[i-1].second]);
        }
    }
    ll ans=0;
 
    /*for(ll i=0;i<=n;i++){
        for(ll j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
 
    for(ll i=0;i<=sum;i++){
        if(dp[n][i]<=w){
            ans=max(ans,i);
        }
    }
 
    cout<<ans << endl;
}
 
int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}
 