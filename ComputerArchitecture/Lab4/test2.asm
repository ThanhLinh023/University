.data
s1: .asciiz"Nhap a: "
s2: .asciiz"Nhap b: "
s3: .asciiz"Nhap c: "
s4: .asciiz"Nhap d: "
kq1: .asciiz"(a + b) - (c + d) = "
kq2: .asciiz"\n(a - b) + (c - d) = "
.text
#Nhap a
addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x00000000
syscall

addi $v0, $0, 5
syscall
add $s0, $v0, $0
#Nhap b
addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x00000009
syscall 

addi $v0, $0, 5
syscall
add $s1, $v0, $0
#Nhap c
addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x00000012
syscall 

addi $v0, $0, 5
syscall
add $s2, $v0, $0
#Nhap d
addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x0000001b
syscall

addi $v0, $0, 5
syscall
add $s3, $v0, $0

addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x00000024
syscall
#Truyen tham chieu cho ham
add $a0, $s0, $0
add $a1, $s1, $0
add $a2, $s2, $0
add $a3, $s3, $0
jal proc_example

add $a0, $v0, $0
addi $v0, $0, 1
syscall

addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x00000039
syscall

add $a0, $v1, $0
addi $v0, $0, 1
syscall
j exit
proc_example:
	addi $sp, $sp, -4
	sw $s0, 0($sp)
	add $t0, $a0, $a1
	add $t1, $a2, $a3
	sub $s0, $t0, $t1
	add $v0, $s0, $0
	
	lw $s0, 0($sp)
	addi $sp, $sp, 4
	
	addi $sp, $sp, -4
	sw $s1, 0($sp)
	sub $t1, $a0, $a1
	sub $t2, $a2, $a3
	add $s1, $t1, $t2
	add $v1, $s1, $0
	
	lw $s1, 0($sp)
	addi $sp, $sp, 4
	jr $ra
exit: