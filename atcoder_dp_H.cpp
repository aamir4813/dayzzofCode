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

vvi dp;

ll doSome(vvi &arr , int i , int j){
    int n = arr.size();
    int m = arr[0].size();

    if( i == n or j == m)
        return 0;
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if( i == n-1 and j == m-1){
        return dp[i][j] = 1;
    }

    ll res = 0;
    if(i+1 < n && arr[i+1][j] == 0 ){
        res =  (res + doSome(arr , i+1 , j))%mod;
    }
    if(j+1 < m and arr[i][j+1] == 0){
        res = (res + doSome(arr , i , j+1))%mod;
    }
    return dp[i][j] = res;
}

void solv(){
    ll n , m ;
    cin >> n >> m ;

    vvi arr(n+1 , vi(m+1 , 0));

    FOR(i , 1 , n){
        FOR(j , 1 , m){
            char c ;
            cin >> c;
            if(c == '#')
                arr[i][j] = 1;
        }
    }

    // assign dp
    dp.assign(n+1 , vi(m+1 , -1));

    ll  ans = doSome(arr , 1 , 1);
    cout << ans << endl;
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}


