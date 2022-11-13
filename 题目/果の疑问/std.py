from cyaron import *  
_n=ati([1,30,30,30,30,30,30,30,30,30,30])
for i in range(1,11):
    test_data=IO(file_prefix="",data_id=i)
    n=15
    m=30
    test_data.input_writeln(n,m)
    graph=Graph.graph(n,m,weight_limit=1000000000)
    test_data.input_writeln(graph)
    test_data.output_gen("./std")