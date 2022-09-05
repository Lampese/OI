from cyaron import *
test_data=IO(file_prefix="re",data_id=1)
test_data.input_writeln(10000000,3)
for i in range(1,10000001):
    test_data.input_write(i)
test_data.input_write('\n')
test_data.input_writeln("1 100008")
test_data.input_writeln("200000 9999999")
test_data.input_writeln("100010 100015")
test_data.output_gen("./so")