string Solution::convert(string A, int B) {
    
    // cout << A << end;
    int n = A.length();
    if(B==1)
        return A;
    string arr[B];
    int row=0;
    bool down=true;
    for(int i=0; i<n; i++){
        arr[row].push_back(A[i]);
        if(row==B-1)
            down=false;
        else if(row==0)
            down=true;
        if(down)
            row++;
        else
            row--;
    }
    string ans;
    for(int i=0; i<B; i++)
        ans+=arr[i];
    
    return ans;   
}
