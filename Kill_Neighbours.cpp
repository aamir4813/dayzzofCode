/*
Given an array A, we can pick a number and delete it, then all the numbers which are 1 less or 1 more also get deleted. The number that we picked is added to the overall score. We need to maximise the score.

Input Format
The first line contains integer n that shows how many numbers are there in the sequence.
The second line contains n integers a1, a2, …, an.

Constraints
1 ≤ n ≤ 10^5 1 ≤ a[i] ≤ 10^5

Output Format
Print a single integer — the maximum number of points that can be earned.

Sample Input
9
1 2 1 3 2 2 2 2 3
Sample Output
10
Explanation
Consider the third test example. At first step we need to choose any element equal to 2. After that step our sequence looks like this [2, 2, 2, 2]. Then we do 4 steps, on each step we choose any element equals to 2. In total we earn 10 points.
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



void solv() {
	ll n ;
	cin >> n ;
	vi arr(n);
	for(int i = 0 ; i < n ; ++i){
		cin >>arr[i];
	}
	map<int , int>mp;

	for(auto x : arr){
		mp[x]++;
	}
	sort(arr.begin(), arr.end());
	arr.resize(unique(arr.begin(), arr.end()) - arr.begin());


	// 1 2 3
	vi dp(n+1);
	dp[0] = arr[0] * mp[arr[0]];
	n = arr.size();

	for(int i = 1 ; i < n ; ++i){
		if(arr[i] - arr[i-1] != 1){
			dp[i] = dp[i-1] + mp[arr[i]] * arr[i];
		}
		else{
			if(i - 2 >= 0)
				dp[i] = max({dp[i-1] , mp[arr[i]]*arr[i] + dp[i-2]});
			else
				dp[i] = max({dp[i-1] , mp[arr[i]] *arr[i]});
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
