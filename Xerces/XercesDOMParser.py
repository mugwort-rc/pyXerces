# -*- coding: utf-8 -*-

from __Xerces import MemBufInputSource, XercesDOMParser as _XercesDOMParser, unsigned_cast

class XercesDOMParser(_XercesDOMParser):
    def fromstring(self, source):
        assert type(source) is str
        input = MemBufInputSource(unsigned_cast(source), len(source), 'PyXercesDOMParser')
        self.parse(input)
        return self.getDocument()

