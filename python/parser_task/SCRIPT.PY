import os 
import re

def main():

  f=open('file.SVD','r')
  peripherals=re.findall(r'(<peripheral>)([\w\W]*?)(</peripheral>)',f.read())
  #print(peripherals[1][0])
  #groupnames=re.findall(r'(<groupName>)([\w\W]*?)(</groupName>)',str(peripherals))
  #print(groupname[0][1])
  for peripheral in peripherals:
    peripheralgroupname=re.search(r'(<groupName>)([\w\W]*?)(</groupName>)',str(peripheral))
    file=str(peripheralgroupname .group(2))
    f=open(file + '_register.h','w+')
    #print(groupname.group(1))
    registers=re.findall(r'(<register>)([\w\W]*?)(</register>)',str(peripheral))
    for register in registers:
      registername=re.search(r'(<displayName>)([\w\W]*?)(</displayName>)',str(register))
      f.write('\n\n'+registername.group(2))
      #print(registername.group(2))
      bits=re.findall(r'(<field>)([\w\W]*?)(</field>)',str(register))
      for bit in bits:
        bitname=re.search(r'(<name>)([\w\W]*?)(</name>)',str(bit))
        #name=str(bitname)
        #print(bitname.group(2))
        bitoffset=re.search(r'(<bitOffset>)([\w\W]*?)(</bitOffset>)',str(bit))
        bitwidth=re.search(r'(<bitWidth>)([\w\W]*?)(</bitWidth>)',str(bit))
        #print(bitwidth.group(2))
        if bitwidth.group(2)== '1':
          example = (0x01<<int (bitoffset.group(2)))&0xffffffff
          f.write('\n#define '+bitname.group(2)+' mask '+ str(hex(example)))
          example=0x00
          #print("original", bin(example))
        else :
          shift=int (bitoffset.group(2))
          width=int (bitwidth.group(2))
          for x in range(width):
            example|=(0x01<<shift)&0xffffffff
            shift=shift+1
          f.write('\n#define '+bitname.group(2)+' mask '+ str(hex(example)))
#print("original", bin(example))
          #f.write('#define ')
     #for name in names:
        #print(name[1])
main()