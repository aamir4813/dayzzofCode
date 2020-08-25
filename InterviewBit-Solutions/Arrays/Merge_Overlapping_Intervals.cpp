/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool comp(Interval a, Interval b){
     
     return a.start < b.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
   
    int n = A.size();
    
    if(n == 0)
        return A;
    
    sort(A.begin() , A.end() , comp);
    vector<Interval> ans;
    int j = 0;
    ans.push_back(A[0]);
    for(int i = 1  ;i < n ; ++i){
        if(A[i].start <= ans[j].end){
            ans[j].end = max(ans[j].end , A[i].end); 
        }
        else{
            ++j;
            ans.push_back(A[i]);
        }
    }
    
    return ans;
}
