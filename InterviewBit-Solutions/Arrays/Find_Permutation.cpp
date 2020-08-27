vector<int> Solution::findPerm(const string A, int B) {
    int n = A.size();
    
    vector<int> result;

    int smaller = 1;
    int larger = B;
    
    for(int i = 0; i < n; i++){
        if(A[i] == 'I'){
            result.push_back(smaller);
            smaller++;
        }
        else{
            result.push_back(larger);
            larger--;
        }
    }
    if(A[n - 1] == 'I'){
        result.push_back(smaller);
    }
    else{
        result.push_back(larger);
    }
    return result;
}
