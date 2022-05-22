.data
array1: .word 5,6,7,8,1,2,3,9,10,4
size1: .word 10
array2: .byte 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
size2: .word 16
array3: .space 8
size3: .word 8
s1: .asciiz "Array1: "
s2: .asciiz "\nArray2: "
s3: .asciiz "\nArray3: "
space: .asciiz " "
.text
	lui $1, 0x00001001
	ori $8, $1, 0x00000000
	lw $t1, size1 
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x0000004c
	syscall
print1:    
	lw $t3, 0($t0)   
	addi $4, $11, 0x00000000
	addi $v0, $0, 1
	syscall
	lui $1, 0x00001001
	ori $4, $1, 0x00000069
	addi $v0, $0, 4
	syscall
	addi $t0, $t0, 4	
	addi $t1, $t1, -1  
	bne $t1, $0, print1
	
	lui $1, 0x00001001
	ori $8, $1, 0x0000002c 
	lw $t1, size2
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x00000055
	syscall
print2: 
	lb $t3, 0($t0)  
	addi $4, $11, 0x00000000
	addi $v0, $0, 1
	syscall

	lui $1, 0x00001001
	ori $4, $1, 0x00000069
	addi $v0, $0, 4
	syscall
	addi $t0, $t0, 1 
	addi $t1, $t1, -1  
	bne $t1, $0, print2
	
	lw $t0, size3 
	lw $t1, size2 
	lui $1, 0x00001001
	ori $16, $1, 0x0000002c
	lui $1, 0x00001001
	ori $17, $1, 0x00000040
	lui $1, 0x00001001
	ori $18, $1, 0x0000003b
tao3:
	lb $t3, 0($s0) 
	lb $t7, 0($s2)
	
	add $t5, $t3, $t7 
	sb $t5, 0($s1)	
	
	addi $s0, $s0, 1
	addi $s1, $s1, 1
	addi $s2, $s2, -1
	addi $t0, $t0, -1
	bne $t0, $0, tao3 
	
	lui $1, 0x00001001
	ori $8, $1, 0x00000040
	lw $t1, size3 
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x0000005f
	syscall
print3:   
	lb $t3, 0($t0)   
	addi $4, $11, 0x00000000
	addi $v0, $0, 1
	syscall

	lui $1, 0x00001001
	ori $4, $1, 0x00000069
	addi $v0, $0, 4
	syscall

	addi $t0, $t0, 1 
	addi $t1, $t1, -1  
	bne $t1, $0, print3
