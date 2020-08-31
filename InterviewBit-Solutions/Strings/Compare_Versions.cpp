int Solution::compareVersion(string A, string B) {
       unsigned long long int p = 0, q = 0;
    for (int i=0,j=0; (i<A.size() || j<B.size()); )
    {
        while (i < A.size() && A[i] != '.')
        {
            p = p * 10 + (A[i] - '0');
            i++;
        }
        while (j < B.size() && B[j] != '.')
        {
            q = q * 10 + (B[j] - '0');
            j++;
        }
        if (p > q)
        {
            return 1;
        }
        if (q > p)
        {
            return -1;
        }
        p = q = 0;
        i++;
        j++;
    }
    return 0;
