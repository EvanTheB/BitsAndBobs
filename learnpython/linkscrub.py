import re
import sys
import urllib.request
import argparse


parser = argparse.ArgumentParser(description='Find links in webpages')
parser.add_argument('-u', '--urls', action="store_true")
parser.add_argument('URL_LIST', nargs='*', default='')
args = parser.parse_args()


if args.URL_LIST is not '':
    urlList = args.URL_LIST
else:
    urlList = sys.stdin

urlDict = {}
for url in urlList:
    if url in urlDict:
        continue
    if 'http' not in url:
        continue
    urlDict[url] = 1

    if not (args.urls):
        print("opening URL %s" % url)

    page = urllib.request.urlopen(url)
    for line in page: #search each line and tag for a linl
        line = str(line).split("<")
        for part in line:
            if "a href" in part:
                part = re.split(r"[\">]", part)
                addr = part[1]
                text = part[3]
                if args.urls:
                    print("%s" % (addr,))
                else:
                    print("%s %s" % (addr, text))
