
class trienode:
    def __init__(self):
        self.children = [None]*26
        self.iswordend = False

class trie:
    def __init__(self):
        self.root = self.getnode()
    def getnode(self):
        return trienode()
    
    def insert(self,s):
        head = self.root
        
        for key in s:
            index = ord(key) - ord('a')
            if head.children[index] is None:
                head.children[index] = self.getnode()
            head = head.children[index]
        head.iswordend = True
    
    def search(self,s):
        head = self.root
        for key in s:
            index = ord(key) - ord('a')
            if not head.children[index]:
                return False
            head = head.children[index]
        if head.iswordend == True:
            return True
        else:
            return False

            



string = ['hello','helto','belo','kelo','helloo','google','microsoft','apple','amazon','flipkart','cisco','paypal','paytm','ritik','badshah']
obj = trie()
for i in string:
    obj.insert(i)

print("{} == {}".format("kello",print(obj.search("kello"))))
