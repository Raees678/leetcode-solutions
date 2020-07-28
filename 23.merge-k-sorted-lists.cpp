/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (31.00%)
 * Likes:    3167
 * Dislikes: 210
 * Total Accepted:    482.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 *
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    ListNode* return_list = nullptr;
    ListNode** current = &return_list;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        *current = l1;
        l1 = l1->next;
      } else {
        *current = l2;
        l2 = l2->next;
      }
      (*current)->next = nullptr;
      current = &((*current)->next);
    }

    if (l1) {
      *current = l1;
    } else {
      *current = l2;
    }

    std::cout << "finished merge" << std::endl;
    return return_list;
  }

  // this has a runtime of log(k)*(m+n), because we dont merge all k lists but
  // just the log of the lists
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (!lists.size()) {
      return nullptr;
    }

    // the interval tells you how many lists to look ahead
    for (int interval = 1; interval < lists.size(); interval *= 2) {
      // we always do want to merge the 0th list with some list so i MUST start
      // at 0
      // we always do want to merge the ith + interval list with some other list
      // so i MUSt end at lists.size() - interval
      //
      for (int i = 0; i < lists.size() - interval; i += interval * 2) {
        std::cout << "merging lists " << i << " and " << i + interval
                  << std::endl;
        lists[i] = merge2Lists(lists[i], lists[i + interval]);
      }
    }
    return lists[0];
  }

  // this has a runtime of k*(m+n).
  // ListNode* mergeKLists(vector<ListNode*>& lists) {
  //   ListNode* return_list = nullptr;
  //   ListNode** current = &return_list;

  //   bool element_added = false;
  //   do {
  //     element_added = false;
  //     ListNode* min_node = nullptr;
  //     int list_index = 0;
  //     for (int i = 0; i < lists.size(); ++i) {
  //       if (lists[i]) {
  //         if (!min_node || lists[i]->val < min_node->val) {
  //           min_node = lists[i];
  //           list_index = i;
  //         }
  //       }
  //     }

  //     if (min_node) {
  //       *current = min_node;
  //       lists[list_index] = lists[list_index]->next;
  //       (*current)->next = nullptr;
  //       current = &((*current)->next);
  //       element_added = true;
  //     }
  //   } while (element_added);

  //   return return_list;
  // }
};
// @lc code=end
