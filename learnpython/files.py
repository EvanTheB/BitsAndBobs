rfile = open('testfile', 'w')

rfile.write('yolo\n')
rfile.write('test ' + str(32) + '\n')
rfile.write('test %d %f\n' % (31, 32)) 
rfile.write('test %s %s\n' % (31, 32)) 
rfile.write('test %s %s\n') 



rfile.write('testdict %(name)s %(value)s\n' % {"name":31, "value":32})
#rfile.write('testdict %(31)s %(32)s\n' % {"31":31, 32:32})
rfile.close()

rfile = open('input', 'r')
for lines in rfile:
    print(lines)
    print(lines.split())
rfile.close()
rfile = open('input', 'r')
print(rfile.read(1))
print(rfile.readline())
print(rfile.readlines().strip())

