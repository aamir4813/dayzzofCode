/*
You are given a line of n colored squares in a row, numbered from 1 to n from left to right. The i-th square initially has the color ci.

Let's say, that two squares i and j belong to the same connected component if ci=cj, and ci=ck for all k satisfying i<k<j. In other words, all squares on the segment from i to j should have the same color.

For example, the line [3,3,3] has 1 connected component, while the line [5,2,4,4] has 3 connected components.

The game "flood fill" is played on the given line as follows:

At the start of the game you pick any starting square (this is not counted as a turn).

Then, in each game turn, change the color of the connected component containing the starting square to any other color.

Find the minimum number of turns needed for the entire line to be changed into a single color.

Input Format
The first line contains a single integer n (1≤n≤5000) — the number of squares.

The second line contains integers c1,c2,…,cn (1≤ci≤5000) — the initial colors of the squares.

Constraints
Output Format
Print a single integer — the minimum number of the turns needed.

Sample Input
8
4 5 2 2 1 3 5 5
Sample Output
4
Explanation
In the example, a possible way to achieve an optimal answer is to pick square with index 5 as the starting square and then perform recoloring into colors 2,3,5,4 in that order.
*/


#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 

vector<vector<int>> dp;

int doSome(vi &arr , int i , int j ){
	
	if( i == j){
		return dp[i][j] = 1;
	}
	if(dp[i][j] != 0)
		return dp[i][j];
	if(arr[i] == arr[j]){
		return dp[i][j] = 1 + doSome(arr , i+1 , j-1);
	}

	int a = doSome(arr , i , j-1);
	int b = doSome(arr , i+1 , j );

	return dp[i][j] = 1 + min(a , b);
}

void solv() {
	
	int n ;
	cin >> n ;
	vi vec(n);
	for(int i = 0 ; i < n ; ++i){
		cin >> vec[i] ;
	}

	int i = 0 ;
	vi arr;
	while( i  < n ){
		arr.push_back(vec[i]);
		while(i+1 < n && vec[i] == vec[i+1]){
			i++;
		}
		i++;
	}
	
	n = arr.size();
	dp.assign(n+1 ,vi (n+1 , 0));
	// cout << doSome(arr , 0 , n-1 ) - 1 << endl ;

	
}

int main () {
	int tt;
	// cin >> tt;
	tt =1;
	while(tt--){
		solv();
	}
	return 0;
}






/*
8
3 2 3 2 3 5 1 3
*/