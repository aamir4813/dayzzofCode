#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
vector<int> dp;
int doSome(int a , int b){

	if(a == 0){
		return dp[a]=1;
		// cout << "yes" << endl;
	}
	else if(a < 0){
		return 0;
	}
	else if(dp[a] != -1)
		return dp[a];

	ll ans = (1LL*doSome(a-b , b) + 1LL*doSome(a-1 , b))%mod;

	return dp[a] = ans;
}

void solv(){
	int n , m ;
	cin >> n >> m ;
	dp.assign(n+1 , -1);
	cout << doSome( n , m) << endl;
}
int main() {
	int tt;
	cin >> tt;
	while(tt--){
		solv();
	}
	return 0;
}