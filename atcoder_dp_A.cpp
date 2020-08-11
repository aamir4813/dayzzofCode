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
#define FOR(i,a,n) for(int i = a ; i < n ; ++i)
#define FORback(i,a,n) for(int i = n ; i >= a ; --i)

typedef long long int ll;

void solv(){
    ll n;
    cin >> n ;

    vi arr(n+1);
    FOR(i , 1 , n+1){
        cin >> arr[i];
    }

    vi dp(n+1 , 0);
    dp[1] = arr[1];
    dp[2] = abs(arr[2] -arr[1]);
    dp[3] = abs(arr[3] - arr[1]);
    FOR(i , 4 , n+1){
        dp[i]  = min(dp[i-1] + abs(arr[i]-arr[i-1]) , dp[i-2] + abs(arr[i] - arr[i-2]));
    }
    cout << dp[n] << endl;
    // FOR(i , 1 , n+1){
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


