class Node:
    def __init__(self, value):
        self.left = self.right = None
        self.data = value

def insert(root, value):
    if root == None:
        return Node(value)

    if value < root.data:
        root.left = insert(root.left, value)
    elif value > root.data:
        root.right = insert(root.right, value)

    return root

def preOrder(root):
    if root != None:
        print(root.data, end=" ")
        preOrder(root.left)
        preOrder(root.right)

def inOrder(root):
    if root != None:
        inOrder(root.left)
        print(root.data, end=" ")
        inOrder(root.right)

def postOrder(root):
    if root != None:
        postOrder(root.left)
        postOrder(root.right)
        print(root.data, end=" ")

values = list(map(int, input("Enter values: ").split()))

root = None
for value in values:
    root = insert(root, value)

print("PreOrder Traversal:", end=" ")
preOrder(root)

print("\nInorder Traversal:", end=" ")
inOrder(root)

print("\nPostOrder Traversal:", end=" ")
postOrder(root)

print()
