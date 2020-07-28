#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll arr[200001] = {-1};

void solv(){
    int n ;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        ll a ;
        cin >> a;
        arr[i] = a;
    }

    ll prev_MAX = INT_MIN ;
    ll ans = 0 ;

    for(ll i = 0; i < n ; ++i){
        if(i == 0 ){
            if(i == n-1){
                ans++;
            }       
            else if(arr[i] > arr[i+1]){
                ans++;
            }     

            continue;
        }
        prev_MAX = max(prev_MAX , arr[i-1]);

        if(arr[i] > prev_MAX && (i == n-1 || arr[i] > arr[i+1])){
            ans++;
        }

    }
    cout << ans << endl;
   
}

int main(){
    int tt;
    cin >> tt;
    int i = 1;
    while(tt--){
        cout << "Case #"<<i++ <<": ";
        solv();
    }
}