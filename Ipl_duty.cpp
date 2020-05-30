/*
In IPL 2025, the amount that each player is paid varies from match to match. The match fee depends on the quality of opposition, the venue etc.

The match fees for each match in the new season have been announced in advance. Each team has to enforce a mandatory rotation policy so that no player ever plays three matches in a row during the season.

Nikhil is the captain and chooses the team for each match. He wants to allocate a playing schedule for himself to maximize his earnings through match fees during the season.

Input Format
Line 1: A single integer N, the number of games in the IPL season.

Line 2: N non-negative integers, where the integer in position i represents the fee for match i.

Constraints
N < 1000000 a[i] < 1000

Output Format
The output consists of a single non-negative integer, the maximum amount of money that Nikhil can earn during this IPL season.

Sample Input
8
3 2 3 2 3 5 1 3
Sample Output
17
Explanation
(Explanation: 3+3+3+5+3)

*/


#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 

vector<vector<int>> dp;

void solv() {
	int n ;
	cin >> n ;

	vi arr(n);
	for(int i = 0 ; i < n ; ++i){
		cin >> arr[i];
	}

	vector<int> dp(n);

	dp[0] = arr[0];
	dp[1] = arr[1];
	dp[2] = arr[2];

	for(int i = 3 ; i < n ; ++i){
		dp[i] = min(dp[i-1] , min(dp[i-2] , dp[i-3])) + arr[i];
	}
	int sum = accumulate(arr.begin(), arr.end() , 0);
	int ans = min(dp[n-1] , min(dp[n-2] , dp[n-3]));
	cout << sum - ans << endl;;
}


int main () {
	solv();
	return 0;
}


/*
8
3 2 3 2 3 5 1 3
*/