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


vvll dp;
ll doSome(vvll &arr , int index , int set){

    int n = arr.size();
    if(index == n ){
        if(set == 0){
            // cerr <<" YES " ;
            return 1;
        }
        return  0;
    }

    if(dp[index][set] != -1){
        return dp[index][set];
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; ++i){

        bool val = (((1 << i) & (set)) == 0 ? 0 : 1) ;

        if(arr[index][i] == 1 and val ){
            ans += doSome(arr , index+1 , ((1<< i)^set));
            ans %= mod;
        }
    }

    return dp[index][set] = ans;
}

void solv(){
    ll n ;
    cin >> n ;

    vvll arr(n , vll(n));

    FOR(i , 0 , n-1){
        FOR(j , 0 , n-1){
            cin >> arr[i][j];
        }
    }
    int set = (1 << n) - 1 ;

    dp.assign(n+1 , vll(set+1 , -1));
    cout << doSome(arr , 0 , set ) << endl;
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
    time;
}


