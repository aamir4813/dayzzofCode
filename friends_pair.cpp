/*
Given n friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. 
Find out the total number of ways in which friends can remain single or can be paired up.

Constraints
1<= n < 30

Output Format
Output t lines each line describing the answer.

Sample Input
1
3

Sample Output
4

Explanation :
{1}, {2}, {3} : all single {1}, {2,3} : 2 and 3 paired but 1 is single. {1,2}, {3} 
: 1 and 2 are paired but 3 is single. {1,3}, {2} :
 1 and 3 are paired but 2 is single. Note that {1,2} and {2,1} are considered same.

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
vector<vector<bool>> dp;
int doSome(int n){
		if( n <= 2)
				return n;

		return doSome(n-1) + (n-1) *doSome(n-2);
}

int bottomUp(int n){
	vector<int> arr(n+1);

	if(n <=2)
		return n;

	arr[1] = 1;
	arr[2] = 2;

	for(int i = 3 ; i <= n ; ++i){
		dp[i] = dp[i-1] + (i-1) * dp[i-2];
	}

	return dp[n];
}

void solv(){
	int n ;
	cin >> n ;

	cout<< doSome(n) << endl;

}
int main() {
	int tt;
	cin >> tt;
	while(tt--){
		solv();
	}
	return 0;
}