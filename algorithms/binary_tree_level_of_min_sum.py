class Node:
    def __init__(self, data):
        self.val = data
        self.left = None
        self.right = None
    def insert(self, data):
        if not self.val:
            self.val=data
        else:
            if data < self.val:
                if not self.left:
                    self.left=Node(data)
                else:
                    self.left.insert(data)
            elif data > self.val:
                if not self.right:
                    self.right=Node(data)
                else:
                    self.right.insert(data)
    def printTree(self):
        print(self.val, end=',')
        if self.left:
            self.left.printTree()
        if self.right:
            self.right.printTree()


def levelMinSum(node, runSum, runLvl):
    if not node:
        return
    runLvl+=1
    runSum+=node.val
    if not node.right and not node.left:
        global minSum, minLvl
        if runSum < minSum:
            minSum, minLvl = runSum, runLvl
    else:
        levelMinSum(node.left, runSum, runLvl)
        levelMinSum(node.right, runSum, runLvl)

def main():
    tree = Node(3)
    tree.insert(5)
    tree.insert(2)
    tree.insert(7)
    tree.insert(1)
    tree.insert(6)
    tree.insert(0)
    tree.printTree()
    print('\nFinding Level with min sum...')
    levelMinSum(tree, 0, 0)
    print('MinSum :', minSum)
    print('Level  :', minLvl)

minLvl = 0
minSum = 999999999
main()