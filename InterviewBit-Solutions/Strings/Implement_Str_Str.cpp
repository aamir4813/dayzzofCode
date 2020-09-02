int Solution::strStr(const string A, const string B) {
    
     if (B[0] == '\0') return 0;
        for (int i = 0; i < A.size(); i++) {
            bool isMatched = true; 
            for (int j = 0; j < B.size(); j++) {
                if (A[i + j] == 0) return -1;
                if (A[i + j] != B[j]) {
                    isMatched = false;
                    break;
                }
            }
            if (isMatched) return i;
        }
        return -1;
}
