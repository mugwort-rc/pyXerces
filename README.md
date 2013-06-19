# pyXerces

## Build

	$ python setup.py build

## Usage

### Xerces-C++ style

	import Xerces
	parser = Xerces.XercesDOMParser()
	
	xml = open('sample.xml', 'rb').read()
	input = Xerces.MemBufInputSource(xml, 'PyXercesDOMParser')
	parser.parse(input)
	dom = parser.getDocument()

### lxml.etree like

	from Xerces import etree

	dom = etree.fromstring('<test><a/><a/><a/></test>')

	print 'tag:', dom.tag
	print 'len:', len(dom)

	result = dom.xpath('//a')

	for elem in result:
		print 'tag:', elem.tag

