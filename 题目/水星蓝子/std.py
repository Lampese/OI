from cyaron import *  
for i in range(1,51):
    test_data=IO(file_prefix="Water",data_id=i)
    a=randint(1,2**30)
    b=randint(a,2**30)
    c=randint(1,2**30)
    d=randint(c,2**30)
    test_data.input_writeln(a,b);
    test_data.input_writeln(c,d);
    test_data.output_gen("./std")