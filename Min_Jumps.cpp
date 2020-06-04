/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Print the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input Format
n, size of array Ai, array elements

Constraints
1<=n<=5000 1<=Ai<=10^5

Output Format
Number of minimum jumps

Sample Input
11
1 3 5 8 9 2 6 7 6 8 9
Sample Output
3
Explanation
3 (1-> 3 -> 8 ->9)
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
const ll mod = 1000000007;

int doSome(vi &arr , int index ,int mn){
	int n = arr.size();

	if(index >= n-1){
		return mn;
	}

	int a = INT_MAX;
	for(int i = index+1 ; i < index+arr[i] ; ++i){
		a = min(a,doSome(arr ,i , mn+1));
	}
	return a;
}


void solv() {


	int n ;
	cin >> n ;

	vi arr(n);
	for(int i = 0 ; i < n ; ++i){
		cin >> arr[i];
	}

	vi dp(n , n+1);
	dp[n-1] = 0;

	for(int i = n-2; i >= 0 ; --i){
		for(int j = 1 ; j <= arr[i] ; ++j){
			if(i+j < n){
				dp[i] = min({dp[i] , 1 + dp[i+j]});
			}else{
				break;
			}
		}
	}

	// for(auto x : dp){
	// 	cout << x <<  " "; 
	// }
	// cout << endl;
	cout << dp[0] << endl;
	// cout << doSome(arr , 0 , 1);
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
