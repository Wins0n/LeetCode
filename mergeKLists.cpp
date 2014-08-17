#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
private:
    int heapsize;
    std::vector<ListNode*> arr;
    ListNode* head;
    
private:
    void buildHeap()
    {
        for (int i = heapsize/2; i >= 1; --i)
        {
            minHeapify(i);
        }
    }
    
    void minHeapify(int i)
    {
        int l = (i<<1);
        int r = l + 1;
        int smallest = i;

        if (l <= heapsize && arr[l]->val < arr[smallest]->val)
        {
            smallest = l;
        }
        if (r <= heapsize && arr[r]->val < arr[smallest]->val)
        {
            smallest = r;
        }
        if (smallest != i)
        {
            ListNode* p = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = p;
            minHeapify(smallest);
        }
    }
    
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        int n = lists.size();
        int i = 0;
        arr.clear();
        arr.push_back(NULL);
        for (i = 0; i < n; ++i)
        {
            if (lists[i])
            {
                arr.push_back(lists[i]);
            }
        }
        heapsize = arr.size() - 1;
        if (heapsize == 0)
        {
            return NULL;
        }

        head = new ListNode(0);
        buildHeap();

        ListNode* p = head;
        while (heapsize > 1)
        {
            p->next = arr[1];
            p = p->next;
            arr[1] = arr[1]->next;
            if (arr[1] == NULL)
            {
                if (heapsize > 1)
                {
                    arr[1] = arr[heapsize];
                    --heapsize;
                }
                else
                {
                    break;
                }
            }
            minHeapify(1);
        }
        p->next = arr[1];
        p = head->next;
        delete head;
        
        return p;
    }
};

int main(int argc, char** argv)
{
    Solution sln;
    
    return 0;
}

