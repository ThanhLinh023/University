.data
s1: .asciiz "Nhap ky tu: "
s2: .asciiz "\nKy tu truoc: "
s3: .asciiz "\nKy tu sau: "
s4: .asciiz "\ninvalid type"
s5: .asciiz "\nKi tu vua nhap la so"
s6: .asciiz "\nKi tu vua nhap la chu thuong"
s7: .asciiz "\nKi tu vua nhap la chu hoa"
.text 
addi $s1, $0, 48
addi $s2, $0, 57
addi $s3, $0, 65
addi $s4, $0, 90
addi $s5, $0, 97
addi $s6, $0, 122

addi $v0, $0, 4
lui $at, 0x00001001
ori $a0, $at, 0x00000000
syscall

addi $v0, $0, 12
syscall
addi $t0, $v0, 0

slt $t1, $t0, $s1
bne $t1, $0, ELSE
beq $t1, $0, IF1

IF1:
	slt $t2, $t0, $s2
	bne $t2, $0, chuso
	beq $t2, $0, IF2
IF2:
	slt $t3, $t0, $s3
	bne $t3, $0, ELSE
	beq $t3, $0, IF3
IF3:
	slt $t4, $t0, $s4
	bne $t4, $0, chuhoa
	beq $t4, $0, IF4
IF4:
	slt $t5, $t0, $s5
	bne $t5, $0, ELSE
	beq $t5, $0, IF5
IF5:
	slt $t6, $t0, $s6
	bne $t6, $0, chuthuong
	beq $t6, $0, ELSE
chuso:
	addi $v0, $0, 4
	lui $at, 0x00001001
	ori $a0, $at, 0x00000037
	syscall
	j output
chuhoa:
	addi $v0, $0, 4
	lui $at, 0x00001001
	ori $a0, $at, 0x0000006b
	syscall
	j output
chuthuong:
	addi $v0, $0, 4
	lui $at, 0x00001001
	ori $a0, $at, 0x0000004d
	syscall
	j output
ELSE:	addi $v0, $0, 4
	lui $at, 0x00001001
	ori $a0, $at, 0x00000029
	syscall
	j end
output:	addi $v0, $0, 4
	lui $at, 0x00001001
	ori $a0, $at, 0x0000000d
	syscall

	addi $v0, $0, 11
	subi $a0, $t0,1
	syscall

	addi $v0, $0, 4
	lui $at, 0x00001001
	ori $a0, $at, 0x0000001c
	syscall

	addi $v0, $0, 11
	addi $a0, $t0, 1
	syscall
	j end
end: 	addi $v0, $0, 10
	syscall


