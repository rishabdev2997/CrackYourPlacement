/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * 
 * 
 *          Let's walk through the corrected code step by step with a dry run using an example linked list. We'll use the following list:

```
1 -> 2 -> 3 -> 4 -> 5
```

### Step 1: Find the Middle of the List
We use two pointers, `slow` and `fast`:
- `slow` moves one step at a time.
- `fast` moves two steps at a time.

**Iterations**:
- **Iteration 1**: 
  - `slow` at `1`, `fast` at `1`
  - After moving: `slow` at `2`, `fast` at `3`
- **Iteration 2**: 
  - `slow` at `2`, `fast` at `3`
  - After moving: `slow` at `3`, `fast` at `5`

Now, `slow` is at the middle of the list (`3`). The list remains:

```
1 -> 2 -> 3 -> 4 -> 5
```

### Step 2: Reverse the Second Half of the List
Starting from the node after `slow` (`4`), we reverse the second half.

**Initial State**:
- `preMiddle` is `3`
- `preCurrent` is `4`

**Reversing Process**:
- **Iteration 1**:
  - `current` is `5`
  - Update `preCurrent->next` to `current->next` (`NULL`)
  - Update `current->next` to `preMiddle->next` (`4`)
  - Update `preMiddle->next` to `current` (`5`)
  - List now looks like this: `1 -> 2 -> 3 -> 5 -> 4`
- No more nodes to reverse.

After reversing, the second half is now:

```
1 -> 2 -> 3 -> 5 -> 4
```

### Step 3: Merge the Two Halves
We need to alternate nodes from the first and reversed second halves.

**Initial State**:
- `first` is `1`
- `second` is `5`
- `preMiddle` is still at `3`

**Merging Process**:
- **Iteration 1**:
  - Connect `first->next` (which is `2`) to `second` (`5`)
  - Connect `second->next` (which is `4`) to `first->next` (`2`)
  - Update `first` to `2`
  - Update `second` to `4`
  - List now looks like this: `1 -> 5 -> 2 -> 3 -> 4`
- **Iteration 2**:
  - Connect `first->next` (which is `3`) to `second` (`4`)
  - Connect `second->next` (which is `NULL`) to `first->next` (`3`)
  - Update `first` to `3`
  - Update `second` to `NULL`
  - List now looks like this: `1 -> 5 -> 2 -> 4 -> 3`
- Stop since `second` is `NULL`.

### Final Result:
The reordered list is now:

```
1 -> 5 -> 2 -> 4 -> 3
```

This correctly follows the pattern of placing the last element next to the first, the second last next to the second, and so on.
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list starting from slow->next
        ListNode* preMiddle = slow;
        ListNode* preCurrent = slow->next;
        while (preCurrent->next != NULL) {
            ListNode* current = preCurrent->next;
            preCurrent->next = current->next;
            current->next = preMiddle->next;
            preMiddle->next = current;
        }

        // Reordering the list
        ListNode* first = head;
        ListNode* second = preMiddle->next;
        while (first != preMiddle) {
            preMiddle->next = second->next;
            second->next = first->next;
            first->next = second;

            first = second->next;
            second = preMiddle->next;
        }
    }
};