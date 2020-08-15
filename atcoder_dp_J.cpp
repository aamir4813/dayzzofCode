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


// vector<vvi> dp;
vector<vector<vector<double>>> dp;

double doSome(int a , int b , int c , int n){


    if( a < 0 or b < 0  or c < 0 ){
        return 0;
    }
    else if(a == 0  and b == 0  and c == 0){
        return dp[a][b][c] = 0 ; 
    }

    if(dp[a][b][c] > -1){
        return dp[a][b][c];
    }

    double first_sushi = a * doSome(a-1 , b , c , n );
    double second_sushi = b * doSome(a+1 , b-1 , c , n );
    double third_sushi = c * doSome(a , b+1 , c-1 , n);

    return dp[a][b][c] = (n + first_sushi +second_sushi +third_sushi) / (a+b+c);
}

void solv(){
    ll n;
    cin >> n ;

    vi arr(n);

    FOR(i , 0 , n-1){
        cin >>arr[i];
    }

    dp.assign(n+1 , vector<vector<double>>(n+1 , vector<double>(n+1 , -1)));

    map mp;
    
    for(auto x : arr){
        mp[x]++;
    }

    // cout << setprecision(20) << doSome(mp[1] , mp[2] , mp[3] , n ) << endl;
    cout << setprecision(20) << iterativeSushi(mp[1] , mp[2] , mp[3] , n ) << endl;
    

}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}


