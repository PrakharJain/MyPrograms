# refer http://stackoverflow.com/questions/645312/what-is-the-quickest-way-to-http-get-in-python
# refer http://codereview.stackexchange.com/questions/7044/better-way-to-parse-xml-in-python
#refer http://lxml.de/tutorial.html
# http://stackoverflow.com/questions/4357494/how-do-i-read-data-using-lxml-in-python
# http://www.blog.pythonlibrary.org/2010/11/20/python-parsing-xml-with-lxml/
from lxml.html import parse
import urllib2
from lxml import etree
from StringIO import StringIO

class ItemRetailerXpath(object):
	def __init__(self , title="" , price=0.0):
		self.title = title
		self.price = price

flipkartXpath = ItemRetailerXpath();
flipkartXpath.title = "//a[contains(@class,'fk-display-block')]/@title"
flipkartXpath.price = "//div[contains(@class,'pu-final')]/span/text()"

response =  urllib2.urlopen("http://www.flipkart.com/search?q=nexus4&as=off&as-show=on&otracker=start").read()
newresponse = response.decode('utf-8')
parser = etree.HTMLParser()
tree   = etree.parse(StringIO(response), parser)
xpath = "//a[contains(@class,'fk-display-block')]/@title"
titles =  tree.xpath(flipkartXpath.title)
prices = tree.xpath(flipkartXpath.price)
for title , price in zip(titles,prices):
	print(title," ", price)
#for title in titles:
#	print title


