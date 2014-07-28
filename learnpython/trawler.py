import subprocess
curPath = "/home/evanb/Documents/code/learnpython/"

out = open('out0', 'w')
subprocess.call(['/usr/bin/python3', curPath + 'linkscrub.py', '-u', 'http://www.example.com'], stdout=out)
out.close()
for i in range(20):
    out = open('out' + str(i+1), 'w')
    inf = open('out' + str(i), 'r')
    subprocess.call(['/usr/bin/python3', curPath + 'linkscrub.py', '-u'], stdout=out, stdin=inf)
