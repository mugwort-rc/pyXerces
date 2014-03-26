# -*- coding: utf-8 -*-
"""
pyXerces
========

|travis-ci|_

.. |travis-ci| image:: https://travis-ci.org/mugwort-rc/pyXerces.png
.. _travis-ci: https://travis-ci.org/mugwort-rc/pyXerces

Basic Usage:

    import Xerces

    parser = Xerces.XercesDOMParser()

    xml = '<test>foobar</test>'
    input = Xerces.MemBufInputSource(xml, 'MemBufId')
    parser.parse(input)

    dom = parser.getDocument()

"""

import os, sys

from distutils.core import setup
from distutils.command import build_ext

from distutils.core import Extension

include_dirs = ['/usr/local/include']
libraries = ['xerces-c', 'boost_python', 'stdc++']
library_dirs = ['/usr/local/lib']
sources = []
for (root, dirs, files) in os.walk('src'):
    for name in files:
        if name[-4:] == '.cpp':
            sources.append('%s/%s'%(root,name))

xerces = Extension(name = 'Xerces.__Xerces',
                   include_dirs = include_dirs,
                   libraries = libraries,
                   library_dirs = library_dirs,
                   sources = sources,
                   extra_compile_args = ['-std=c++0x'])

# distutils c++ bug fix.
from distutils.sysconfig import get_config_vars
(opt,) = get_config_vars('OPT')
os.environ['OPT'] = " ".join([flag for flag in opt.split() if flag != '-Wstrict-prototypes'])

# ccache
for path in os.environ['PATH'].split(os.pathsep):
    path = path.strip('"')
    exe = os.path.join(path, 'ccache')
    if os.path.isfile(exe) and os.access(exe, os.X_OK):
        os.environ['CC'] = 'ccache gcc'
        break

setup(name = 'PyXerces',
      long_description = __doc__,
      version = '0.0.1',
      description = 'pyXerces: A Python Xerces-c wrapper',
      author = 'mugwort_rc',
      author_email = 'mugwort rc at gmail com',
      url = 'https://github.com/mugwort-rc/pyXerces',
      classifiers = [
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: Apache Software License',
        'Programming Language :: C++',
        'Programming Language :: Python',
        'Programming Language :: Python :: 2.7',
        'Topic :: Text Processing :: Markup :: XML',
      ],
      license = 'Apache Software License, Version 2.0',
      packages = ['Xerces', 'Xerces.util'],

      ext_modules = [xerces])

