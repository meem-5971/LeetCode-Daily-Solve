class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int mxT = 0;
        for (int i = 0; i < times.size(); i++) {
            times[i].push_back(i); //appends friend's index
            mxT = max(mxT, times[i][1]);
        }

        //sorting according to arrival time
        sort(times.begin(), times.end());

        typedef pair<int,int> pii; // pair is <LeaveTime, chairNo>

        //min heap based on leave time
        priority_queue<pii, vector<pii>, greater<pii>> pq;


        set<int> s; // this set stores all the available chairs
        for (int i = 0; i <= 10000; i++)
            s.insert(i);

        for (int t = 1, i = 0; t <= mxT; t++) {
            //if any chairs become free
            while (!pq.empty() and pq.top().first <= t) {
                s.insert(pq.top().second);
                pq.pop();
            }
            //assign chairs to incoming friend
            while (i < times.size() and times[i][0] <= t) {
                int cur = *s.begin(); //empty chair

                if (times[i][2] == targetFriend)
                    return cur;
                s.erase(cur);
                pq.push({ times[i][1], cur }); //chair booked
                i++;
            }
        }

        return 10000;
    }

};
