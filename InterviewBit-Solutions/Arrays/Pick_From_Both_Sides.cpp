int Solution::solve(vector<int> &A, int B) {

    int n = A.size();
    
    vector<int> window(B+1);
    
  
    window[0] = 0;
    for(int i = 1 ;i <= B ; ++i){
        window[i] = window[i-1] + A[i-1]; 
    }
    
    int index = B-1;
    
    int ans = window[B];
    
    int val = 0;
    for(int i = n-1 ; i >= n-B ; --i){
        int current = window[index] + A[i] + val;
        val += A[i];
        // cout << index << " " << current << endl;
        index--;
        ans = max(ans , current);
    }
    
    return ans;
}

/*
	Here i've use window this can be easily reduced but i'm lazy enough doing so....so You can imagine it's already O(1) Space xD
*/
