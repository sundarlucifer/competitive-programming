class Node():
    def __init__(self, data):
        self.data=data
        self.right=None
        self.left=None

def rightSumReplace(node, sum):
    if not node:
        return sum
    sum = rightSumReplace(node.right, sum)
    temp = node.data
    node.data = sum
    sum = rightSumReplace(node.left, sum+temp)
    return sum

def inorder(node):
    if node:
        inorder(node.left)
        print(node.data, end=' ')
        inorder(node.right)

tree = Node(5)
tree.left=Node(3)
tree.left.right=Node(4)
tree.left.left=Node(1)
tree.right=Node(10)
tree.right.left=Node(7)
tree.right.right=Node(15)
rightSumReplace(tree, 0)
inorder(tree)