import re

def mail_check(mail):
	if re.match(r"^[\w\-]+\@[A-Za-z0-9]+\.[\w]{1,3}$",mail):
		return True
	else:
		return False


string_list = []
for n in range(0,input()):
    string_list.append(raw_input());

print filter(mail_check,sorted(string_list))