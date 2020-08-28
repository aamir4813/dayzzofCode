int fact(int n)
{
    if(n==1)
        return 1;
    long long int f = (1LL *n*fact(n-1))%1000003;;
    return f;
}

int Solution::findRank(string A) {
    string B;
    B=A;
    
    
    sort(B.begin(),B.end());
    int i=0;
    int mod=1000003;
    int count=0;
    if(A.length()==1)
    return 1;
    while(i< A.length() && B[i]<A[0])
    {
        count+=((fact(A.length()-1))%mod);
        i++;
    }
    if(B[i]==A[0])
    {
        count = (count + findRank(A.substr(1,A.length()-1)))%mod;
        return count;
    }
}
