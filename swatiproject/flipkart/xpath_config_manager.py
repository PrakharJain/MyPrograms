from lxml.html import parse
import urllib2
from lxml import etree
from StringIO import StringIO

def GetXPathConfig( filepath ):
	xmldata = etree.parse(filepath)
	root = xmldata.getroot()
	print root[0].tag
	print len(root)
	children = list(root)
	for child in children:
		print child.tag , child.text
	
	for child in root
	#print result
#	for element in root.iter(tag=etree.Element):
#		print("%s - %s" % (element.tag, element.text))



def parseXML(xmlFile):
    """
    Parse the xml
    """
    f = open(xmlFile)
    xml = f.read()
    f.close()
 
    tree = etree.parse(StringIO(xml))
    context = etree.iterparse(StringIO(xml))
    for action, elem in context:
        if not elem.text:
            text = "None"
        else:
            text = elem.text
        print elem.tag + " => " + text 


GetXPathConfig("product_detail_xpath_config.xml")

#parseXML("product_detail_xpath_config.xml")
