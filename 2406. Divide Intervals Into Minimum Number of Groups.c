class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>startT,endT;
        //storing start and end time in two separate vectors
        for(auto u:intervals){
            startT.push_back(u[0]);
            endT.push_back(u[1]);
        }

        sort(startT.begin(),startT.end());
        sort(endT.begin(),endT.end());

        int  cnt=0,res=0;

        int i=0,j=0;


        while(i<intervals.size()){
            //if the start points are smaller then the end point, there should be separate groups for each end points
            if(startT[i]<=endT[j]){
                cnt++;
                i++;
            }

            //if start points are greater then the end points, the interval won't intersect with others while staying in same group
            else{
                cnt--;
                j++;
            }
            res=max(res,cnt);
        }
        return res;

    }
};
