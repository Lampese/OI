from cyaron import *
_n=ati([0,15000000,15000000,15000000,15000000,15000000,15000000])       
for i in range(1,7):
    test_data=IO(file_prefix="challenge",data_id=i)
    T=_n[i]
    A=""
    B=""
    for j in range(1,T+1):
        tag=randint(1,4)
        if tag==1:
            A+="A"
            B+='T'
        if tag==2:
            A+='T'
            B+='A'
        if tag==3:
            A+='G'
            B+='C'
        if tag==4:
            A+='C'
            B+='G'
    Yes=randint(1,2)
    print(Yes)
    if Yes==2:
        A+='A'
        B+='G'
    test_data.input_writeln(1)
    test_data.input_writeln(A)
    test_data.input_writeln(B)
    if Yes==1:
        test_data.output_writeln("Yes")
    else:
        test_data.output_writeln("No")