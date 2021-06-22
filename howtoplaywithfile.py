
file_name = 'dogs.txt'
with open(file_name,'w') as f:
	line = f.write('rocky\n')
	line = f.write('bong\n')
	line = f.write('chat\n')

with open(file_name) as ff:
	rd = ff.readlines()

for row in rd:
	print(row.rstrip())
print("")
file = 'cats.txt'
with open(file,'a') as fe:
	Line = fe.append('jhon\n')
	Line = fe.append('utha\n')
	Line = fe.append('bhvgea\n')
with open(file,'r') as mm:
	hh = mm.readlines()
for d in hh:
	print(d.rstrip())