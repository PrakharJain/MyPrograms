# refer http://stackoverflow.com/questions/645312/what-is-the-quickest-way-to-http-get-in-python
# refer http://codereview.stackexchange.com/questions/7044/better-way-to-parse-xml-in-python
#refer http://lxml.de/tutorial.html
# http://stackoverflow.com/questions/4357494/how-do-i-read-data-using-lxml-in-python
# http://www.blog.pythonlibrary.org/2010/11/20/python-parsing-xml-with-lxml/
from lxml.html import parse
import urllib2
from lxml import etree
from StringIO import StringIO

#import xml.etree.ElementTree as ElementTree
#response =  urllib2.urlopen("http://www.barnesandnoble.com/s/?store=ebook").read().decode('latin-1')
#print response
#e=ElementTree.XML(response);
#tree = etree.parse(response);
#response =  urllib2.urlopen("http://www.flipkart.com/search/a/all?query=shantaram").read()
response =  urllib2.urlopen("http://www.flipkart.com/search?q=nexus4&as=off&as-show=on&otracker=start").read()
#print response
newresponse = response.decode('utf-8')
#page = parse(newresponse)
#tree = etree.parse(StringIO(newresponse))
#tree = etree.fromstring(response)
parser = etree.HTMLParser()
tree   = etree.parse(StringIO(response), parser)

#x = "http://www.w3.org/1999/xhtml"
#r = tree.xpath("//%x:div[@class='line all_search_results']/x:div[1]/x:div[2]//x:a[@title]")
#r = tree.xpath("//a[contains(@class,'fk-display-block')]/@title")
#p = tree.xpath("//div[@class='line all_search_results']/div[1]/div[2]//a[@title]")
#parameterFile =  open('XpathParameters.xml','r')
#parametersXpath = parameterFile.read()

#print parametersXpath
parametersXmlDoc = etree.parse("XpathParameters.xml")
titleXpath = parametersXmlDoc.xpath("//Name")[0].text
titles =  tree.xpath(titleXpath)

priceXPath =  parametersXmlDoc.xpath("//Price")[0].text
prices = tree.xpath(priceXPath)

for price in prices:
	print price
#titles =  tree.xpath("//a[contains(@class,'fk-display-block')]/@title")

for title in titles:
	print title

for title , price in zip(titles,prices):
	print title + "    " + price

#for node in p:
#	print node.get("title")

#for child in r:
#	print child.tag

#result = etree.tostring(tree.getroot(),pretty_print=True, method="html")

#print (r)
#print(result)
