import xml.etree.ElementTree

e = xml.etree.ElementTree.parse('safari.xml').getroot()

for atype in e.findall('p'):
    print(atype)
