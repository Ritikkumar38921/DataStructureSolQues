
class States:
	""" this is about the states"""

	def __init__(self,cm):
		self.cm = cm

	def About_State_Gov(self):
		print(f" the name of the cm is {self.cm}")
		print(f" it handle to all over the disticts")

	def Rights(self):
		print(f" {self.cm} can do anything in its area")

name = input("enter your name")
obj = States(name)
obj.About_State_Gov()
obj.Rights()

