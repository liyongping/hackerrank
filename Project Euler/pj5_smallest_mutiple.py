checked = [11, 12, 13, 14, 15, 16, 17, 18, 19,20]



def get_smallest_mutiple():
	x = 2520
	while True:
		found = True
		for c in checked:
			if x%c != 0:
				found = False
				break
		if found:
			return x
		else:
			x+=1

print get_smallest_mutiple()