#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution2273
{
public:
    vector<string> removeAnagrams(vector<string>& words) {

        // the first index since index 0 can never be i; < i < words.length
        vector<string> return_words = { words[0] };

        unordered_map<char, int> previous_letter_count = letter_counter(words[0]);
        
        for (int index = 1; index < words.size(); index++)
        {
            unordered_map<char, int> current_letter_count = letter_counter(words[index]);

            // if they are not anagrams, add to return words and update previous_letter_count
            if (previous_letter_count != current_letter_count)
            {
                return_words.push_back(words[index]);
                previous_letter_count = current_letter_count;
            }
            // if they are anagrams, do not add to return_words and keep previous_letter_count the same
        }

        return return_words;
    }

    unordered_map<char, int> letter_counter(string word)
    {
        unordered_map<char, int> letter_count;

        for (auto letter : word)
        {
            letter_count[letter]++;
        }

        return letter_count;
    }
};

