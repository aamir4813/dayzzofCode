#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll arr[1000002];
void solv(){
    ll n ;
    cin >> n;

    for(int i = 0 ;  i < n ; ++i){
        cin >> arr[i];
    }
    if(n <= 4){
        cout << 0 << endl;
        return ;
    }
    ll ans = 0 ;
    ll mn = 0;
    ll x = mn;
    ll y = 0;
    for(int i = 1; i < n ; ++i){
        if(  arr[i] > arr[i-1] ){
            x++;
            y = 0;
        }
        else if(arr[i] < arr[i-1]){
            y++;
            x = 0;
        }
        
        
        if(x > 3 or y > 3){
            ans++;
            x = 0 , y = 0;
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




