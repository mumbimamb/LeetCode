#pragma once

/*
    https://leetcode.com/problems/k-items-with-the-maximum-sum/
*/

class Solution2600
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) 
    {
        // if k > numOnes + numZeroes + numNegOnes, return error
        if (k > numOnes + numZeros + numNegOnes)
        {
            return NULL;
        }

        // If numOnes => k, return k
        if (numOnes >= k)
        {
            return k;
        }

        // Grab as much as numOnes as you can if numOnes < k
        // k -= numOnes
        k -= numOnes;

        // If numZeros => k, return numOnes
        if (numZeros >= k)
        {
            return numOnes;
        }

        // Grab as much as numZeros as you can if numZeros < k
        // k -= numZeros
        k -= numZeros;

        // return numOnes - k
        return numOnes - k;
    }
};