#pragma once

#include <vector>

using std::vector;

/*
You are given two integers memory1 and memory2 representing the available 
memory in bits on two memory sticks. There is currently a faulty program 
running that consumes an increasing amount of memory every second.

At the ith second (starting from 1), i bits of memory are allocated to the 
stick with more available memory (or from the first memory stick if both have
the same available memory). If neither stick has at least i bits of available
memory, the program crashes.

Return an array containing [crashTime, memory1crash, memory2crash], where 
crashTime is the time (in seconds) when the program crashed and memory1crash 
and memory2crash are the available bits of memory in the first and second 
sticks respectively.
*/

/* 
    Right now, can only do simple solution, definitely ways to make it faster.

    Loop, check what to add memory too, and exit once hit loop condition.

    Loop condition is excessive, memory1 and memory 2 are less than 2^32 so
    while excessive, it is a definite end.

*/

class Solution1860 {
public:
    static vector<int> memLeak(int memory1, int memory2) {
        int crash_time = 1, mem1_used = 0, mem2_used = 0;

        for (; crash_time < INT32_MAX; crash_time++)
        {
            if ((memory1 - mem1_used) >= (memory2 - mem2_used))
            {
                if (crash_time + mem1_used > memory1)
                {
                    break;
                }

                mem1_used += crash_time;
            }
            else
            {
                if (crash_time + mem2_used > memory2)
                {
                    break;
                }

                mem2_used += crash_time;
            }
        }

        return vector<int>{crash_time, memory1 - mem1_used, memory2 - mem2_used};
    }
};