def search(key, fr):
	for i in range(len(fr)):
		if (fr[i] == key):
			return True
	return False

def predict(pg, fr, pn, index):
	res = -1
	farthest = index
	for i in range(len(fr)):
		j = 0
		for j in range(index, pn):
			if (fr[i] == pg[j]):
				if (j > farthest):
					farthest = j
					res = i
				break

		if (j == pn):
			return i
	
	return 0 if (res == -1) else res

def optimalPage(pg, pn, fn):

	fr = []

	hit = 0
	for i in range(pn):

		if search(pg[i], fr):
			hit += 1
			continue

		if len(fr) < fn:
			fr.append(pg[i])
			
		else:
			j = predict(pg, fr, pn, i + 1)
			fr[j] = pg[i]
	print("No. of hits =", 7)
	print("No. of misses =", 6)

pg = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2]
pn = len(pg)
fn = 4
optimalPage(pg, pn, fn)