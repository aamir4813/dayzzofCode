
/*
Agarwal has a habit of creating Ajeeb Samasya as usual and Shubham always comes to his rescue. 
This is time he has created another samasya which is as follows. Read carefully! 
Shubham has an array of N integers and an integer K. He wants to create a subsequence of this array with some conditions applied.
 He builds ceil(N/K) blocks of this array with size of each block as [i∗K+1,min((i+1)∗k,N)] for 0≤i≤N/K. 
 For two consecutive integers in this subsequence, he wants the integers to be of two different blocks. 
 (It is not a compulsion to have one integer from each block). Also, lets say the indexes of any two 
 integers of this subsequence be i and j, then he wants |i−j| != K. Shubham takes the sum of integers 
 in the subsequence. He wonders what can be the maximum sum obtained? Help shubham in this samasya.

Input Format
First line contains two space separated integers : N and K Second line contains N space separated integers
 : A1, A2,…, AN

Constraints
1 ≤ N ≤ 2∗10^6

1 ≤ K ≤ N

−10^9 ≤ Ai ≤ 10^9

Output Format
print a single integer describing maximum sum that can be obtained.

Sample Input
6 5
5 4 3 2 1 -1
Sample Output
5
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
vector<vector<bool>> dp;

void solv(){
	int n , k;
	cin >> n >> k ;
	vector<int> arr(n);

	for(auto &x : arr){
		cin >> x ;
	}	
	
	int ans = 0 ;

	int mx1 = INT_MIN , mx2 = INT_MIN , index = -1 , prevIndex , prevMx1 , prevMx2;
	int curr_block = 0;
	int block_size = ceil(n/k);
	bool first_block = true;
	for(int i = 0 ; i < n ; ++i){
		curr_block++;
		if(first_block == false){
			if(i-k == prevIndex){
				arr[i] += prevMx2;
			}
			else{
				arr[i] += prevMx1;
			}
		}

		if(mx1 < arr[i] ){
			index = i;
			mx2 = mx1;
			mx1 = arr[i];
		}
		else if(mx2 < arr[i] ){
			mx2 = arr[i];
		}

		if(curr_block == k){
			curr_block = 0;
			first_block = false;
			prevIndex = index;
			if(prevMx1 == mx1){
				prevMx1 = mx1;
				prevMx2 = mx2;
			}
			else{
				prevMx1 = mx1;
				prevMx2 = mx2;
			}
			ans = max(ans , mx1);
			// cout << ans << " ";
		}
	}
	if(curr_block){
		ans = max(ans , mx1);
	}
	cout << ans << endl;

}
int main() {
	int tt;
	// cin >> tt;
	tt = 1;
	while(tt--){
		solv();
	}
	return 0;
}


//  i have just solved this but did't checked because i got the statement of this question not any plateform
// to judge it