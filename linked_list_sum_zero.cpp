//
// Created by winterless on 2019/9/1.
//
#include <iostream>
#include <map>


using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

        if (NULL == head) return NULL;
        ListNode res(0);
        res.next = head;
        int cur = 0;
        map<int, ListNode*> dic;
        dic.insert(pair<int,ListNode*>(0, &res));
        while (head) {
            cur += head->val;
            if (dic.find(cur) == dic.end()) {
                dic.insert(pair<int,ListNode*>(cur, head));
            }
            else {
                ListNode* error = dic.find(cur)->second;
                int error_val = cur;
                while (error != head) {
                    error = error->next;
                    error_val += error->val;
                    if (dic.find(error_val) != dic.end() && error != head) dic.erase(error_val);
                }
                dic.find(cur)->second->next = head->next;
            }
            head = head->next;
        }
        return res.next;
    }
};