from cyaron import *     
for i in range(7,16):
    test_data=IO(file_prefix="challenge",data_id=i)
    p=(2**31)-1
    pos=randint(10**7,p-10000000)
    test_data.input_writeln(2)
    test_data.input_writeln(pos,pos+4999999,p)
    test_data.output_gen("./std")