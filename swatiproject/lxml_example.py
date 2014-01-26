# refer http://stackoverflow.com/questions/645312/what-is-the-quickest-way-to-http-get-in-python
# refer http://codereview.stackexchange.com/questions/7044/better-way-to-parse-xml-in-python
#refer http://lxml.de/tutorial.html
# http://stackoverflow.com/questions/4357494/how-do-i-read-data-using-lxml-in-python
# http://www.blog.pythonlibrary.org/2010/11/20/python-parsing-xml-with-lxml/
from lxml.html import parse
import urllib2
from lxml import etree
from StringIO import StringIO


parametersXmlDoc = etree.parse("XpathParameters.xml")
# //Category[@type=Mobiles]//Name
categoryXpathPrefix="//Category[@type='";
categoryXpathPostfix="']//";
category = raw_input("Enter Category String: ")
#category = "Mobiles"
categoryXpath = categoryXpathPrefix + category + categoryXpathPostfix
nameXPath = categoryXpath + "Name"
print nameXPath
titleXpath = parametersXmlDoc.xpath(categoryXpath + "Name")[0].text
#titleXpath = parametersXmlDoc.xpath("//Category[@type='Mobiles']//Name")[0].text
#titleXpath = parametersXmlDoc.xpath("//Name")[0].text
priceXPath = parametersXmlDoc.xpath(categoryXpath+"Price")[0].text
#priceXPath = parametersXmlDoc.xpath("//Category[@type='Mobiles']//Price")[0].text
#priceXPath =  parametersXmlDoc.xpath("//Price")[0].text
rootUrl = parametersXmlDoc.xpath(categoryXpath+"RootUrl")[0].text
#rootUrl = parametersXmlDoc.xpath("//Category[@type='Mobiles']//RootUrl")[0].text
#rootUrl = parametersXmlDoc.xpath("//RootUrl")[0].text

print rootUrl
searchItem=raw_input("Enter Search String: ")

response =  urllib2.urlopen(rootUrl+searchItem).read()
#response =  urllib2.urlopen("http://www.flipkart.com/search?q=nexus4&as=off&as-show=on&otracker=start").read()
newresponse = response.decode('utf-8')
parser = etree.HTMLParser()
tree   = etree.parse(StringIO(response), parser)

prices = tree.xpath(priceXPath)
titles =  tree.xpath(titleXpath)

#for price in prices:
#	print price

#for title in titles:
#	print title

for title , price in zip(titles,prices):
	print title + "    " + price
