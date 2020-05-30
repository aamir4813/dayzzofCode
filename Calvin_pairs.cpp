/*
Calvin wakes up early one morning and finds that all his friends in the hostel are asleep. To amuse himself, he decides to play the following game : he draws a sequence of N squares on the ground, numbered 1 to N, and writes an integer in each square. He starts at square k (1 ≤ k ≤ N). The game consists of one forward phase followed by one backward phase.

:- In the forward phase, Calvin makes zero or more moves of the following type : if his current position is p, he can jump to p+1 or p+2 as long as he stays within the N squares.

:- In the backward phase, Calvin makes zero or more moves of the following type : if his current position is p, he can jump to p−1 or p−2 as long as he stays within the N squares.

He plays such that he finally ends up at square 1, and then he stops. He starts with a score of 0, and each time he jumps from square i to square j, he adds the integer written in square j to his score. Find the maximum score Calvin can obtain by playing this game. Recall that Calvin must start at square k and end at square 1. The integer on the square where he starts is not included in his score.

For example, suppose N = 5 and the numbers in squares are 5, 3, −2, 1, 1. If k = 2, Calvin starts on the second square. He can make a forward move to square 4, another to square 5, a backward move to square 4, another to square 2, and another to square 1. His total score is 1+1+1+3+5 = 11. You can check that this is the maximum score possible.

Input Format
• Line 1 : Two space-separated integers, N and k, with 1 ≤ k ≤ N. • Line 2 : A space-separated sequence of N integers, the numbers in squares 1, 2 . . . , N .

Constraints
1 ≤ N ≤ 2*10^5 -1000 <= Ai <= 1000

Output Format
A single line with a single integer, the maximum score Calvin can obtain by playing the game.

Sample Input
5 2
5 3 -2 1 1
Sample Output
11

*/

#include<bits/stdc++.h>
using namespace std;

void solv(){
	int n , k ;
	cin >>  n >> k;
	vector<int> arr(n);

	for(int i = 0  ; i < n ; ++i){
		cin >> arr[i];
	}

	vector<int> dpf(n+1 , 0);
	// cout << k<< endl;
	k--;
	if(k == 0 ){
		cout << 0 << endl;
	}

	// cout << k << endl;
	for(int i = k+1 ;  i < n ; ++i){
		// cout << arr[i] << endl;
			if(  i == 1){
				dpf[i] = arr[0] + arr[1];
			}
			else{
				dpf[i] = arr[i] + max(dpf[i-1] , dpf[i-2]);
			}
	}

	vector<int> dpb(n);
	dpb[0] = arr[0];
	dpb[1] = arr[0] + arr[1];
	for(int i = 2 ;  i < n ; ++i){
		dpb[i] = arr[i] + max(dpb[i-1] , dpb[i-2]);
	}

	// for(auto x : dpf){
	// 	cout << x <<" ";
	// }
	// cout << endl;
	// for(auto x : dpb){
	// 	cout << x <<" ";
	// }

	int ans = INT_MIN;
	for(int i  = k ; i < n ; ++i){
		ans = max(ans , dpb[i] + dpf[i] - arr[i]);
	}

	cout << ans << endl;
}

int main () {
	solv();
	return 0;
}

/*
	Approach here:
	i just calculated max sum by hops of +1 and +2 from kth index till n
	and before that index obviosuly every index will have 0 sum...
	for example

	if  k = 3
	then forward_arr[N] = {0 , 0 , 0 , blah , blah , blah ... , N}

	and 
	another calculation is needed for backward moves..
	that will be from 1st index to Nth...

	and after that just find maxAns from these moves...
	Hope it will help

	in mySolution :
	dpf[i] denotes-> maxSum till index i from kth index

	dpb[i] denotes-> maxSum till index i from 1st index
*/