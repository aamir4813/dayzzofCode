/*
https://www.codechef.com/PCO12020/problems/LVPOL
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

vvi graph;
vi visited;
int doSome(int val , int cnt) {

	if (visited[val] == 1) {
		return cnt;
	}
	visited[val] = 1;
	for(auto x : graph[val]){
		if(visited[x] == 0){
			// cout << x<< " ";
			return doSome(x , cnt+1);
		}
	}
	return cnt;
}

void solv() {
	ll n , k ;
	cin >> n >> k;
	graph.assign(n + 1 , vi());
	visited.assign(n + 1 , 0);

	for (int i = 0 ; i < k ; ++i) {
		int a , b ;
		cin >> a >> b ;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> arr;
	for (int i = 0 ; i < n ; ++i) {
		if (visited[i] == 0) {
			int cnt = doSome(i , 1);
			arr.push_back(cnt);
		}
	}
	cout <<arr.size() << endl;
	sort(arr.begin(), arr.end());
	for(auto x : arr){
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	fast;
	int tt;
	cin >> tt;
	// tt =1;
	while (tt--) {
		solv();
	}
	return 0;
}
/*
1 6 4
0 1
1 2
3 4
4 3
*/