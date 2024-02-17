class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int,vector<int>, greater<int>> pq;

        for(int i=1;i<n;i++){
            int jump=heights[i]-heights[i-1];
            if(jump>0){
                pq.push(jump);

                if(pq.size()>ladders){
                    int diff = pq.top();
                    pq.pop();
                    bricks -= diff;
                    if(bricks<0) return i-1;
                }
            }            
        }
        return n-1;
    }
};