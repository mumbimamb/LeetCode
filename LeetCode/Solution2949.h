#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;


class Solution2949
{
public:

    #define ll long long

    bool isVowel(char ch) { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; }

    // Return the number of non-empty beautiful substrings in the given string 
    // s. Vowels are 'a', 'e', 'i', 'o', and 'u'.
    //
    // A string is beautiful is vowels = consonants AND
    // (vowels * consonants) % k == 0
    //
    long long beautifulSubstrings(string s, int k) {
        
        // If k is greater than the size of string s, then no substring is
        // beautiful
        if (k > s.size())
        {
            return 0;
        }

        ll a = 0, b = 0, ans = 0;
        unordered_map<ll, unordered_map<ll, ll>> mp;
        mp[0][0] = 1;

        for (char ch : s) {
            ++(isVowel(ch) ? a : b);


            for (auto& [z, count] : mp[a - b])
                if ((a - z) * (a - z) % k == 0)
                {
                    ans += count;
                }

            ++mp[a - b][a % k];
        }

        return ans;
    }
};

