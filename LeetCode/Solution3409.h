#pragma once

#include <vector>

using std::vector;

/*
* 3409: Longest Subsequence With Decreasing Adjacent Difference
* https://leetcode.com/problems/longest-subsequence-with-decreasing-adjacent-difference/description/

*/

class Solution3409 {
public:
    static int longestSubsequence(vector<int>& nums) {

        std::vector<int> results(nums.size(), 1);


        for (int last_index_of_subarray = 0; last_index_of_subarray < nums.size(); last_index_of_subarray++)
        {
            for (int compare_to = 0; compare_to < last_index_of_subarray; compare_to++)
            {
                if (nums.at(last_index_of_subarray) <= nums.at(compare_to))
                {
                    results.at(last_index_of_subarray) = results.at(compare_to) + 1;
                    //results.at(last_index_of_subarray) += 1;
                }
            }
        }
        
        return 1;
    }
};

/* notes */

// Solution 1
// 
// [6, 5, 3, 4, 2, 1]
// 0 = [1, 3, 2, 4, 5] (6)
// 1 = [2, 1, 3, 4] (5)
// 2 = [1, 1, 2] (3)
// 3 = [2, 3] (4)
// 4 = [1] (2)
// 
// Feels wrong

// Solution 2
// 
// [6, 5, 3, 4, 2, 1]
// i = 0 to length - 2 and j = 1 to length - 1
// [ 1, 1, 1, 1, 1, 1 ] (initial array)
// [ 1, 2, 2, 2, 2, 2] i = 0, j = 1 to 5
// [ 1, 2, 3, 3, 3, 3] i = 1, j = 2 to 5
// [ 1, 2, 3, 3, 4, 4] i = 2, j = 3 to 5
// [ 1, 2, 3, 3, 5, 5] i = 3, j = 4 to 5
// [ 1, 2, 3, 3, 5, 6] i = 4, j = 5 to 5


// Solution 3
// 
// Looked up video on YouTube, skimmed it and got final array 
// to see if I can work out how it works based on limited info
// and to make solution more memorable to mes
// 
// [nums[i]][difference]; i = nums.size() - 1
//
// [6, 5, 3, 4, 2, 1]
// 
// [1, 2, 1, 1, 1, 1] (1)
// [1, 2, 3, 1, 1, 1] (2)
// [1, 2, 3, 3, 1, 1] (3)
// [1, 2, 3, 3, 5, 1] (4)
// [1, 2, 3, 3, 5, 6] (5)
//
// Fails at indices 2 and 3. Looked at video again. It's not 
// simply last_index_of_subarray <= compare_to
// Look if we can increase subsequence and then steal what's
// at compare_to index