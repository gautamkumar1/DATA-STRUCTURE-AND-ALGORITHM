#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeListHelper(vector<ListNode *> &lists, int low, int end)
    {
        // Base case
        if (low > end)
        {
            return NULL;
        }
        if (low == end)
        {
            return lists[low];
        }
        int mid = low + (end - low) / 2;
        ListNode *left = mergeListHelper(lists, low, mid); // calling for left
        ListNode *right = mergeListHelper(lists, mid + 1, end);
        return merge(left, right);
    }
    ListNode *merge(ListNode *&leftHead, ListNode *&rightHead)
    {
        ListNode *dummyHead = new ListNode(-1);
        ListNode *dummyTail = dummyHead;
        while (leftHead != NULL && rightHead != NULL)
        {
            if (leftHead->val < rightHead->val)
            {
                dummyTail->next = leftHead;
                leftHead = leftHead->next;
            }
            else
            {
                dummyTail->next = rightHead;
                rightHead = rightHead->next;
            }
            dummyTail = dummyTail->next;
        }
        dummyTail->next = (leftHead != NULL) ? leftHead : rightHead;
        return dummyHead->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
        {
            return NULL;
        }
        int low = 0;
        int end = lists.size() - 1;
        return mergeListHelper(lists, low, end);
    }
};
// T(N) : O(NlogK) and S(N) : O(logK)
int main()
{
    // create three sorted linked lists
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode *> lists = {l1, l2, l3};

    Solution solution;

    ListNode *mergedList = solution.mergeKLists(lists);

    // print out the merged list
    while (mergedList != NULL)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}
