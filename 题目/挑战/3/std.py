from cyaron import *     
for i in range(16,21):
    test_data=IO(file_prefix="challenge",data_id=i)
    A=""
    B=""
    Al=randint(1000,2000)
    Bl=randint(1000,2000)
    for j in range(1,Al):
        tag=randint(1,4)
        if tag==1:
            A+='A'
        if tag==2:
            A+='T'
        if tag==3:
            A+='G'
        if tag==4:
            A+='C'
    for j in range(1,Bl):
        tag=randint(1,4)
        if tag==1:
            B+='A'
        if tag==2:
            B+='T'
        if tag==3:
            B+='G'
        if tag==4:
            B+='C'  
    test_data.input_writeln(3)
    test_data.input_writeln(A)
    test_data.input_writeln(B)
    test_data.output_gen("./std")