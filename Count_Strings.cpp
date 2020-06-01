/*
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints
1<=t<=100 1<=n<=90

Output Format
Print the number of all possible binary strings.

Sample Input
2
2
3
Sample Output
3
5
Explanation
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101
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
	int n ;
	cin >> n ;
	long no_zero = 1 , no_one = 1;

	long ans = 0 ;
	for(int i = 2;  i <= n ; ++i){
		long temp = no_zero;
		no_zero += no_one;
		no_one = temp;
	}
	ans = no_one + no_zero;
	cout << ans << endl;;

}

int main() {
	fast;
	int tt;
	cin >> tt;
	while (tt--) {
		solv();
	}
	return 0;
}
