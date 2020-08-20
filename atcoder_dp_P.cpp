// #pragma GCC optimize "trapv"

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vll vector<ll> 
#define vpll vector<pair<ll ,ll>>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define MAP map<ll ,ll>
#define UMAP unordered_map<ll , ll>
#define endl "\n"
#define SET set<ll> 
#define SETC set<char>
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fastcout ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define testcases int tt = 1 ; cin >> tt ; for(int i = 1 ; i <= tt ; ++i)
#define codejam cout << "Case #"<<i <<": "; 
#define FOR(i,a,n) for(int i = a ; i <= n ; ++i)
#define FORback(i,a,n) for(int i = n ; i >= a ; --i)
#define time cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#define ll long long int
const ll INF = 1e13+7;
const ll mod = 1e9+7;

vvll graph;
vvll dp;

ll doSome(int curr , int color , int parent){

    ll ans= 0 ;

    if(dp[curr][color] != -1){
        return dp[curr][color];
    }

    ll temp = 1;
    ll temp2 = 1;
    
    for(auto x : graph[curr]){

        if(x != parent){
            // let's say it's black
            temp *= doSome(x , 1 , curr);
            temp %= mod;
            if(color){
                temp2 *= doSome(x , 0 , curr);
                temp2 %= mod;
            }
        }

    }
    if(color){
        ans += temp2;
        ans %= mod;
    }
    
    ans += temp;

    return dp[curr][color] = ans%mod;

}

void solv(){
    ll n ;
    cin >> n ;
    graph.assign(n+2 , vll());
    FOR(i , 1 ,n-1){
        ll a , b ;
        cin >> a >> b ;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll ans = 0;
    dp.assign(n+2 , vll(2 , -1));
        // here i have taken color 1 as white and 0 as black
    ans += doSome(1 , 1  , -1);
    cout << ans  << endl;
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}
