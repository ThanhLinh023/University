.data
s1: .asciiz"Enter number: "
s2: .asciiz"Number is "
.text
main:
	jal getInt
	add $s0, $v0, $0
	add $a0, $s0, $0
	jal showInt
	j exit
getInt:
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x00000000
	syscall
	
	addi $v0, $0, 5
	syscall
	jr $ra
showInt:
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x0000000f
	syscall
	
	addi $v0, $0, 1
	addi $a0, $s0, 1
	syscall
	
	jr $ra
	
exit:
