
/*

4star:
standard input/output: 2s/128000 KB

Given an integer X find an integer Y such that Y has exactly two set bits in its binary representaion and abs(X- Y) is minimum.
Input
Input contains a single integer X.

Constraints
1 <= X <= 10^15
Output
Print a single integer, the minimum value of abs(X- Y).

Sample input 1
5

Sample output 1
0

Explanation: Y=5.

Sample input 2
1

Sample output 2
2

Explanation: Y=3

*/

#include<bits/stdc++.h>
using namespace std;

#define vi vector<ll> 

typedef long long int ll;

void solv(){
	ll n ;
	cin >> n ;
	ll y = 0 ;

	if(n == 0){
		cout << 3 << endl;
		return;
	}
	ll k = 0; 
	for(ll i = 31 ; i>=0 ; --i ){
		bool bit = (n) &(1 << i);

		if(bit == 1){
			y |= (1 << i);
			k++;
		}
		if(k == 2){
			cout << abs(n - y) << endl;
			return;
		}
	}
	ll left = 1;
	ll x = 0; 
	for(ll i = k ; i <= 1 ; ++i){
		// bool bit = ( n ) & (i << i);
		y = (y) | ( 1 | (x << left));
		// cout << bit << endl;
		left++;
	}
			cout << abs(n - y) << endl;

}

int main () {
	ll tt;
	// cin >> tt;
	tt =1;
	while(tt--){
		solv();
	}
	return 0;
}

