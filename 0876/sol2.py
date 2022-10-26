from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        end_node = head
        mid_node = head

        while end_node is not None and end_node.next is not None:
            end_node = end_node.next.next
            mid_node = mid_node.next

        return mid_node