int Solution::cpFact(int A, int B) {
    // Simple Maths here
    
    int x = __gcd(A , B );
    cout << x << " ";
    
    int val = A/x;
    
    while( B % val != 0 and val != 1){
        
    }
    return val;
}
