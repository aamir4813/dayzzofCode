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

typedef long long int ll;

void solv(){
    ll n;
    cin >> n ;

    vvi arr(n , vi(3 ));

    FOR(i , 0 , n-1){
        FOR(j , 0 , 2){
            cin >> arr[i][j];
        }
    }

    vvi dp(n+1 , vi(3 , 0));

    FOR(i , 1 , n){
        dp[i][0] = max(dp[i-1][1] , dp[i-1][2]) + arr[i-1][0];
        dp[i][1] = max(dp[i-1][0] , dp[i-1][2]) + arr[i-1][1];
        dp[i][2] = max(dp[i-1][0] , dp[i-1][1]) + arr[i-1][2];
    }

    cout << max({dp[n][0] , dp[n][1] , dp[n][2]})<< endl;
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}


