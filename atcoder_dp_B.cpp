#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vll vector<ll> 
#define vpll vector<pair<ll ,ll>>
#define vvi vector<vector<ll>>
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
#define FORback(i,n,a) for(int i = n ; i >= a ; --i)

typedef long long int ll;

void solv(){
    ll n , k;
    cin >> n  >> k;
    vi arr(n+1 );
    FOR(i , 1 , n){
        cin >> arr[i];
    }

    vll dp(n+1 , INT_MAX);
    dp[1] = 0;
    FOR(i , 2 , k+1){
        dp[i] = abs(arr[i] - arr[1]);
    }

    FOR(i , k+2 , n){
        FORback(j , i-1 , i-k){
            dp[i] = min(abs(arr[i] - arr[j])+dp[j] , dp[i]);
        }
    }
    cout << dp[n] << endl;
    // FOR(i , 1 , n){
    //     cout << dp[i] << " ";
    // }
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}


