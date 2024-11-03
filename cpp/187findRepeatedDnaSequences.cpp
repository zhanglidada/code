#include"./include/common.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int>    dna;
        vector<string>      res;
        string              word;

        // 长度为10及10以下的字符数组直接返回空
        if (s.length() <= 10)
            return res;

        for (int i = 0; i < s.length() - 9; i++)
        {
            word = s.substr(i, 10);
            if (dna.find(word) != dna.end())
            {
                // 子串第二次出现的时候放入res中，之后再出现不会再重复放入
                if (dna[word] == 1)
                    res.push_back(word);

                dna[word] += 1;
            }
            else
                dna[word] = 1;  // 第一次出现的子串插入map中
        }

        return res;
    }
};