.data
s1: .asciiz"Nhap a: "
s2: .asciiz"Nhap b: "
s3: .asciiz"Nhap c: "
s4: .asciiz"Nhap d: "
s5: .asciiz"Nhap e: "
s6: .asciiz"Nhap f: "
kq1: .asciiz"(a + b) - (c + d) = "
kq2: .asciiz"\ne - f = "
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
#Nhap e
addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x00000024
syscall

addi $v0, $0, 5
syscall
addi $t2, $v0, 0
#Nhap f
addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x0000002d
syscall

addi $v0, $0, 5
syscall
addi $t3, $v0, 0

addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x00000036
syscall
#Truyen tham chieu cho ham
add $a0, $t2, $0
sw $a0, 16($sp)
add $a0, $t3, $0
sw $a0, 20($sp)
add $a0, $s0, $0
add $a1, $s1, $0
add $a2, $s2, $0
add $a3, $s3, $0
add $s7, $sp, $0

jal proc_example

add $a0, $v0, $0
addi $v0, $0, 1
syscall

addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x0000004b
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
	sub $s1, $t2, $t3
	add $v1, $s1, $0
	
	lw $s1, 0($sp)
	addi $sp, $sp, 4
	jr $ra
exit:
