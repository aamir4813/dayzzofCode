/*
Given an array of integers A and an integer B, find and return the maximum value K such that there is no subarray in A of size K with sum of elements greater than B.
*/
#define ll long long int
bool isValid(vector<int> &arr, int target, int hops)
{

    ll sum = 0;
    int i = 0, j = 0;
    for (; i < hops; ++i)
    {
        sum += arr[i];
    }

    for (; i < arr.size(); ++i)
    {
        if (sum > target)
            return false;

        sum += arr[i] - arr[j++];
    }
    if (sum > target)
        return false;
    return true;
}

int Solution::solve(vector<int> &A, int B)
{

    int n = A.size();

    int s = 0, e = n;
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);

        if (isValid(A, B, mid))
        {
            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
    }

    return ans;
}