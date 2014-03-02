from django.http import HttpResponse

def start(request):
    return HttpResponse('<form name="input" action="http://127.0.0.1:8000/search/" method="get">Enter item need to search: <input type="text" name="item_name"><br>enter category: <input type="text" name="category"><br><input type="submit" value="submit"></form>')
