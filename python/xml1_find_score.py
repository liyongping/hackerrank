import xml.etree.ElementTree as etree

xml_string = ""
for x in range(0,input()):
    xml_string += raw_input()
    
tree = etree.ElementTree(etree.fromstring(xml_string))

score = 0

root = tree.getroot()

for n in root.iter():
	score += len(n.attrib)

print score