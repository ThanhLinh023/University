.data
string1: .asciiz "Chao ban! Ban la sinh vien nam thu may?\n" #Kh?i t?o chu?i th? 1
string2: .asciiz "Hihi, minh la sinh vien nam thu 1 ^-^" #Kh?i t?o chu?i th? 2
.text
li $v0, 4 #Kh?i t?o giá tr? cho thanh ghi $v0 là 4
la $a0, string1 #Kh?i t?o thanh ghi $a0 v?i ??a ch? c?a chu?i th? 1
syscall #L?nh h? th?ng ?? in ra chu?i th? nh?t
li $v0, 4 #Kh?i t?o giá tr? cho thanh ghi $v0 là 4
la $a0, string2 #Kh?i t?o thanh ghi $a0 v?i ??a ch? c?a chu?i th? 2
syscall #L?nh h? th?ng ?? in ra chu?i th? 2