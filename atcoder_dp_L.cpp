// #pragma GCC optimize "trapv"

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


vvll dp;

ll doSome(vll&arr , int i , int j){


    if(i == j){
        return dp[i][j] = arr[i];
    }
    if(j == i+1){
        return dp[i][j] = max(arr[i] , arr[j]);
    }

    if(dp[i][j] != -1)
        return dp[i][j];
    // 1 2 3

    ll a = arr[i] + min(doSome(arr , i+2 , j) , doSome(arr , i+1 , j-1));
    ll b = arr[j] + min(doSome(arr , i+1 , j-1 ) , doSome(arr , i , j-2));

    return dp[i][j] = max(a , b);
}


void solv(){
    ll n;
    cin >> n ;
    vll arr(n);

    FOR(i , 0 , n-1){
        cin >> arr[i];
    }
    dp.assign(n+1 , vll(n+1 , -1));
    ll sum= accumulate(all(arr) , 0LL);
    ll val = doSome(arr , 0 , n-1);

    cout << 2*val - sum << endl;
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}


