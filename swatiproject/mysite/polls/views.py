
from django.http import HttpResponse
import DataFetcher

def index(request,poll_id):
    return HttpResponse("Hello, world. You're at the poll index %s." %poll_id)

#def start(request):
 #   return HttpResponse('<form name="input" action="http://127.0.0.1:8000/search/" method="get">Enter item need to search: <input type="text" name="item_name"><br>enter password: <input type="password" name="pwd"><br><input type="submit" value="submit"></form>')

def start(request):
	name = request.GET.get('item_name', '')
	category = request.GET.get('category' ,'')
	titles , prices = DataFetcher.GetData(name , category)
	information = ""
	for title , price in zip(titles,prices):
		information = information + title + "\t" + price + "\n"        
	return HttpResponse("Hello, world. You're at the poll index %s and category %s. \n Results = %s" %(name,category, information))
