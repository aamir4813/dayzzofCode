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

void solv(){
    ll n ;
    cin >> n ;
    vll a(n) , b(n);

    FOR(i , 0 , n-1)
        cin >>a[i];
    FOR(i, 0 ,n-1)
        cin >> b[i];

    vll dp(n+1);

    dp[1] = b[0];
    map<ll , ll> mp;
    mp[a[0]]  = dp[1];
    //  3 1 4 2
    ll ans = dp[1];
    FOR(i , 2 , n){
        dp[i] = b[i-1];

        auto it = mp.lower_bound(a[i-1]+1);

        if(it != mp.begin()){
            it--;
            dp[i] += it->second;
        }

        mp[a[i-1]] = dp[i];

        auto it2 = mp.upper_bound(a[i-1]);

        while(it2 != mp.end() and it2->second <= dp[i]){
            auto temp = it2;
            ++temp;
            mp.erase(it2);
            it2 = temp;
        }
        ans = max(ans , dp[i]);
    }
    // return ans;
    cout << ans << endl;
}

int main(){
    fast ;    
    // testcases{
        // codejam ;
        solv();
    // } 
}


