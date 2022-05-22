.data
s1: .asciiz"Nhap vao so nguyen: "
kq: .asciiz"So fibonacci tuong ung la: "
.text
addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x00000000
syscall

addi $v0, $0, 5
syscall
add $a0, $v0, $0

jal fibonacci
add $a1, $v0, $0

addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x00000015
syscall

addi $v0, $0, 1
add $a0, $a1, $0
syscall
j exit1
fibonacci:
	addi $sp, $sp, -4
	sw $ra, ($sp)
	
	beq $a0, $zero, return0
	addi $t0, $0, 1
	beq $a0, $t0, return1
	
	addi $a0, $a0, -1
	
	addi $sp, $sp, -8
	sw $a0, ($sp)
	sw $t0, 4($sp)
	jal fibonacci
	lw $a0, ($sp)
	lw $t0, 4($sp)
	addi $sp, $sp, 8

	add $t0, $v0, $0
	addi $a0, $a0, -1

	addi $sp, $sp, -8
	sw $a0, ($sp)
	sw $t0, 4($sp)
	jal fibonacci
	lw $a0, ($sp)
	lw $t0, 4($sp)
	addi $sp, $sp, 8

	add $v0, $v0, $t0
	exit:
		lw $ra, ($sp)
		addi $sp, $sp, 4
		jr $ra
	return0:
		add $v0, $zero, $0
		j exit
	return1:
		add $v0, $zero, $0
		addi $v0, $v0, 1
		j exit
exit1: