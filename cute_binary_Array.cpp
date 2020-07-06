/*
Cute Binary Arrays
Problem Description

You are given some binary numbers and their positions on a number line.
A cute window is a window that has equal number of 1s and 0s in it and the size of this window is the difference between the position of boundary elements.

You have a magical OR operation, using which you can make any 0 into 1 by ORing it with 1.

Find and return the maximum possible size of the cute window.



Problem Constraints
1 <= length(A) + length(B) <= 105

0 <= A[i], B[i] <= 109



Input Format
The first argument contains an integer array, A, representing the positions of the 0s.

The second argument contains an integer array, B, representing the positions of the 1s.



Output Format
Return an integer representing the maximum possible size of the cute window.



Example Input
A = [1, 5, 10]
B = [2]


Example Output
9


Example Explanation
We can OR the 0 at position 10 and then select all the 1s and 0s.
Endpoints are at 10 and 1, thus the size of the cute window will be 10 - 1 = 9.
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long int
map<ll, ll> mp;
vector<pair<ll, ll>> arr;
ll maxsize, startindex;
ll isCheck()
{

    int n = arr.size();

    ll temp[n];

    ll min, mx;
    int i;

    temp[0] = ((arr[0].first == 0) ? -1 : 1);
    min = arr[0].first;
    mx = arr[0].first;
    //   0 1 1 1 0 1 1 1 1 0 1 1 1 1 1
    //  -1 0 1 2 1 2 3 4 5 4 5 6 7 8 9
    for (i = 1; i < n; i++)
    {
        temp[i] = temp[i - 1] + ((arr[i].first == 0) ? -1 : 1);
        if (temp[i] < min)
            min = temp[i];
        if (temp[i] > mx)
            mx = temp[i];
    }

    ll mapper[mx - min + 1];

    for (i = 0; i < mx - min + 1; i++)
        mapper[i] = -1;
    ll ans = INT_MIN;
    // cout << "Val : \n";
    for (i = 0; i < n; i++)
    {

        if (temp[i] == 0)
        {
            maxsize = i + 1;
            startindex = 0;
            ans = max(ans, abs(arr[startindex].second - arr[startindex + maxsize - 1].second));
        }

        if (mapper[temp[i] - min] == -1)
            mapper[temp[i] - min] = i;
        else
        {
            if ((i - mapper[temp[i] - min]) >= maxsize)
            {
                maxsize = i - mapper[temp[i] - min];
                startindex = mapper[temp[i] - min] + 1;
                ans = max(ans, abs(arr[startindex].second - arr[startindex + maxsize - 1].second));
                // cout << arr[startindex].second << "  " << arr[startindex + maxsize - 1].second<<" "<< ans << endl;
            }
        }
    }
    ans = max(ans, abs(arr[startindex].second - arr[startindex + maxsize - 1].second));
    if (maxsize == -1)
        return 0;
    else
        return ans;
}

int solve(vector<int> &A, vector<int> &B)
{
    mp.clear();
    for (int i = 0; i < A.size(); ++i)
    {
        mp[A[i]] = 0;
    }
    for (int j = 0; j < B.size(); ++j)
    {
        mp[B[j]] = 1;
    }
    arr.clear();

    for (auto x : mp)
    {
        arr.emplace_back(x.second, x.first);
    }
    int n = A.size();
    int m = B.size();
    ll lo = min({*min_element(B.begin(), B.end()), *min_element(A.begin(), A.end())});
    ll hi = max({*max_element(B.begin(), B.end()), *max_element(A.begin(), A.end())});

    ll check = 0;
    for (auto x : arr)
    {
        if (x.first == 0)
        {
            check--;
        }
        else
            check++;
    }
    // cout << check << " : check \n";
    ll ans;
    if (check == 0 || (check < 0 && (-1 * check) % 2 == 0))
    {
        // cout << " yes";
        ans = abs(hi - lo);
    }
    else if (check > 0)
    {
        maxsize = -1, startindex = 0;
        ans = isCheck();
    }
    else
    {
        int n = arr.size();
        ans = max({abs(arr[0].second - arr[n - 2].second), abs(arr[1].second - arr[n - 1].second)});
    }
    // 100010011
    // 100111000
    // 01110001
    return ans;
}

int main()
{
    freopen("file.in", "r", stdin);
    // freopen("output.txt" , "w" , stdout);

    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        int m;
        cin >> m;
        vector<int> vrr(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> vrr[i];
        }

        cout << solve(arr, vrr) << endl;
    }
}

/*
  A6 - 10 9 5 8 7 4
  B4  - 6 3 2 1
    1 2 3 4 5 6 7 8 9 10
    1 1 1 0 0 1 0 0 0 0
*/
