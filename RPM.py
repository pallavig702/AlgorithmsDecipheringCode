from __future__ import division
import os, sys, re

file1=sys.argv[1]
number=int(sys.argv[2])
string = open(file1).read()
i=0
#while(i!=len(string)):
while((i+number)<=len(string)):
	start=i
	stop=i+number
	temp=string[start:stop]
	i=i+1
	if len(temp.rstrip('\r\n'))==number:
		print temp.rstrip('\r\n')
