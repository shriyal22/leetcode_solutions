class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // priority_queue<int> pq;
        // queue<vector<int>> q;
        int sz = tasks.size();
        vector<int> counter(26);
        int mf = 0;
        for (int i = 0; i < sz; i++){
            counter[tasks[i] - 'A']++;
            mf = max(mf, counter[tasks[i] - 'A']);
        }
        
        int numOfMax = 0;
        for (int i = 0; i < 26; i++){
            if (counter[i] == mf) numOfMax++;
        }

        int time = (n+1)*(mf-1) + numOfMax;
        return max(time, sz);
        // int time = 0;
        // while (!q.empty() || !pq.empty()){
        //     ++time;
        //     if (!pq.empty()){
        //         if (pq.top() - 1)
        //             q.push({pq.top() - 1, time + n});
        //         pq.pop();
        //     }
        //     if (!q.empty() && q.front()[1] == time){
        //         pq.push(q.front()[0]);
        //         q.pop();
        //     }
        // }
        // return time;
    }
};