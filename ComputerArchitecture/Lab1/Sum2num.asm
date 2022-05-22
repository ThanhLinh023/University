.data
s1: .asciiz "Input a : "
s2: .asciiz "Input b : "
s3: .asciiz "Sum = "
.text
li $v0, 4
la $a0, s1 
syscall 

li $v0, 5 
syscall 
move $t0, $v0 

li $v0, 4 
la $a0, s2 
syscall 

li $v0, 5 
syscall 
move $t1, $v0 

li $v0, 4 
la $a0, s3 
syscall 

li $v0, 1 
add $t0, $t0, $t1 
la $a0, ($t0) 
syscall