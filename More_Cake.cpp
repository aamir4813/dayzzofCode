/*
https://www.codechef.com/PCO12020/problems/MORECAKE
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
ll extra , left;
void solv(){
	ll val ,n , s , k;
	cin >> val >> n >>  s >> k;

	ll temp = s;

	for(int i = 0 ; i < n ; ++i){
		val -= temp;
		temp *= k;
	}

	extra += val;
	if( val >  0){
		cout << "POSSIBLE " << val << endl;
	}
	else if(val == 0){
		cout << "POSSIBLE" << endl;
	}
	else {
		cout << "IMPOSSIBLE " << -1*val << endl; 
	}

}

int main() {
	fast;
	int tt;
	cin >> tt;
	// // tt =1;
	extra = 0 ;
	while (tt--) {
		solv();
	}
	if(extra >= 0){
		cout << "POSSIBLE"<<endl;
	}
	else{
		cout << "IMPOSSIBLE"<< endl;
	}
	return 0;
}
