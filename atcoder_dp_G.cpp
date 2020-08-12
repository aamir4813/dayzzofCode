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
#define all(x) x.begin() , x.end()
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fastcout ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define testcases int tt = 1 ; cin >> tt ; for(int i = 1 ; i <= tt ; ++i)
#define codejam cout << "Case #"<<i <<": "; 
#define FOR(i,a,n) for(int i = a ; i <= n ; ++i)
#define FORback(i,a,n) for(int i = n ; i >= a ; --i)
#define ll long long int
const ll INF = 1e13+7;
const ll mod = 1e9+7;

vvll graph;
vll dp;

ll doSome(ll curr){

    if(dp[curr] != -1)
        return dp[curr];

    
    bool leaf = 1;
    ll ans = 0;


    for(auto x : graph[curr]){
        leaf = 0;
        ans = max(doSome(x) , ans);
    }

    return dp[curr] = (leaf ? 0 : 1 + ans);

}

void solv(){
    ll n  , m;
    cin >> n >> m ;

    graph.assign(n+1 , vll());    

    FOR(i , 1 , m){
        ll a , b ;
        cin >>a >> b ;
        graph[a].push_back(b);
    }

    dp.assign(n+1 , -1) ;

    ll ans = 0;
    FOR(i , 1 , n){
        ans = max(ans , doSome(i) );
    }
    cout << ans << endl;
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}


