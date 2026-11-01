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

def search(root, value):
    if root == None:
        return False

    if root.data == value:
        return True
    elif value < root.data:
        return search(root.left, value)
    else:
        return search(root.right, value)

values = list(map(int, input("Enter BST values: ").split()))

root = None
for value in values:
    root = insert(root, value)

key = int(input("Enter key to search: "))

if search(root, key):
    print("Key is present")
else:
    print("Key is not present")
