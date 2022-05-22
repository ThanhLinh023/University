.data
s1: .asciiz "Nhap : "  
s2: .asciiz "Xuat : "
chuoi: .space 255
.text
li $v0, 4
la $a0, s1 
syscall 

li $v0, 8 
la $a0, chuoi 
li $a1, 256 
syscall 

li $v0, 4 
la $a0, s2 
syscall 

li $v0, 4 
la $a0, chuoi 
syscall


