.data
s1: .asciiz "Input a : "
s2: .asciiz "Input b : "
s3: .asciiz "Sum = "
.text
li $v0, 4 #Kh?i t?o $v0 b?ng 4
la $a0, s1 #Kh?i t?o $a0 v?i ??a ch? c?a s1
syscall #In ra dong "Input a : "

li $v0, 5 #Kh?i t?o $v0 b?ng 5
syscall #L?nh h? th?ng d�ng ?? nh?p s? nguy�n
move $t0, $v0 #G�n $t0 = $v0 ?? ??c s? nguy�n

li $v0, 4 #Kh?i t?o $v0 b?ng 4
la $a0, s2 #Kh?i t?o $a0 v?i ??a ch? c?a s2
syscall #In ra dong "Input b : "

li $v0, 5 #Kh?i t?o $v0 b?ng 5
syscall #L?nh h? th?ng d�ng ?? nh?p s? nguy�n
move $t1, $v0 #G�n $t1 = $v0 ?? ??c s? nguy�n

li $v0, 4 #Kh?i t?o $v0 b?ng 4
la $a0, s3 #Kh?i t?o $a0 v?i ??a ch? c?a s3
syscall #In ra d�ng "Sum = "

li $v0, 1 #Kh?i t?o $v0 b?ng 1
add $t0, $t0, $t1 #Ph�p c?ng $t0 = $t0 + $t1
la $a0, ($t0) #Kh?i t?o $a0 v?i ??a ch? $t0
syscall #L?nh in ra k?t qu? ph�p c?ng