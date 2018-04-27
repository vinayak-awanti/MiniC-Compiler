import sys

def func1(e):
	if('* 0' in e or '0 *' in e):
		return 0
	if('+ 0' in e):
		return e.replace("+ 0", "")	
	if('0 +' in e):
		return e.replace("0 +", "")
	if('1 *' in e):
		return e.replace("1 *", "")
	if('* 1' in e):
		return e.replace("* 1", "")
	if('/ 1' == e[-2:]):
		return e.replace("/ 1", "")
	if('/ 0' in e):
		print('Divide by Zero')
		quit()	
	try:
		return int(eval(e))
	except NameError:
		return 'NO'


def constant_folding(input_file , output_file):
	sys.stdout = open(output_file,'wt')
	with open(input_file) as fp:
		for s in fp:
			s = s.replace('\n','')
			if s.count('=') == 1:
				a, b = s.split('=')
				a, b = a.strip(' '), b.strip(' ')
				x = func1(b)
				str(x).strip(' ')
				if(x!='NO' ):
					print(a,'=',x)
				else:
					print(s)	
			else:
				print(s)


def constant_propagation(input_file , output_file):
	sys.stdout = open(output_file ,'wt')
	with open(input_file) as fp:
		d = {}
		out = []
		for s in fp:
			s = s.replace('\n','')
			if s.count('=') == 1:
				a, b = s.split('=')
				a, b = a.strip(' '), b.strip(' ')
				for i  in [*d]:
					if(i in b):
						if(i == b and 't' in i):
							out.remove(i+' = '+d[i])
						if('<' not in b and '>' not in b and 'not' not in b):
							b = b.replace(i,d[i])
						
						 
				d[a] = b
				out.append(a+' = '+b)
			else:
				out.append(s)
					

	for i in out:
		print(i)



constant_folding('ic' , 'folding.txt')
constant_propagation('folding.txt' ,'propagation.txt')
constant_folding('propagation.txt' ,'final.txt')
constant_propagation('final.txt' ,'final.txt')
constant_folding('final.txt' ,'final.txt')
