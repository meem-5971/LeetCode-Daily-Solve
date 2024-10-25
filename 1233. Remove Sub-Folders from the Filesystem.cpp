class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>st(begin(folder),end(folder));
        vector<string>result;

        for(string& curr : folder){
            bool isSub=false;
            string tmp=curr;
            while(!curr.empty()){
                size_t pos =curr.find_last_of('/'); //returns the last index whose value is '\'

                curr=curr.substr(0,pos);

                if(st.find(curr)!=st.end()){
                    isSub=true;
                    break;
                }
            }
            if(!isSub){
                result.push_back(tmp);
            }
        }
        return result;
    }
};