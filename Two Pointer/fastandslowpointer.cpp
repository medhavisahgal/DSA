#include <unordered_set>
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
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> s;
        ListNode *temp = head;
        while (temp)
        {
            if (s.find(temp->val) != s.end())
            {
                return true;
            }
            s.insert(temp->val);
            temp = temp->next;
        }
        return false;
    }
};