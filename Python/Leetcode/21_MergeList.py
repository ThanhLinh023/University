class Node:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def mergeList(list1, list2):
    head = Node()
    tail = head
    while (list1 != None or list2 != None):
        if (list2 == None) or (list1 != None and list1.val < list2.val):
            tail.next = list1
            tail = list1
            list1 = list1.next
        else:
            tail.next = list2
            tail = list2
            list2 = list2.next
    return head.next
t = Node(1)
t.next = Node(2)
t.next.next = Node(3)
t.next.next.next = Node(4)
m = Node(5)
m.next = Node(6)
m.next.next = Node(7)
m.next.next.next = Node(8)

head = mergeList(t, m)

while head != None:
    print(head.val)
    head = head.next