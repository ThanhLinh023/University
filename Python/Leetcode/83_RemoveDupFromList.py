class Node:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def deleteDuplicate(head):
    tmp = head
    while tmp != None:
        i = tmp
        while i.next and i.next.val == tmp.val:
            i.next = i.next.next
        tmp = tmp.next
    return head
t = Node(1)
t.next = Node(2)
t.next.next = Node(2)
t.next.next.next = Node(3)
t.next.next.next.next = Node(3)

m = deleteDuplicate(t)
while m != None:
    print(m.val)
    m = m.next