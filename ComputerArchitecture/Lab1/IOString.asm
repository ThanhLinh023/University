.data
s1: .asciiz "Nhap : "  
s2: .asciiz "Xuat : "
chuoi: .space 255 #Kh?i t?o b? nh? c� t�n chuoi
.text
li $v0, 4 #Kh?i t?o $v0 c� gi� tr? 4
la $a0, s1 #Kh?i t?o $a0 v?i ??a ch? c?a s1
syscall #L?nh h? th?ng in ra "Nhap : "

li $v0, 8 #Kh?i t?o $v0 c� gi� tr? 8
la $a0, chuoi #Kh?i t?o $a0 v?i ??a ch? cua bi?n chuoi
li $a1, 256 #Kh?i t?o $a1 v?i gi� tr? 256 t??ng ?ng v?i ?? d�i 
syscall #L?nh h? th?ng d�ng ?? nh?p chu?i v�o

li $v0, 4 #Kh?i t?o $v0 c� gi� tr? 4
la $a0, s2 #Kh?i t?o $a0 v?i ??a ch? c?a s2
syscall #L?nh h? th?ng in ra "Xuat : "

li $v0, 4 #Kh?i t?o $v0 c� gi� tr? 4
la $a0, chuoi #Kh?i t?o $a0 v?i ??a ch? cua bi?n chuoi
syscall #L?nh h? th?ng ?? in ra chu?i v?a nh?p

