int Solution::solve(int A, int B) {
    
    // return ((A-1 + 8-A) + ())
    return min(A-1,B-1)+min(8-A,8-B)+min(A-1,8-B)+min(8-A,B-1);
}
