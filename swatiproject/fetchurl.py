# refer http://stackoverflow.com/questions/645312/what-is-the-quickest-way-to-http-get-in-python
import urllib2
print urllib2.urlopen("http://www.flipkart.com/search/a/all?query=shantaram").read()
