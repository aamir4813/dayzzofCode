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

// double dp[3001][3001] ;
vector<vector<double>> dp;
double doSome(vector<double>&arr , int i , int curr ){
    
    if( curr ==  0){
        return 1;
    }
    if(i < 0){
        return 0;
    }

    if(dp[i][curr] > -.9) return dp[i][curr];


    double x = arr[i] * doSome(arr , i-1 , curr-1);
    double y = (1 - arr[i]) * doSome(arr , i-1 , curr);

    return dp[i][curr] = x+y;
}

void solv(){
    ll n;
    cin >> n ;
    vector<double> arr(n);

    FOR(i , 0 , n-1){
        cin >> arr[i];
        arr[i] = arr[i] * 1.000000000;
    }
  dp.assign(n+1 , vector<double>(n+1 , -1));

    ll target = (n+1)/2 ;
    // FOR(i , 0 , n){
    //     FOR(j , 0 , n){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    double ans = doSome(arr , n , target);

    cout   << setprecision(10) << ans <<  endl;
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}


