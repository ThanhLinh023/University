from distutils.log import info

Type = {
    "add" : "R", "addu" : "R", "and" : "R", "jr" : "R",
    "addi" : "I", "addiu" : "I", "andi" : "I", "beq" : "I", "bne" : "I",
    "lbu" : "I", "lhu" : "I", "lui" : "I", "lw" : "I", "ll" : "I",
    "j" : "J", "jal" : "J"
}
Reg = {
    "$zero" : "00000", "$0" : "00000", "$at" : "00001", "$v0" : "00010", "$v1" : "00011",
    "$a0" : "00100", "$a1" : "00101", "$a2" : "00110", "$a3" : "00111", "$t0" : "01000",
    "$t1" : "01001", "$t2" : "01010", "$t3" : "01011", "$t4" : "01100", "$t5" : "01101",
    "$t6" : "01110", "$t7" : "01111", "$t8" : "11000", "$t9" : "11001", 
    "$s0" : "10000", "$s1" : "10001", "$s2" : "10010", "$s3" : "10011", "$s4" : "10100", "$s5" : "10101",
    "$s6" : "10110", "$s7" : "10111", "$k0" : "11010", "$k1" : "11011", "$gp" : "11100", "$sp" : "11101",
    "$fp" : "11110", "$ra" : "11111"
}
Opcode = {
    "add" : "000000", "addu" : "000000", "and" : "000000", "jr" : "000000",
    "addi" : "001000", "addiu" : "001001", "andi" : "001100", "beq" : "000100",
    "bne" : "000101", "lbu" : "100100", "lhu" : "100101", "lui" : "001111",
    "lw" : "100011", "sw" : "101011", "j" : "000010", "jal" : "000011", "ll" : "110000"
}
Func = {
    "add" : "100000", "addu" : "100001", "and" : "100100", "jr" : "001000"
}
def signedDecToBin16(n):
    if n < 0:
        n = n + 2**16
    return bin(n)[2:].zfill(16)
def addressToBin26(n):
    n = n >> 2
    if n < 0:
        n = n + 2**16
    return bin(n)[2:].zfill(26)
def tachNgoacPhay(a):
    t1 = a.replace(",", " ")
    t1 = t1.replace("(", " ")
    t1 = t1.replace(")", "")
    t2 = t1.split()
    t3 = ''
    for i in t2:
        t3 = t3 + i + ' '
    return t3
def branchAddr(Pc, Ad):
    t = int(Ad - Pc)
    t = int((t / 4) - 1)
    return t

inp = open('Input.asm')
temp = open('tempFile.txt', 'w+')
out = open('Output.txt', 'w')

content = inp.readlines()
for i in content:
    t1 = tachNgoacPhay(i)
    if t1 == "":
        continue
    if t1.find('#') != -1:
        t1 = t1[0:t1.find('#')]
    if t1 == "":
        continue
    if t1.find(':') != -1:
        s1 = t1.split(': ')
        temp.write(s1[0] + ':')
        temp.write('\n')
        if (len(s1[1]) > 1):
            temp.write(s1[1])
            temp.write('\n')
        continue
    temp.write(t1)
    temp.write('\n')
inp.close()

temp.seek(0)
str1 = temp.readlines()
a = str1.index('.text \n')
while (a > - 1):
    str1.pop(0)
    a = a - 1

Label = {}
Pc = 4194304
for i in str1:
    Pc = Pc + 4
    if i.find(':') != -1:
        Pc = Pc - 4
        i = i[0: len(i) - 2]
        Label.setdefault(i, Pc)

Pc = 4194304
for i in str1:
    if i.find(':') != -1:
        continue
    data = i.split()
    if Type[data[0]] == "R":
        if data[0] == "jr":
            out.write(Opcode[data[0]] +Reg[data[1]] + "000000000000000" + Func[data[0]] + '\n')
        else:
            out.write(Opcode[data[0]] + Reg[data[2]] + Reg[data[3]] + Reg[data[1]] + "00000"+Func[data[0]] + '\n')
        
    elif Type[data[0]] == "I":
        Pctemp = Pc
        if data[0] == "bne" or data[0] == "beq":
            out.write(Opcode[data[0]] + Reg[data[1]] + Reg[data[2]] + str(signedDecToBin16(branchAddr(Pctemp, Label[data[3]]))) + '\n')
        elif data[0] == "lbu" or data[0] == "lhu" or data[0] == "ll" or data[0] == "lw":
            out.write(Opcode[data[0]] + Reg[data[3]] + Reg[data[1]] + str(signedDecToBin16(int(data[2]))) + '\n')
        elif data[0] == "lui":
            out.write(Opcode[data[0]] + "00000" + Reg[data[1]] + str(signedDecToBin16(int(data[2]))) + '\n')
        else:
           out.write(Opcode[data[0]] + Reg[data[2]] + Reg[data[1]] + str(signedDecToBin16(int(data[3]))) + '\n')
 
    elif Type[data[0]] == "J":
        out.write(Opcode[data[0]] + str(addressToBin26(Label[data[1]])) + '\n')
    Pc = Pc + 4
out.close()
