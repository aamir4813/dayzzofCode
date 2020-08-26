#define ll long long int
int Solution::solve(int n, vector<int> &A) {

    ll pre=0;
    ll index[n+1]={0};

    for(int i=0;i<n;i++)
        pre += A[i];
    if(pre%3!=0)return 0;
    ll sf=0;
    
    for(int i=n-1;i>=0;i--)
    {
       sf+=A[i];
        if(sf==(pre/3))
            index[i]=1;
    }
    
    for(int i=0;i<n;i++){
        index[i]=index[i-1]+index[i];
    }
    ll temp=0,ans=0;
    pre=pre/3;
    for(int i=0;i<n-1;i++){
            temp+=A[i];
            if(temp==pre)
                ans+=index[n-1]-index[i+1];
    }
    return ans;
}
