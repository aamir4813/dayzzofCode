/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compare(Interval a,Interval b)
{
    return(a.start<b.start);
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
     vector<Interval> ans;
    if(intervals.empty())
    return {newInterval};
    intervals.push_back({newInterval.start,newInterval.end});
    sort(intervals.begin(),intervals.end(),compare);
    int i;
     for(i=0;i<intervals.size()-1;i++){
            if(intervals[i].end>=intervals[i+1].start){
               intervals[i+1].start=intervals[i].start;
               intervals[i+1].end=max(intervals[i].end , intervals[i+1].end);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        ans.push_back(intervals[i]);
return ans;

