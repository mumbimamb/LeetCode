#include "Solution1991.h"

void Solution1991::work()
{
    vector<int> temp = {2, 3, -1, 8, 4};
    int answer = findMiddleIndex(temp);
}

// Find the index where sum of numbers to the left and right equal each 
    // other.
    //
    // Returns -1 if there is no valid middleIndex.
    //
    // Constraints: 1 <= nums.length <= 100. -1000 <= nums[i] <= 1000.
int Solution1991::findMiddleIndex(vector<int>& nums)
{
    int ERROR_NO_MIDDLE_INDEX = -1;

    if (nums.size() == 1)
    {
        if (nums.at(0) == 0)
        {
            return 0;
        }
        else
        {
            return ERROR_NO_MIDDLE_INDEX;
        }
    }

    int left_side_sum = 0;
    int right_side_sum = 0;

    for (auto it = nums.begin() + 1; it < nums.end(); it++)
    {
        right_side_sum += *it;
    }

    // [3, 0]
    for (auto it = nums.begin(); it < nums.end(); it++)
    {
        if (left_side_sum == right_side_sum)
        {
            return std::distance(std::begin(nums), it);
        }

        left_side_sum += *it;
        if (it + 1 != nums.end())
        {
            right_side_sum -= *(it + 1);
        }
    }

    return ERROR_NO_MIDDLE_INDEX;
}
