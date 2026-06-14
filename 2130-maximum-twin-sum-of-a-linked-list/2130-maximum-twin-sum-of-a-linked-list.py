# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        arr = []

        current = head
        while current is not None:
            arr.append(current.val)
            current = current.next

        res = 0
        for i in range(len(arr)//2):
            res = max(res, arr[i] + arr[len(arr) - (i + 1)])
        
        return res