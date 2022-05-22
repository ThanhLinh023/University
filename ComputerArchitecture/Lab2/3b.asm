.data
s1: .asciiz "Nhap 2 so: "
s2: .asciiz "So lon hon la: "
s3: .asciiz "\nTong: "
s4: .asciiz "\nHieu: "
s5: .asciiz "\nTich: "
s6: .asciiz "\nThuong: "
.text
addi $v0, $zero, 4 
lui $at, 0x00001001
ori $a0, $at, 0x00000000
syscall

addi $v0, $zero, 5 
syscall
addi $t0, $v0, 0

addi $v0, $zero, 5
syscall
addi $t1, $v0, 0

addi $v0, $zero, 4 
lui $at, 0x00001001
ori $a0, $at, 0x0000000c
syscall

slt $t2, $t0, $t1
bne $t2, $0, IF
addi $v0, $0, 1
add $a0, $0, $t0
syscall
j tinhtoan

IF:	addi $v0, $0, 1
	add $a0, $0, $t1
	syscall
	j tinhtoan
tinhtoan:
	addi $v0, $zero, 4 
	lui $at, 0x00001001
	ori $a0, $at, 0x0000001c
	syscall

	addi $v0, $zero, 1 
	add $a0, $t0, $t1
	syscall

	addi $v0, $zero, 4 
	lui $at, 0x00001001
	ori $a0, $at, 0x00000024
	syscall

	addi $v0, $zero, 1 
	sub $a0, $t0, $t1
	syscall

	addi $v0, $zero, 4 
	lui $at, 0x00001001
	ori $a0, $at, 0x0000002c
	syscall

	addi $v0, $zero, 1 
	mul $a0, $t0, $t1
	syscall

	addi $v0, $zero, 4 
	lui $at, 0x00001001
	ori $a0, $at, 0x00000034
	syscall

	addi $v0, $zero, 1 
	div $a0, $t0, $t1
	syscall
