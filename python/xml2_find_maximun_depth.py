
# refer to http://www.cnblogs.com/CheeseZH/p/4026686.html
# 
import xml.etree.ElementTree as etree

xml_string = ""
for x in range(0,input()):
    xml_string += raw_input()
    
tree = etree.ElementTree(etree.fromstring(xml_string))

root = tree.getroot()

def get_depth(root):
	if len(list(root)) == 0:
		return 0
	current_depth = []
	for x in root:
		if len(list(x)) == 0:
			current_depth.append(1)
		else:
			current_depth.append(1+get_depth(x))
	return max(current_depth)

print get_depth(root)