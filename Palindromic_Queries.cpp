// Palindromic Queries


/*

Given a string s and m queries . Each query consists of (l,r) where 1 <= l <= r <= n(size of string).

You need to print whether l to r is a palindromic string or not.

A string can be called palindrome if its reverse is same as itself . Ex - "aba" .

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
vector<vector<bool>> dp;
void doSome(string s){
		int n = s.size();

		for(int len = 1 ; len <= n ; ++len){
			for(int i = 0 ; i <= n-len ; ++i){
				int j = i + len - 1;

				if(s[i] == s[j]){
					if(len <= 2){
						dp[i][j] = true;
					}

					else if(dp[i+1][j-1]){
						dp[i][j] = true;
					}
				}
			}
		}
}

void solv(){
	int n ;
	string s;
	cin >> n>> s;
	dp.assign(n+1 , vector<bool>(n+1 , false));
	doSome(s);

	int q;
	cin >> q ;
	while(q--){
		int l , r;
		cin>> l >> r;
		cout << (dp[--l][--r] ? "YES" : "NO") << endl;
	}
}
int main() {
	int tt = 1;
	// cin >> tt;
	while(tt--){
		solv();
	}
	return 0;
}
