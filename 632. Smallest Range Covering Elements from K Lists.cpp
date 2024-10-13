class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();  // The number of lists
        vector<int> indices(k, 0);  // To store the current index for each list
        vector<int> range = {0, INT_MAX};  // To store the smallest range found

        // Infinite loop to continuously search for the smallest range
        while (true) {
            int curMin = INT_MAX, curMax = INT_MIN;  // To track the current minimum and maximum values
            int minListIndex = 0;  // To track which list has the current minimum value

            // Loop over each list to find the current minimum and maximum values
            for (int i = 0; i < k; i++) {
                int currentElement = nums[i][indices[i]];

                // Update the current minimum value and track the list where it is found
                if (currentElement < curMin) {
                    curMin = currentElement;
                    minListIndex = i;
                }

                // Update the current maximum value
                if (currentElement > curMax) {
                    curMax = currentElement;
                }
            }

            // If the current range is smaller than the previously stored range, update the range
            if (curMax - curMin < range[1] - range[0]) {
                range[0] = curMin;
                range[1] = curMax;
            }

            // Move to the next element in the list that had the smallest value
            // If we have reached the end of that list, break out of the loop
            if (++indices[minListIndex] == nums[minListIndex].size()) {
                break;  // Stop the loop if any list is fully processed
            }
        }

        return range;  // Return the smallest range found
    }
};
