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
    
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j ){
            if(dp[j] < arr[i] and dp[j+1] > arr[i]){
                dp[j+1] = arr[i];
            }
        }
    }


    // for(int i = 0 ; i <= n ; ++i){
    //     cout << dp[i] << " ";   
    // }
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


