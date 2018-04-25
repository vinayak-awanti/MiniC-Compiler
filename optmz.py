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
	if('/ 1' in e):
		return e.replace("/ 1", "")
	if('/ 0' in e):
		print('Divide by Zero')
		quit()	
	try:
		return eval(e)
	except NameError:
		return 'NO'


def constant_folding(input_file , output_file):
	sys.stdout = open(output_file,'wt')
	with open('ic') as fp:
		for s in fp:
			s = s.replace('\n','')
			if('=' in s ):
				a, b = s.split('=')
				x = func1(b)
				if(x!='NO'):
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
			if('=' in s ):
				a, b = s.split('=')
				a, b = a.strip(' '), b.strip(' ')
				for i  in [*d]:
					if(i in b):
						if(i == b):
							out.remove(i+' = '+d[i])
						b = b.replace(i,d[i])
						
						 
				d[a] = b
				out.append(a+' = '+b)
			else:
				out.append(s)
					

	for i in out:
		print(i)

