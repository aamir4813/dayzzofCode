#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solv(){
    ll n;
    cin >> n ;

    string a;
    cin >> a ;

    map<char , ll> mp;
    for(int i = 0 ; i < n ; ++i){
        mp[a[i]]++;
    }

    if(abs(mp['A'] - mp['B']) == 1){
        cout << 'Y'<< endl;
    }
    else{
        cout << 'N' << endl;
    }
}

int main(){

    freopen("alchemy_input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int tt = 1;
    cin >> tt;

    for(int i = 1; i <= tt ; ++i){
        cout << "Case #"<<i <<": ";
        solv();
    }
}


// 