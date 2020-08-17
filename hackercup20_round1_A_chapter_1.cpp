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


ll peri(ll x , ll y){
    
    return (2LL*x + 2LL*y);
}

void solv(){
    ll n , k , w ;
    cin >> n >> k >> w ;

    vll L(n) , H(n);

    ll aP , bP , cP , dP;

    FOR(i , 0 , k-1){
        cin >> L[i];
    }
    cin >> aP >> bP >> cP >> dP ; 
    ll aQ , bQ , cQ , dQ;

    FOR(i , 0 , k-1){
        cin >>H[i];
    }

    cin >> aQ >> bQ >> cQ >> dQ;

    FOR(i , k , n-1){
        L[i] = (aP*L[i-2] + bP*L[i-1] + cP)%dP + 1; 
    }

    FOR(i , k , n-1){
       H[i] = (aQ*H[i-2] + bQ*H[i-1] + cQ)%dQ + 1; 
    }

    // for(auto x : L){
    //     cout << x <<" ";
    // }
    // cout << endl;
    // for(auto y : H){
    //     cout << y << " ";
    // }
    // cout << endl;
    
    vll ans(n);

    vll right ;

    FOR(i , 0 , n-1){

        if(i == 0 ){
            ans[i] = peri( H[i] , w);
            right.push_back(L[i]+w);
        }
        else{
            ll prev_x = L[i];

            auto itX = upper_bound(right.begin() , right.end() , L[i]);
            auto index = abs(distance(itX , right.begin()));
        
            if(binary_search(all(right) , L[i])){
                ll val = -1;
                ll mx_h = H[index-1];
                FOR(j , index-1 , i-1){
                    if(mx_h <= H[j]){
                        mx_h = H[j];
                        val = j;
                    }
                }
                // border sharing
                index = val;
                // cout << "on boundry : "<< i <<" " << index << " " << L[i] <<endl;
                ll bottom_fix = right[index] - L[i];
                ll height_fix = abs(H[i] - H[index]);
                // cout << height_fix << " " << ans[index];
                // cout << mx_h << endl;
                    ans[i] = ans[index] - H[index] + height_fix - 2LL * bottom_fix + 2LL*w + H[i];
                }
            else if(itX == right.end()){
                // No boundary
                // cout << "No boundry : " << index << " " << L[i] <<endl;
                
                ans[i] = ans[index-1] + peri(w , H[i]);

            }
            else{
                // yes crossed
                // index -;/
                ll val = -1;
                ll mx_h = H[index];
                FOR(j , index , i-1){
                    if(mx_h <= H[j]){
                        mx_h = H[j];
                        val = j;
                    }
                }

                // cout << "Crossed boundry : " << index << " " << H[index] <<endl;
                index = val;
                ll bottom_fix = right[index] - L[i];
                ll height_fix = abs(H[i] - H[index]);

                ans[i] = ans[index] - H[index] + height_fix - 2LL* (bottom_fix) + 2LL*w + H[i];
                
            }
            ans[i] = ans[i] % mod;
            right.push_back(L[i]+w);
        }
    }

    ll answer = 1LL;
    for(ll x : ans ){
        // cout <<x << " ";
        answer = (answer * x)%mod;
    }
    // cout << endl;
    cout << answer << endl;

}

int main(){
    fast ;    
    testcases{
        codejam ;    
        solv();
    } 
}


