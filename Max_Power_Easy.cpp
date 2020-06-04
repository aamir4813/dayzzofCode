/*
Alice is fighting with an alien to save this planet. As alien is very powerful he needs some power to overcome him. Power points are represented in the form of an array containing both positive and negative powers but the problem is he can get power equal to the product of the subarray he selects. Help him to decide maximum power he can get.

Input Format
First line contains an integral value denoting the size of array 'n' and then next line represents the array elements.

Constraints
1<=n<=100000 Product of all numbers will fit in long long int.

Output Format
Single integer denoting the maximum power.

Sample Input
8
10 1 2 -13 0 7 -18 2 
Sample Output
20
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
	/*
	8
	10 1 2 -13 0 7 -18 2 
	*/
	int n ;
	cin >> n ;
	vi arr(n);

	for(int i = 0 ; i < n ; ++i){
		cin >> arr[i];
	}

	ll ans = 0 ;
	ll mn = 1 , mx = 1;
	bool wasThere = false;
	for(int i = 0 ; i < n ; ++i){

		if(arr[i] > 0){
			mx *= arr[i];
			mn = min(mn*arr[i] , 1LL);
			wasThere = true;
		}
		else if(arr[i] < 0 ){
			ll temp = mx;
			mx = max(mn * arr[i] , 1LL);
			mn = temp * arr[i];
		}
		else{
			mn = 1;
			mx = 1;
		}
		ans = max(ans , mx);
	}
	if(ans == 1 && !wasThere){
		cout << *max_element(arr.begin(), arr.end())<<endl;
		return ;
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
