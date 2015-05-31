import string
import random
def id_gen(size = 6, chars=string.ascii_uppercase + string.digits):
	return ''.join(random.choice(chars) for _ in range(size))

samplesize = 100000
f = open('random_grades' + str(samplesize) + '.txt', 'w')
f.truncate()

for i in range(0, samplesize):
	name = id_gen(10)
	midterm = int(random.uniform(40, 100))
	final = int(random.uniform(40, 100))
	hw = [int(random.uniform(40, 100)) for a in range(4,int(random.uniform(6,10)))]
	f.write(name + ' ' + str(midterm) + ' ' + str(final))
	for a in range(0, len(hw)):
		f.write(' ' + str(hw[a]))
	f.write('\n')

f.close()