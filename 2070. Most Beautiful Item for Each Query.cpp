class Solution {
public:
static bool cmp(int price, vector<int>& item) {
        return item[0] > price;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        for (int i=1; i<n; i++)
            items[i][1] = max(items[i][1], items[i-1][1]);
        vector<int> ans;
        for (auto &price : queries) {
            int idx = upper_bound(items.begin(), items.end(), price, cmp) - items.begin() - 1;
            if (idx < 0) ans.push_back(0);
            else ans.push_back(items[idx][1]);
        }
        return ans;
    }                   
};