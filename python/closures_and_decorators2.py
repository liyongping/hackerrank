
from operator import itemgetter

def format_name(func):
	def inner(original_names):
		original_names = func(original_names)
		final_list = []
		for firstname,lastname,age,sex in original_names:
			if sex == "M":
				final_list.append("Mr. "+firstname+" "+lastname)
			else:
				final_list.append("Ms. "+firstname+" "+lastname)
		return final_list
	return inner

@format_name
def sort_name(name_list):
	ordered_list = sorted(name_list,key=itemgetter(2))
	return ordered_list


name_list = []
for x in range(0,input()):
	firstname,lastname,age,sex = raw_input().split()
	name_list.append([firstname,lastname,age,sex])

for name in sort_name(name_list):
	print name;