#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solv()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    ll ans = 0;
    priority_queue<pair<ll, ll>> q;

    /*
    M = 3 
       -1 9 16 17 -9 19 -19  17
0 1 4 7 0 5 9  8  0  3   0   6
0 0 0 0 1 4 7  9  9  16  19  0

heap now = 7 5 9
*/
    // q.push({-11111111, 0});
    // for(int i = 0 ;)
    if(n-1 <= m){
        cout << 0 << endl;
        return;
    }
    for(int i = 0 ; i <= m ; ++i){
        if(arr[i] == 0 ){
            q.push({INT64_MIN , i});
        }
        else{
            q.push({-arr[i] , i});
        }
    }

    if(q.top().first == INT64_MIN){
        cout << -1 << endl;
        return;
    }

    for (int i = m+1; i < n; ++i)
    {

        while (q.top().second < i - m)
        {
            q.pop();
        }
        ans = q.top().first;
        
        // else
        // {
            if (q.top().first == INT64_MIN)
            {
                q.push({INT64_MIN, i});
                // continue;
            }
            else
            {   
                if(arr[i] == 0){
                    q.push({INT64_MIN , i});
                }
                else{
                    auto x = q.top().first;
                    q.push({x - arr[i], i});
                }
            }
        // }
        // cout << i << " " << ans << endl;
        // dp[i] = min(dp[i] , )
    }
    // return ans;
    cout << (ans == INT64_MIN ? -1 : -ans) << endl;
    
}

int main()
{

    freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
    freopen("output.txt" , "w" , stdout);
    int tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; ++i)
    {
        cout << "Case #"<<i <<": ";
        solv();
    }
}
