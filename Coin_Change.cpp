/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, In how many ways can we make the change? The order of coins doesn’t matter.

Input Format
First line of input contain two space separated integers N and M. Second line of input contains M space separated integers - value of coins.

Constraints
1<=N<=250 1<=m<=50 1 <= Si <= 50

Output Format
Output a single integer denoting the number of ways to make the given change using given coin denominations.

Sample Input
10 4
2 5 3 6
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

int doSome(vi &arr , int index , int target){
	int n = arr.size();

	if(target < 0 )
		return 0;
	if(target == 0){
		return 1;
	}
	if(index == n){
		return 0;
	}

	int a = doSome(arr , index , target - arr[index]);
	int b = doSome(arr , index+1 , target);

	return a+b;
}

void bottomUp(vi&coins , int n , int k){
	
	vi dp(n+1 , 0);
	dp[0] = 1;
	for(int i = 0 ;  i < k ; ++i){
		for(int j = coins[i] ; j <= n ; ++j){
			dp[j] += dp[j-coins[i]];
		}
	}
	cout << dp[n] << endl;
}

void solv() {
	int n , k;
	cin >>n >> k;
	vi coins(k);
	for(int i = 0 ; i < k ; ++i){
		cin >>coins[i];
	}

	// cout << doSome(coins , 0 , n);
	bottomUp(coins , n , k);
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
