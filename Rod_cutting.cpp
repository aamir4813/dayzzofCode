/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input Format
n, size of array Ai, value of array elements

Constraints
1<= n <= 10^5 1<= Ai <=10^5

Output Format
Maximum value obtainable by cutting up the rod and selling the pieces.

Sample Input
5
1 2 3 4 5
Sample Output
5
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
#define pi pair<int , int>
#define pll pair<ll , ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define fast ios::sync_with_stdio(0) ; cin.tie(0) ;
#define fastcout ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
const ll mod = 1e9 + 7;
void solv() {
	ll n ;
	cin >> n;
	vi arr(n);
	for(int i  = 0 ; i  < n ;  ++i){
		cin >> arr[i];
	}
	vi dp(arr.begin() , arr.end());
	for(int i = 1 ; i < n ; ++i){
		for(int j = 0 ; j < i ; ++j){
			dp[i] = max(dp[i] , dp[i-j -1] + dp[j]);
		}
	}
	cout << dp[n-1] << endl;
}

int main() {
	fast;
	int tt;
	// cin >> tt;
	tt =1;
	while (tt--) {
		solv();
	}
	return 0;
}