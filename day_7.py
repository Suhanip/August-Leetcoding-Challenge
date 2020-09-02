'''PROBLEM STATEMENT:
  Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        result = []
        if root is None:
            return result
        cache = {}
        self.minC, self.maxC = 0,0
        
        def dfs(node, r, c):
            if node is None:
                return
            if c in cache: cache[c].append([r,node.val])
            else:
                cache[c] = [[r,node.val]]
            self.minC = min(self.minC,c)
            self.maxC = max(self.maxC,c)
            dfs(node.left,r+1,c-1)
            dfs(node.right,r+1,c+1)
         
        dfs(root, 0, 0)
        for c in range(self.minC,self.maxC+1):
            col = sorted(cache[c], key = lambda x: (x[0], x[1]))
            col_sorted = []
            for p in col:
                col_sorted.append(p[1])
            result.append(col_sorted)
            
        return result
 
