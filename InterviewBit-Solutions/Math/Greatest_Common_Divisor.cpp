int gcd2(int A , int B){
    
    if( A == 0)
        return B;
        
    return gcd2(B%A , A);
}

int Solution::gcd(int A, int B) {
    
    // return __gcd(A , B);
    if(B == 0)
        return A;
    return gcd2(A , B);
}
