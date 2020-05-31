/*
	Question is not available but i'm providing in simple terms..

	you have to  maximize the area using thses sticks..
	first line is testcase
	second line how many pair N
	next N Line Follows:
	pair of size of sticks and their quantity
	
	You can make sqaure and Rectangles using these sticks..
	Then maximize the overall area possible..
	
	testcases like :
		1
		4
		5 6
		3 2
		4 3
		6 1

	Here output : 38

*/

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 

vector<vector<int>> dp;

bool comp(const pair<int , int> &a , const pair<int , int > &b){
	return a.first > b.first;
}

void solv(){
	int n;
	cin >> n ;
	vector<pair<int , int>> vec;

	priority_queue<pair<int , int>> q;
	for(int i = 0 ;  i < n ; ++i){
		int a , b;
		cin >> a >> b ;
		vec.emplace_back(a , b);
		// vec.push_back(a , b)
	}
	sort(vec.begin(), vec.end() , comp);
	
	// priority_queue<pair<int , int>> vec;
	int ans = 0 ; 
	for(int i = 0 ; i < n ; ++i){
		auto pr = vec[i];
		int rem = pr.second % 4;
		int cost = pr.second /4;

		ans += cost * pr.first * 4 ;

		bool k = false;
		if(rem >= 2){
			if(!q.empty()){
				ans += (q.top().first + pr.first)*2;
				q.pop();
				k = true;
			}
			if(!k)
				q.push({pr.first , rem});
		}
		// cout << pr.first << "  " <<ans <<  " " << rem << "  - " ;

	}
	cout << ans << endl;
}

int main () {
	int tt;
	cin >> tt;
	// tt =1;
	while(tt--){
		solv();
	}
	return 0;
}






