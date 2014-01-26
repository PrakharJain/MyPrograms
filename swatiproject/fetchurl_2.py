# refer http://stackoverflow.com/questions/645312/what-is-the-quickest-way-to-http-get-in-python
# refer http://codereview.stackexchange.com/questions/7044/better-way-to-parse-xml-in-python
#refer http://lxml.de/tutorial.html
# http://stackoverflow.com/questions/4357494/how-do-i-read-data-using-lxml-in-python
# http://www.blog.pythonlibrary.org/2010/11/20/python-parsing-xml-with-lxml/

import urllib2
from lxml import etree
#import xml.etree.ElementTree as ElementTree
response =  urllib2.urlopen("http://www.barnesandnoble.com/s/?store=ebook").read()
print response
#e=ElementTree.XML(response);
tree = etree.parse(response);

