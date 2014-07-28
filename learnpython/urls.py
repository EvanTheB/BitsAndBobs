import urllib.request
page = urllib.request.urlopen('http://www.cs.luther.edu/python/test.html')
pageText = page.read()
print(pageText)
