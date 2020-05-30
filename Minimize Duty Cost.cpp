/*
In ICO School, all students have to participate regularly in SUPW. There is a different SUPW activity each day, and each activity has its own duration. The SUPW schedule for the next term has been announced, including information about the number of minutes taken by each activity.

Nikhil has been designated SUPW coordinator. His task is to assign SUPW duties to students, including himself. The school's rules say that no student can go three days in a row without any SUPW duty.

Nikhil wants to find an assignment of SUPW duty for himself that minimizes the number of minutes he spends overall on SUPW.

Input Format
A single integer N, the number of days in the future for which SUPW data is available.

N non-negative integers, where the integer in position i represents the number of minutes required for SUPW work on day i.

Constraints
N < = 1000000

Output Format
The output consists of a single non-negative integer, the minimum number of minutes that Nikhil needs to spend on SUPW duties this term

Sample Input
10
3 2 1 1 2 3 1 3 2 1
Sample Output
4
Explanation
(Explanation: 1+1+1+1)

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
	// int sum = accumulate(arr.begin(), arr.end() , 0);
	// cout << dp[n-1] << endl;	
	int ans = min(dp[n-1] , min(dp[n-2] , dp[n-3]));
	cout << ans << endl;
	// cout << sum - dp[n-1] << endl;;
}


int main () {
	solv();
	return 0;
}


/*
another testcase :
8
3 2 3 2 3 5 1 3
Output : 5


*/