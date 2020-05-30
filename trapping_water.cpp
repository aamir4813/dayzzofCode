
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 

vector<vector<int>> dp;

void solv() {
	int n ;
	cin >> n ;
	vi arr(n) ;
	for(int i = 0  ; i < n ; ++i){
		cin >> arr[i];
	}

	vi left(n) , right(n);

	left[0] = arr[0];
	for(int i = 1 ; i  < n ; ++i){
		left[i] = max(left[i-1] , arr[i]);
	}
	right[n-1] = arr[n-1];

	for(int i = n-2 ; i>= 0 ; --i){
		right[i] = max(right[i+1] , arr[i]);
	}

	int ans = 0 ;
	for(int i =  0 ; i < n ; ++i){
		
			ans += min(right[i] ,left[i]) - arr[i];
	}
	cout << ans  << endl;
}


int main () {
	solv();
	return 0;
}


/*
8
3 2 3 2 3 5 1 3
*/