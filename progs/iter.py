#!/usr/bin/python
import itertools
#print list(itertools.permutations([1,2,3],3 ))
#print list(itertools.permutations(['DS','DF','XS','XF'],3 ))
#mylist= list(itertools.product(['DS','DF','SS','SF'],repeat=3))
mylist= list(itertools.product(['DS','DF','SF'],repeat=3))
for i in mylist:
	print i[0], i[1],i[2]
