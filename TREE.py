
class node:
	def __init__(self,data):
		self.data = data
		self.left = None
		self.right = None

class Tree:

	def __init__(self):
		pass

	def searchEle(self,key,root):
		if root is None:
			return False

		if (root.left == None and root.right == None):
			if root.data == key:
				return True
			else:
				return False

		if root.data == key:
			return True
		res = self.searchEle(key,root.left)
		if res:
			return True
		res1 = self.searchEle(key,root.right)
		if res1:
			return True

		return False

	def deleteElement(self,key,root):
		if root is None:
			return 
		if root.left == None and root.right == None:
			if root.data == key:				
				root = None





t = node(10)
t.left = node(20)
t.right = node(30)
t.left.left = node(40)
t.left.right = node(50)

t1 = Tree()
res = t1.searchEle(20,t)
res1 = t1.searchEle(90,t)
print(res1)
print(res)