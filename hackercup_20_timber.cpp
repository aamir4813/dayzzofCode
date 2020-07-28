#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool comp (const pair<ll , ll> &a , const pair<ll , ll> &b){
	return a.first <= b.first;
}

void solv(){
    ll n;
    cin >> n ;
	vector<pair<ll , ll > > arr;
	for(int i = 0 ; i < n ; ++i){
		ll a , b ;
		cin >> a >> b ;
		arr.emplace_back(a , b);
	}
	sort(arr.begin() , arr.end() , comp);

	map<ll , ll> dp;
	ll res = 0 ;
	for(auto x : arr){
		ll index = x.first ;
		ll height = x.second ;	
		
		dp[index + height] = max(dp[index+height] , dp[index] + height);
		dp[index] = max(dp[index] , dp[index-height] + height);
		res = max({res , dp[index] , dp[index + height]});
	}

	cout << res << endl;
}

int main(){

    int tt = 1;
    cin >> tt;

    for(int i = 1; i <= tt ; ++i){
        cout << "Case #"<<i <<": ";
        solv();
    }
}


