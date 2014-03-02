# refer http://stackoverflow.com/questions/645312/what-is-the-quickest-way-to-http-get-in-python
# refer http://codereview.stackexchange.com/questions/7044/better-way-to-parse-xml-in-python
#refer http://lxml.de/tutorial.html
# http://stackoverflow.com/questions/4357494/how-do-i-read-data-using-lxml-in-python
# http://www.blog.pythonlibrary.org/2010/11/20/python-parsing-xml-with-lxml/

from lxml.html import parse
import urllib2
from lxml import etree
from StringIO import StringIO
import urllib
def parseXpathInformation():
	return etree.parse("//media//sf_OurStuff//myGitRepo//MyPrograms//swatiproject//mysite//polls//XpathParameters.xml")

def getCategoryXpath(category):
	categoryXpathPrefix="//Category[@type='";
        categoryXpathPostfix="']//";
        return categoryXpathPrefix + category + categoryXpathPostfix

def getNameXpath(categoryXpath):
	return categoryXpath + "Name"

def getTitleXPath(parametersXmlDoc , categoryXpath):
	return parametersXmlDoc.xpath(categoryXpath + "Name//xpath")[0].text

def getPriceXPath(parametersXmlDoc , categoryXpath):
	return parametersXmlDoc.xpath(categoryXpath+"Price//xpath")[0].text

def getRootUrl(parametersXmlDoc , categoryXpath):
	return parametersXmlDoc.xpath(categoryXpath+"RootUrl")[0].text

def fetchSearchPageCotent(rootUrl , searchItem):
	searchItemEncoded = urllib.quote_plus(searchItem)
	urlToFetch = rootUrl + searchItemEncoded
#	urlToFetch = urllib.quote_plus(urlToFetch)
#	urlToFetch = urllib2.quote(urlToFetch, safe="%/:=&?~#+!$,;'@()*[]")
	print urlToFetch
	return urllib2.urlopen(rootUrl+searchItem).read()
	# newresponse = response.decode('utf-8')

def GetData(itemName , category):
	parametersXmlDoc = parseXpathInformation() 
	categoryXpath = getCategoryXpath(category)
	
	nameXPath = getNameXpath(categoryXpath)
	print nameXPath
	
	titleXpath = getTitleXPath(parametersXmlDoc , categoryXpath)
	priceXPath = getPriceXPath(parametersXmlDoc , categoryXpath)
	rootUrl = getRootUrl(parametersXmlDoc , categoryXpath)
	print rootUrl

	response =  fetchSearchPageCotent(rootUrl , itemName)
#	print response
	parser = etree.HTMLParser()
	tree   = etree.parse(StringIO(response), parser)	
	prices = tree.xpath(priceXPath)
	titles =  tree.xpath(titleXpath)

	for title , price in zip(titles,prices):
		print title + "    " + price
	return (titles , prices)

# uncomment this to trigger fuctionality in this file.
#category = raw_input("Enter Category String: ")
#searchItem=raw_input("Enter Search String: ")
#GetData(searchItem , category)
