class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, 
        greater<pair<long long int, int>>> occupiedRooms;
        vector<int> ans(n, 0);
        sort(meetings.begin(), meetings.end());

        for(int i=0;i<n;i++){
            availableRooms.push(i);
        }

        for(auto meet: meetings){
            long long start = meet[0], end=meet[1];
            while(occupiedRooms.size() > 0 && occupiedRooms.top().first <= start){
                availableRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }

            if(availableRooms.size() > 0){
                int room = availableRooms.top();
                availableRooms.pop();
                ans[room]++;
                occupiedRooms.push({end, room});
            } else {
                auto roomDeets = occupiedRooms.top();
                occupiedRooms.pop();
                long long int endTime = roomDeets.first, room = roomDeets.second;
                ans[room]++;
                occupiedRooms.push({endTime + end - start, room});
            }
        }
        return max_element(ans.begin(), ans.end()) - ans.begin();  
    }
}; 