.data
s1: .asciiz"Nhap so phan tu: "
s2: .asciiz"Nhap vao mang: "
s3: .asciiz"Max: "
s4: .asciiz"\nMin: "
s5: .asciiz"\nTong cac phan tu: "
s6: .asciiz"\nNhap chi so: "
a: .word 200
.text
nhapN:
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x00000000
	syscall
	
	addi $v0, $0, 5
	syscall
	addi $s0, $v0, 0
	addi $t0, $0, 200
	addi $t1, $0, 0
	slt $t2, $s0, $t0
	slt $t2, $t1, $s0
	beq $t2, $0, nhapN
	
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x00000012
	syscall
	
	addi $v0, $0, 5
	syscall
	addi $s1, $v0, 0
	addi $s2, $v0, 0
	addi $s3, $v0, 0
	lui $1, 0x00001001
	ori $5, $1, 0x00000054
	sw $v0, 0($a1)
	addi $a1, $a1, 4
	addi $s0, $s0, -1
loop:
	addi $v0, $0, 5
	syscall
	sw $v0, 0($a1)
	add $s3, $s3, $v0
max:
	slt $t4, $s1, $v0
	beq $t4, $0, min
	addi $s1, $v0, 0
min:
	slt $t4, $v0, $s2
	beq $t4, $0, ketiep
	addi $s2, $v0, 0
ketiep:
	addi $a1, $a1, 4
	addi $s0, $s0, -1
	beq $s0, $0, print
	j loop
print:
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x00000022
	syscall
	addi $v0, $0, 1
	addi $a0, $s1, 0
	syscall
	
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x00000028
	syscall
	addi $v0, $0, 1
	addi $a0, $s2, 0
	syscall
	
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x0000002f
	syscall
	addi $v0, $0, 1
	addi $a0, $s3, 0
	syscall
	
	addi $v0, $0, 4
	lui $1, 0x00001001
	ori $4, $1, 0x00000043
	syscall
	
	addi $v0, $0, 5
	syscall
	addi $t5, $v0, 0
	
	sll $t5, $t5, 2
	lui $1, 0x00001001
	ori $14, $1, 0x00000054
	add $t6, $t6, $t5
	lw $a0, 0($t6)
	addi $v0, $0, 1
	syscall
	
	
	
	
