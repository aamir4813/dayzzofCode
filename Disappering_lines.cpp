/*
	i forgot the ques... xD
	testcases:
	5 5 1
	1 2
	1 3
	2 4
	3 5
	4 5
	1 3

	here first line follows N , M , K
	N is where we have reach..
	M is no of edges..
	K lines after M lines
	in k paired value denotes..
	time = 1 ... edges from 3 will disappear....

	so find minimum... Cost to reach there if possible otherwise -1
*/

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 

vector<vector<int>> graph;
vector<int> visited;
void doSome(vi &node){
	int cnt = 1 ;
	int t = 0 ;
	queue<int> q;

	int n = graph.size();
	
	visited.assign(n , 0);
	q.push(0);
	
	int sz = q.size();
	visited[0] = 1;
	node[0] = 1;
	// cout << sz << endl;
	queue<int> p;
	int temp = 0;
	while(!q.empty()){
		temp++;
		int tp = q.front();
		q.pop();
		// cout << tp << " ";
		for(auto x : graph[tp]){
			if(visited[x] == 0){
				p.push(x);
				visited[x] = 1;
			}
			node[x] = min(node[x] , cnt);
			// cout << x << " - " << node[x] << endl;
		}

		if(sz == temp){
			sz = p.size();
			q = p;
			queue<int> k;
			p = k;
			temp = 0;
			++cnt;
			// cout << cnt << " ";
		}
	}

	// for(auto x : node){
	// 	cout << x << " ";
	// }
}

void solv(){
	int n , m , k;
	cin >> n >>  m >> k;
	graph.assign(n , vi());

	for(int i = 0 ; i < m ; ++i){
		int u , v ;
		cin >> u >> v;
		graph[--u].push_back(--v);
		graph[v].push_back(u);
	}
	map<int , int> timestamp;

	for(int i = 0 ; i < k ; ++i){
		int u , v ;
		cin >> u >> v;

		timestamp[--v] =  u;
	}
	vector<int> node(n ,n+1);

	doSome(node);

	for(int i = 0 ;  i < n ; ++i){
		if(timestamp.find(i) != timestamp.end() && node[i] > timestamp[i]){
			cout << -1 << endl;
			return;
		}
	}

	cout << node[n-1]+1 << endl;
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



