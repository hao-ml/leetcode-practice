class Node:
    def __init__(self, val):
        self.val = val 
        self.next = None 
        self.prev = None

class MyLinkedList(object):

    def __init__(self):
        self.head = None

    def get(self, index):
        """
        :type index: int
        :rtype: int
        """
        i = 0
        curr = self.head
        while curr is not None:
            if i == index:
                return curr.val
            curr = curr.next
            i += 1
        
        return -1
        
    def addAtHead(self, val):
        """
        :type val: int
        :rtype: None
        """
        node = Node(val)
        node.next = self.head
        if self.head is not None:
            self.head.prev = node
        self.head = node 

    def addAtTail(self, val):
        """
        :type val: int
        :rtype: None
        """
        node = Node(val)

        if self.head is None:
            self.head = node
            return
        
        curr = self.head
        while curr.next is not None:
            curr = curr.next
        curr.next = node
        node.prev = curr

        return
        

    def addAtIndex(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        if index == 0:
            self.addAtHead(val)
            return
        
        i = 0
        curr = self.head
        while curr is not None:
            if i == index:
                node = Node(val)
                node.prev = curr.prev
                curr.prev.next = node
                curr.prev = node
                node.next = curr
                return
            i += 1
            curr = curr.next
        if i == index:
            self.addAtTail(val)

        return

    def deleteAtIndex(self, index):
        """
        :type index: int
        :rtype: None
        """
        if self.head is None:
            return 
        if index == 0:
            self.head.prev = None
            self.head = self.head.next 
            return
        
        i = 0
        curr = self.head
        while curr is not None:
            if i == index:
                curr.prev.next = curr.next
                if curr.next is not None:
                    curr.next.prev = curr.prev 
                return 
            i += 1
            curr = curr.next
        return      

    def print_list(self):
        node = self.head
        lst = []
        while node is not None:
            lst.append(node.val)
            node = node.next         
        print(lst)

# Your MyLinkedList object will be instantiated and called as such:
obj = MyLinkedList()

obj.addAtHead(7)
obj.print_list()

obj.addAtHead(2)
obj.print_list()

obj.addAtHead(1)
obj.print_list()

obj.addAtIndex(3, 0)
obj.print_list()

obj.deleteAtIndex(2)
obj.print_list()

obj.addAtHead(6)
obj.print_list()

obj.addAtTail(4)
obj.print_list()

print(obj.get(4))

obj.addAtHead(4)
obj.print_list()

obj.addAtIndex(5, 0)
obj.print_list()

obj.addAtHead(6)
obj.print_list()
