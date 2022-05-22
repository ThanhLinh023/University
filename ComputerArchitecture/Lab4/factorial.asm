.data
s1: .asciiz"Nhap so nguyen: "
.text
addi $v0, $0, 4
lui $1, 0x00001001
ori $4, $1, 0x00000000
syscall

addi $v0, $0, 5
syscall
add $a0, $v0, $0

jal factorial

add $a0, $v0, $0
addi $v0, $0, 1
syscall

j exit
factorial:
	addi $sp, $sp, -4
	sw $ra, ($sp)
	add $v1, $a0, $0
	addi $v0, $0, 1
	beq $a0, $zero, return
	addi $a0, $a0, -1

	addi $sp, $sp, -8
	sw $v1, 0($sp)
	sw $a0, 4($sp)

	jal factorial
		
	lw $v1, 0($sp)
	lw $a0, 4($sp)
	addi $sp, $sp, 8
	mul $v0, $v0, $v1

	return:
	lw $ra, ($sp)
	addi $sp, $sp, 4
	jr $ra
exit: