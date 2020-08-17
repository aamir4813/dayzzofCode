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



vll read_som(ll n , ll k){

    vll arr(n);

    FOR(i , 0 , k-1){
        cin >> arr[i];
    }
    ll a , b , c , d;
    cin >> a>> b >> c >> d;

    FOR(i , k , n-1){
        arr[i] = ((a*arr[i-2] + b * arr[i-1] + c )%d) +1 ;
    }

    return arr;
}

bool doSome(vll &driver , vll &cluster , ll mid ){
   int index = 0 ;
    ll n = cluster.size();


    for(auto x : driver){
        
        if(n == index) return true;

        int left = cluster[index];

        // if(mid == 13){
        //     cerr << "LEFT : " << left << endl;
        // }

        for( ; index < n ;  ){

            int right = cluster[index];

            // if value of cluster is on left...
            ll gap = 0 ;            
            if(left >= x){
                gap = right - x;
            }
            else if(right <= x){
                gap = x - left;
            }
            else{
                // here driver lies between left and right,,,
                // so always try to choose min...

                gap = right - left ;
                // because i have to reach back at that point whoever comes and goes back
                if((right - x) < (x - left)){
                    gap += right - x;
                }
                else{
                    gap += x - left ;
                }
            }
            // if(mid == 13){
            //     cerr << "RIGHT : " << right << " GAP : "<< gap << " Val:  " << x << endl;
            // }
            if(gap > mid)
                break;
            
            index++;
        }

    }
    if(index == n){
        return true;
    }

    return false;

}

void solv(){
    ll n , m , k , s;
    cin >> n >> m >> k >> s ;

    vll driver = read_som(n , k);
    // i just write down m as n in cluster size...
    // that really frustrating during contest ..could not make it work 
    // Fucking Typo....
    // i was able to find...
    vll cluster = read_som(m , k);
    sort(all(driver));
    sort(all(cluster));
    // for(auto x : driver ){
    //     cout << x << " ";
    // }
    // cout << endl;
    // for(auto x : cluster ){
    //     cout << x << " ";
    // }
    // cout << endl;
    ll start = 0  , end = 2e9+1 ;
    ll ans = end ;


    while(start <= end){
        ll mid = start + (end - start)/2;

        bool status = doSome(driver , cluster , mid);
        // cerr << mid <<" " << status << endl;
        if(status){
            ans = mid;
            end = mid -1;
        }
        else{
            start = mid+1;
        }
    } 

    cout << ans << endl;
}

int main(){
    fast ;    
    testcases{
        codejam ;    
        solv();
    } 
    time;
}


