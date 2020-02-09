#include <iostream>
#include "leetcode_test.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution solution;
    vector<vector<string>> watchVideos = {{"A", "B"},
                                          {"C"},
                                          {"B", "C"},
                                          {"D"}};
    vector<vector<int>> friends = {{1, 2},
                                   {0, 3},
                                   {0, 3},
                                   {1, 2}};
    vector<string> res = solution.watchedVideosByFriends(watchVideos, friends, 0, 1);
    for (string& val : res) {
        cout << val << " " << endl;
    }
    return 0;
}