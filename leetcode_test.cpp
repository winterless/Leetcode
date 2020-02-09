//
// Created by winterless on 2020/2/9.
//

#include "leetcode_test.h"

string Solution::freqAlphabets(string s) {
    string res;
    for (unsigned long i = 0; i < s.length(); i++) {
        char cur;
        if (i + 2 < s.length() and s[i + 2] == '#') {
            cur = (char) ('a' + atoi(s.substr(i, 2).c_str()) - 1);
            i += 2;
        } else {
            cur = (char) ('a' + s[i] - '1');
        }
        res += cur;
    }
    return res;
}

vector<int> Solution::xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    // 0 ... a ... b ... n
    // op(a,b) = op2(op(0,a), op(0,b))
    // same -> 1, diff -> 0
    // A XOR B = C, C XOR B = A
    if (arr.empty()) {
        return {};
    }
    vector<int> memo;
    vector<int> res;
    memo.push_back(arr[0]);
    for (unsigned long i = 1; i < arr.size(); i++) {
        memo.push_back((unsigned int) memo[memo.size() - 1] ^ (unsigned int) arr[i]);

    }
    for (vector<int> &query : queries) {
        if (query[0] > 0) {
            res.push_back((unsigned int) memo[query[1]] ^ (unsigned int) memo[query[0] - 1]);
        } else {
            res.push_back(memo[query[1]]);
        }
    }
    return res;
}

bool cmpByValue(KeyValue keyValueA, KeyValue keyValueB) {
    if (keyValueA.value < keyValueB.value) {
        return true;
    } else if (keyValueA.value == keyValueB.value && keyValueA.key.compare(keyValueB.key) < 0) {
        return true;
    }
    return false;
}

vector<string>
Solution::watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id,
                                 int level) {
    int cur_level = 0;
    set<int> visited;
    unordered_map<string, int> frequencyMap;
    visited.insert(id);
    vector<int> curMembers = {id};
    vector<int> nextMembers;
    vector<KeyValue> sorter;
    vector<string> res;
    while (cur_level < level) {
        for (int member : curMembers) {
            for (int friend_ : friends[member]) {
                if (!visited.count(friend_)) {
                    visited.insert(friend_);
                    nextMembers.push_back(friend_);
                }
            }
        }
        curMembers = nextMembers;
        nextMembers = vector<int>();
        cur_level += 1;
    }
    for (int member : curMembers) {
        for (string video : watchedVideos[member]) {
            if (frequencyMap.count(video)) {
                frequencyMap[video]++;
            } else {
                frequencyMap.insert({video, 1});
            }
        }
    }
    for (pair<string, int> element : frequencyMap) {
        KeyValue keyValue;
        keyValue.key = element.first;
        keyValue.value = element.second;
        sorter.push_back(keyValue);
    }
    sort(sorter.begin(), sorter.end(), cmpByValue);
    for (KeyValue keyValue : sorter) {
        res.push_back(keyValue.key);
    }
    return res;
}

int Solution::minInsertions(string s) {
    // DP: Edit Distance Problem
    // ref: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/discuss/497790/C%2B%2B-or-DP-or-(24ms-9072)-(10mb-100)
    // 滑动成范围内相等花费的费用？
    int len = s.length();
    int dp[len + 2][len + 2];
    for (int i = 0; i < len; i++) {
        dp[i][i] = 0; // 自己相等为0
    }
    for (int i = 2; i <= len; i++) { // 从2开始，注意这个是i，实际上是j左k右
        for (int j = 0; j <= len - i; j++) { // i用来限制长度，和我之前做的offset一个东西
            int k = i + j - 1; // 也就是i = j - k - 1, 比如2,0,他们中间只有一个1值，所以理解为什么从2开始，1值必0
            if (s[j] == s[k] && i == 2) { // 左右相等且i=2，就是xxxxeexxxx这种情况
                dp[j][k] = 0;
            } else if (s[j] == s[k]) { // 左右相等非2，集成上一次的就好
                dp[j][k] = dp[j + 1][k - 1];
            } else {
                dp[j][k] = min(dp[j][k - 1], dp[j + 1][k]) + 1; // 左右不相等，注意edit distance,左边减少一个（就是变相的对位增加),或者右边,二选一
            }
        }
    }
    return dp[0][len - 1];
}