from progressbar import progressBar
import sys 

f = open( "progress.txt", "r+") 
line = f.read()
if len ( sys.argv) == 1 :
  print ("usage: progress.py MAXSIZE")
else :
  prog=progressBar(maxValue = int (sys.argv[1]))
  prog.updateAmount(int (line))
  prog.draw()
  print("")
f.close()
