from cyaron import *
import random
_n=ati([0,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000])       
for i in range(1,11):
    test_data=IO(file_prefix="Hash",data_id=i)
    N=randint(1,_n[i])
    A=""
    for j in range(1,N):
        A+='a'
    test_data.input_write(A)
    test_data.output_gen("./std")