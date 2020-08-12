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
    ll n , w;
    cin >> n  >> w;
    
    vi value(n) , weight(n);
 
    FOR(i , 0 , n-1){
        cin >>weight[i];
        cin >> value[i];
    }
 
    vvll dp(w+1 , vll(n+1 , 0));
 
    FOR(i , 1 , w){
        FOR(j , 1 , n){
            
        // here we wanted 
 
        if(weight[j-1] <= i){
            dp[i][j]  = max(dp[i-weight[j-1]][j-1] + value[j-1] , dp[i][j-1]) ;
        }
        else{
            dp[i][j] = dp[i][j-1];
        }
 
        }
    }
    
    cout << dp[w][n] << endl;
}
 
int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}
 