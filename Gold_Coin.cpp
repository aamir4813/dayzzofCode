/*

Tughlaq introduces a strange monetary system. He introduces copper coins and each coin has a number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. A coin can also be sold for gold. One can get as much grams of gold as the number written on the coin. You have one copper coin. What is the maximum weight of gold one can get from it?

Input Format
The input file contains a single integer n, the number on the coin.

Constraints
0 <= n <= 1 000 000 000

Output Format
Print the maximum weight of gold you can get.

Sample Input
12
Sample Output
13

*/
/*
states are very less .... and array range will overflow because n <=1e9
so bottom up with map will help
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

map<long , long> mp;
long doSome(long n){
	if(n < 11){
		return n;
	}
	
	if(mp.find(n)!= mp.end()){
		return mp[n];
	}
	long a = doSome(n/2);
	long b = doSome(n/3);
	long c = doSome(n/4);

	return mp[n] = max({a+b+c , n});
}
int bottomUp(int n){
	if(n <= 11)
		return n;
	vector<int> dp(n+1);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;

	for(int i = 5 ; i <= n ; ++i){
		dp[i] = max({dp[i/2] +dp[i/3] +dp[i/4] , i});
		// cout << dp[i] <<  " ";
	}

	cout << dp[n]<< endl;
}
void solv() {
	int n ;
	cin >> n ;

	// mp.clear();
	// for shorter range... bottomUp will work
	
	cout << doSome(n) << endl;;
}

int main() {
	// fast;
	int tt;
	// cin >> tt;
	tt = 1;;
	while (tt--) {
		solv();
	}
	return 0;
}