from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        len_ll = 0
        temp = head
        while temp is not None:
            len_ll += 1
            temp = temp.next

        temp = head
        for i in range(int(len_ll / 2)):
            temp = temp.next

        return temp

# test case

# test 
# print(int(6/2))