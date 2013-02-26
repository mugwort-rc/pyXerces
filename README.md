pyXerces
========

Build
=====

	$ python setup.py build

Usage
=====

	import Xerces
	parser = Xerces.XercesDOMParser()
	
	xml = open('sample.xml', 'rb').read()
	input = Xerces.MemBufInputSource(xml, 'PyXercesDOMParser')
	parser.parse(input)
	dom = parser.getDocument()

