# tree class definition and building tree from input, not related to solution
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
    
    
def build_tree(n, edges):
    nodes = {1: TreeNode(1)}
    
    def get_node(val):
        if val not in nodes:
            nodes[val] = TreeNode(val)
        return nodes[val]
    
    for parent, dir, val in edges:
        p = get_node(parent)
        c = get_node(val)
        
        if dir == 0:
            p.left = c
        if dir == 1:
            p.right = c
        
    return nodes[1]
    
# longest distance is obtained effectively from the distance between deepest 
# leftward node and deepest rightward node of the root node 
def count_longest_distance(root: TreeNode):
    longest_distance = 0
    
    # recursively finds depth of both left and right subtrees of given node
    # then saves max of both add one as the depth of given node
    def trace_depth():
        nonlocal root, longest_distance
        
        if not root:
            return 0
            
        left_depth, right_depth = trace_depth(root.left), trace_depth(root.right)
        longest_distance = max(longest_distance, left_depth + right_depth)
        
        return 1 + max(left_depth, right_depth)
    trace_depth(root)
    
    return longest_distance
    
    
n = int(input())
edges = []

for _ in range(n-1):
    edges.append((map(int, input().split())))
    
root = build_tree(n, edges)

print(count_longest_distance(root))
