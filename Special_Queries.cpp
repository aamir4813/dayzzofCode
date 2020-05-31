/*
i don't think this is Optimal Approach..xD xD

A number X is special if X is divisible by sum of digits of X. For example 24 is special because it is divisible by 6 (2+4). You are given Q queries where in each query you are given q[i] and you have to report the q[i]th positive special number.
Input
First line of input contains Q. Next Q lines contains q[i].

Constraints :
1 <= Q <= 10000
1 <= q[i] <= 100000
Output
For each query print the q[i]th special number in a new line.

Sample Input
5
1
2
10
11
12

Sample Output
1
2
10
12
18

*/


#include<bits/stdc++.h>
using namespace std;

#define vi vector<ll> 
typedef long long ll;

vector<ll> dp(100001 , 0);
ll cal(ll n){
	ll res = 0;

	while(n){
		res += (n % 10);
		n /= 10;
	}
	return res;
}

void solve(){

	ll j = 1;
	for(ll i = 1 ; i <= 1000000; ++i){
		ll rem = cal(i);
		if(i % rem == 0){
			dp[j++] = i;
			if(j == 100000){
				return;
			}
		}
	}
}

void solv(){
	int n ;
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		int x;
		cin >> x;
		cout << dp[x] << "\n";			
	}
	// cout << endl;
}

int main () {
	ll tt;
	solve();
	// cin >> tt;
	tt =1;
	while(tt--){
		solv();
	}
	return 0;
}


