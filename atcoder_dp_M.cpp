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

vvi dp ;

void solv(){
    ll n  , k ;
    cin >> n  >> k;

    vll arr(n+1);
    FOR(i , 1 , n){
        cin >> arr[i];
    }
    dp.assign(n+2 , vi(k+2 , 0));

    FOR(i , 0 , k){
        if(arr[1] < i){
            dp[1][i] = 0; 
        }
        else{
            dp[1][i] = 1;
        }
    }

    FOR(i , 2 , n){
        FOR(j , 0 , k){
            if(j == 0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                if(j >= arr[i]+1){
                    dp[i][j] = (mod + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-arr[i]-1])%mod;
                }
                else{
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
                }
            }
        }
    }

    // for(auto x : dp){
    //     for(auto y : x){
    //         cerr << y << " ";
    //     }
    //     cerr << endl;
    // }
    cout << dp[n][k] << endl;
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
    time;
}


