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

// mattrix exponent thing here

vvll multiply(vvll a , vvll &b ){
    int n = a.size();
    vvll res(n , vll(n , 0));
    
    FOR(i , 0 , n-1){
        FOR(j , 0 , n-1){
            FOR(k , 0 , n-1){
                res[i][j] += (a[i][k] * b[k][j])%mod;
                res[i][j] %= mod;
            }
        }
    }

    return res;
}

vvll power(vvll &mat , ll exp ){

    if(exp == 1){
        return mat;
    }

    vvll sq = power(mat , exp/2); 

    if(exp & 1){
       return multiply(multiply(mat , sq) , sq);
    }
    else{
        return multiply(sq , sq);
    }
}

ll doSome(vvll &adj , ll k , int n){

    vvll ak = power(adj , k);
    ll ans = 0 ;
    FOR(i , 0 , n-1){
        FOR(j , 0 , n-1){
            ans = (ans + ak[i][j])%mod;;
        }
    }

    return ans;
}

void solv(){
    ll n , k ;
    cin >> n >> k;

    vvll adj(n , vll(n)) ;

    FOR(i , 0 , n-1){
        FOR(j , 0 , n-1){
            cin >> adj[i][j];
        }
    }

    cout << doSome(adj , k , n) << endl;
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}


