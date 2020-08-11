#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solv(){
    ll n;
    cin >> n ;
    
    vector<ll> arr(n) , dp(n+1 , INT_MAX);

    for(int i = 0 ; i < n ; ++i){
        cin >> arr[i];
    }
    // here dp[i] repesents : element at which subsequence of length i ends

// because len 0 in not available at least we have len = 1 with one element
    dp[0] = INT_MIN;
    // think something we can place a value at that length..
    // like in earlier version if you have 
    // two index same length...than we'll always prefer the smaller one
    // that might lead to more chances of getting that more longer increasing
    // sequence...

/*
Testcase :
1 
8
1 5 2 3 4 9 6 10 
*/
    

// There is an update .... actually we are storing values in dp
// in increasing order so can we use binary search ?
// Voilla

    for(int i = 0 ; i < n ; ++i){

            ll j = upper_bound(dp.begin() , dp.end() , arr[i]) - dp.begin();
            // cout << j << " " << endl;
            if(dp[j-1] < arr[i] and dp[j] > arr[i]){
                dp[j] = arr[i];
            }
    }


    // for(int i = 0 ; i <= n ; ++i){
    //     cout << dp[i] << " ";   
    // }
    // cout << "\n";
    for(int i = n ; i >= 1 ; --i){
        if(dp[i] != INT_MAX){
            cout << i << endl;
            return ;
        }
    }
}

int main(){

    int tt = 1;
    cin >> tt;

    for(int i = 1; i <= tt ; ++i){
        // cout << "Case #"<<i <<": ";
        solv();
    }
}


