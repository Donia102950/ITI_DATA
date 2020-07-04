import sys ,os ,shutil

def main():
  ls=[]
  print("Hello to my driver creation\n")
  name=input("please enter the name of your driver:")
  
  os.mkdir(name)
  os.chdir('./'+name)
  f=open(name+'_interface.h','w')
  f.close()
  
  f=open(name+'_config.h','w')
  f.close()
  
  f=open(name+'_register.h','w')
  f.close()
  
  f=open(name+'_program.c','w')
  ls=['\n#include "STD_TYPES.h"','\n#include "BIT_MATH.h"','\n#include "'+name+'_interface.h"','\n#include "'+name+'_register.h"','\n#include "'+name+'_config.h"','\n#include "'+name+'_private.h"']
  for i in ls :
    f.write(i)
  f.close()
  
  f=open(name+'_main.c','w')
  ls=['\n#include "STD_TYPES.h"','\n#include "BIT_MATH.h"','\n#include "'+name+'_interface.h"','\n\nint main(void){','return 0}']
  for i in ls :
    f.write(i)
  f.close()
  
if __name__ == '__main__':
  main()