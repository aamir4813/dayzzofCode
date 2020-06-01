/*
Let's define a new game of snakes and ladders. There is only one dimension of n cells. Each cell either contains a snake or ladder. One can simply take a jump of not more than k cells. A person cannot step on a snake. However, s/he can jump over a snake.
Alice is excited to play this game and is asking you to calculate the number of ways to finish the game.
Game starts at 1st cell and ends at the nth cell. It is guaranteed that there is a ladder at the 1st cell.
Since the number can be large, output the answer modulo (109+7).

Input Format
First line contains 2 integers N and K, denoting the number of cells and the maximum possible jump respectively. The next line contains N integers, x1, x2,…., xN, where xi is either 0 or 1. xi=0 denotes that there is a ladder in ith cell, xi=1 denotes that there is a snake in ith cell.

Constraints
1<=N<=10^4 1<=K<=10^4 0<=xi<=1

Output Format
Output a single integer denoting the number of ways to finish the game modulo (109+7).

Sample Input
5 2
0 0 0 1 0
Sample Output
2

Explanation
There are 2 ways to reach the 5th cell - [1,2,3,5] and [1,3,5].
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
#define fastcout fast cout.tie(0);
const ll mod = 1e9 + 7;

int dphere(vi &arr , int k){
	int n =arr.size();

	vector<ll> dp(n , 0);

	dp[0] = 1;

	for(int i = 1 ; i < n ; ++i){
		if(arr[i] == 0){
			for(int j =1 ; j <= k ; ++j){
				if(i-j >= 0 && arr[i-j] == 0 && i >= j){
					dp[i] += dp[i-j];
					dp[i] %= mod;
				}
			}
		}
	}
	return dp[n-1];
}

int doSome(vi &arr , int index , int k){
	int n = arr.size();
	if(index == n-1){
		return 1;
	}

	int ans = 0 ;
	for(int i = 1 ; i <= k ; ++i){
		if(index+i < n && arr[index+i] == 0)
			ans += doSome(arr , index+i , k);
	}
	return ans;
}

void solv() {
	int n , k ;
	cin >> n >> k;

	vi arr(n);
	for(int i = 0 ; i <n ; ++i){
		cin >> arr[i];
	}
	if(arr[n-1] == 1){
		cout << 0 << endl;
		return;
	}
	// cout << doSome(arr , 0 , k) << endl;
	cout << dphere(arr , k) <<endl;
}

int main() {
	fast;
	int tt;
	// cin >> tt;
	tt = 1;
	while (tt--) {
		solv();
	}
	return 0;
}