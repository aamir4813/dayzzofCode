   long long int n = A.size();
    long long int sum =0 , sum_square = 0;
    for(long long int i = 0 ;i < n ; i++){
        sum += (long long int)A[i];
        sum_square += (long long)(A[i])*(long long )(A[i]);
    }
    long long int orginal_sum = n*(n+1)/2;
    long long int orginal_sum_square = n*(n+1)*(2*n+1)/6;
    long long int temp , temp2 , missing , repeated;
    temp = orginal_sum - sum;
    temp2 = (orginal_sum_square - sum_square) / temp;
    missing = (temp + temp2)/2;
    repeated = (temp2 - temp)/2;
    // cout << missing << " "<< repeated << endl;
