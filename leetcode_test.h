//
// Created by winterless on 2020/2/9.
//

#ifndef LEETCODE_CONTEST_LEETCODE_TEST_H
#define LEETCODE_CONTEST_LEETCODE_TEST_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

struct KeyValue {
    string key;
    int value;
};


class Solution {
public:
    // contest 170
    string freqAlphabets(string s); // 1309
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries); // 1310
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id,
                                          int level); // 1311
    int minInsertions(string s); // 1312

};

#endif //LEETCODE_CONTEST_LEETCODE_TEST_H
