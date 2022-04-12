# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if not head.next:
            return None
        
        first = head
        second = head
        cnt = n
        
        while cnt > 0:
            if not second.next:
                return head.next
            second = second.next
            cnt -= 1
        
        while second.next:
            first = first.next
            second = second.next
        
        first.next = first.next.next
        return head
