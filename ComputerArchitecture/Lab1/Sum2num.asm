.data
s1: .asciiz "Input a : "
s2: .asciiz "Input b : "
s3: .asciiz "Sum = "
.text
li $v0, 4 #Kh?i t?o $v0 b?ng 4
la $a0, s1 #Kh?i t?o $a0 v?i ??a ch? c?a s1
syscall #In ra dong "Input a : "

li $v0, 5 #Kh?i t?o $v0 b?ng 5
syscall #L?nh h? th?ng dùng ?? nh?p s? nguyên
move $t0, $v0 #Gán $t0 = $v0 ?? ??c s? nguyên

li $v0, 4 #Kh?i t?o $v0 b?ng 4
la $a0, s2 #Kh?i t?o $a0 v?i ??a ch? c?a s2
syscall #In ra dong "Input b : "

li $v0, 5 #Kh?i t?o $v0 b?ng 5
syscall #L?nh h? th?ng dùng ?? nh?p s? nguyên
move $t1, $v0 #Gán $t1 = $v0 ?? ??c s? nguyên

li $v0, 4 #Kh?i t?o $v0 b?ng 4
la $a0, s3 #Kh?i t?o $a0 v?i ??a ch? c?a s3
syscall #In ra dòng "Sum = "

li $v0, 1 #Kh?i t?o $v0 b?ng 1
add $t0, $t0, $t1 #Phép c?ng $t0 = $t0 + $t1
la $a0, ($t0) #Kh?i t?o $a0 v?i ??a ch? $t0
syscall #L?nh in ra k?t qu? phép c?ng