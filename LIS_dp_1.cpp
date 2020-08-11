#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// LIS with dp-1

void solv(){
    ll n;
    cin >> n ;

    vector<ll> arr(n) , dp(n);

    for(int i = 0  ; i < n ; ++i){
        cin >> arr[i];
    }
    // Here dp[i] represent ...  at any index max Len
    for(int i = 0 ; i < n ; ++i){
        for(int j = i ; j >= 0 ; --j){
            if(arr[j] <= arr[i] )
            dp[i] = max(dp[i] , dp[j] + 1);
        }
    }

    cout << dp[n-1] << endl;
}

int main(){

    int tt = 1;
    cin >> tt;

    for(int i = 1; i <= tt ; ++i){
        // cout << "Case #"<<i <<": ";
        solv();
    }
}


