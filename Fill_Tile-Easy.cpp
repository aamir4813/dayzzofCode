/*
Given a “2 x n” board and tiles of size “2 x 1”, print the number of ways to tile the given board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.

Input Format
The only line of the input contains N to represent the second dimension of the board.

Constraints
1<= N < 100000000

Output Format
Print the number of ways to tile the given board .

Note: Since the answer can be huge, print ans % 1000000007.

Sample Input
3
Sample Output
3
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

	if(n <= 3){
		cout << n << endl; return ;
	}

	ll a = 2;
	ll b = 3;

	ll ans = 0 ;
	for(ll i = 4 ; i <= n ; ++i){
		ans = (a + b)%mod ;
		a = b % mod;
		b = ans;
	}

	cout << ans << endl;
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
