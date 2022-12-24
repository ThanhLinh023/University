--------------------
create database QuanLyBanHang
go
use QuanLyBanHang
go
-- KHACHANG
CREATE TABLE KHACHHANG(
	MAKH	char(4) not null,	
	HOTEN	varchar(40),
	DCHI	varchar(50),
	SODT	varchar(20),
	NGSINH	smalldatetime,
	NGDK	smalldatetime,
	DOANHSO	money,
	constraint pk_kh primary key(MAKH)
)
---------------------------------------------
-- NHANVIEN
CREATE TABLE NHANVIEN(
	MANV	char(4) not null,	
	HOTEN	varchar(40),
	SODT	varchar(20),
	NGVL	smalldatetime	
	constraint pk_nv primary key(MANV)
)
---------------------------------------------
-- SANPHAM
CREATE TABLE SANPHAM(
	MASP	char(4) not null,
	TENSP	varchar(40),
	DVT	varchar(20),
	NUOCSX	varchar(40),
	GIA	money,
	constraint pk_sp primary key(MASP)	
)
---------------------------------------------
-- HOADON
CREATE TABLE HOADON(
	SOHD	int not null,
	NGHD 	smalldatetime,
	MAKH 	char(4),
	MANV 	char(4),
	TRIGIA	money,
	constraint pk_hd primary key(SOHD)
)
---------------------------------------------
-- CTHD
CREATE TABLE CTHD(
	SOHD	int,
	MASP	char(4),
	SL	int,
	constraint pk_cthd primary key(SOHD,MASP)
)

-- Khoa ngoai cho bang HOADON
ALTER TABLE HOADON ADD CONSTRAINT fk01_HD FOREIGN KEY(MAKH) REFERENCES KHACHHANG(MAKH)
ALTER TABLE HOADON ADD CONSTRAINT fk02_HD FOREIGN KEY(MANV) REFERENCES NHANVIEN(MANV)
-- Khoa ngoai cho bang CTHD
ALTER TABLE CTHD ADD CONSTRAINT fk01_CTHD FOREIGN KEY(SOHD) REFERENCES HOADON(SOHD)
ALTER TABLE CTHD ADD CONSTRAINT fk02_CTHD FOREIGN KEY(MASP) REFERENCES SANPHAM(MASP)
-----------------------------------------------------
-----------------------------------------------------
set dateformat dmy
-------------------------------
-- KHACHHANG
insert into khachhang values('KH01','Nguyen Van A','731 Tran Hung Dao, Q5, TpHCM','8823451','22/10/1960','22/07/2006',13060000)
insert into khachhang values('KH02','Tran Ngoc Han','23/5 Nguyen Trai, Q5, TpHCM','908256478','03/04/1974','30/07/2006',280000)
insert into khachhang values('KH03','Tran Ngoc Linh','45 Nguyen Canh Chan, Q1, TpHCM','938776266','12/06/1980','08/05/2006',3860000)
insert into khachhang values('KH04','Tran Minh Long','50/34 Le Dai Hanh, Q10, TpHCM','917325476','09/03/1965','10/02/2006',250000)
insert into khachhang values('KH05','Le Nhat Minh','34 Truong Dinh, Q3, TpHCM','8246108','10/03/1950','28/10/2006',21000)
insert into khachhang values('KH06','Le Hoai Thuong','227 Nguyen Van Cu, Q5, TpHCM','8631738','31/12/1981','24/11/2006',915000)
insert into khachhang values('KH07','Nguyen Van Tam','32/3 Tran Binh Trong, Q5, TpHCM','916783565','06/04/1971','12/01/2006',12500)
insert into khachhang values('KH08','Phan Thi Thanh','45/2 An Duong Vuong, Q5, TpHCM','938435756','10/01/1971','13/12/2006',365000)
insert into khachhang values('KH09','Le Ha Vinh','873 Le Hong Phong, Q5, TpHCM','8654763','03/09/1979','14/01/2007',70000)
insert into khachhang values('KH10','Ha Duy Lap','34/34B Nguyen Trai, Q1, TpHCM','8768904','02/05/1983','16/01/2007',67500)

-------------------------------
-- NHANVIEN
insert into nhanvien values('NV01','Nguyen Nhu Nhut','927345678','13/04/2006')
insert into nhanvien values('NV02','Le Thi Phi Yen','987567390','21/04/2006')
insert into nhanvien values('NV03','Nguyen Van B','997047382','27/04/2006')
insert into nhanvien values('NV04','Ngo Thanh Tuan','913758498','24/06/2006')
insert into nhanvien values('NV05','Nguyen Thi Truc Thanh','918590387','20/07/2006')

-------------------------------
-- SANPHAM
insert into sanpham values('BC01','But chi','cay','Singapore',3000)
insert into sanpham values('BC02','But chi','cay','Singapore',5000)
insert into sanpham values('BC03','But chi','cay','Viet Nam',3500)
insert into sanpham values('BC04','But chi','hop','Viet Nam',30000)
insert into sanpham values('BB01','But bi','cay','Viet Nam',5000)
insert into sanpham values('BB02','But bi','cay','Trung Quoc',7000)
insert into sanpham values('BB03','But bi','hop','Thai Lan',100000)
insert into sanpham values('TV01','Tap 100 giay mong','quyen','Trung Quoc',2500)
insert into sanpham values('TV02','Tap 200 giay mong','quyen','Trung Quoc',4500)
insert into sanpham values('TV03','Tap 100 giay tot','quyen','Viet Nam',3000)
insert into sanpham values('TV04','Tap 200 giay tot','quyen','Viet Nam',5500)
insert into sanpham values('TV05','Tap 100 trang','chuc','Viet Nam',23000)
insert into sanpham values('TV06','Tap 200 trang','chuc','Viet Nam',53000)
insert into sanpham values('TV07','Tap 100 trang','chuc','Trung Quoc',34000)
insert into sanpham values('ST01','So tay 500 trang','quyen','Trung Quoc',40000)
insert into sanpham values('ST02','So tay loai 1','quyen','Viet Nam',55000)
insert into sanpham values('ST03','So tay loai 2','quyen','Viet Nam',51000)
insert into sanpham values('ST04','So tay','quyen','Thai Lan',55000)
insert into sanpham values('ST05','So tay mong','quyen','Thai Lan',20000)
insert into sanpham values('ST06','Phan viet bang','hop','Viet Nam',5000)
insert into sanpham values('ST07','Phan khong bui','hop','Viet Nam',7000)
insert into sanpham values('ST08','Bong bang','cai','Viet Nam',1000)
insert into sanpham values('ST09','But long','cay','Viet Nam',5000)
insert into sanpham values('ST10','But long','cay','Trung Quoc',7000)

-------------------------------
-- HOADON
insert into hoadon values(1001,'23/07/2006','KH01','NV01',320000)
insert into hoadon values(1002,'12/08/2006','KH01','NV02',840000)
insert into hoadon values(1003,'23/08/2006','KH02','NV01',100000)
insert into hoadon values(1004,'01/09/2006','KH02','NV01',180000)
insert into hoadon values(1005,'20/10/2006','KH01','NV02',3800000)
insert into hoadon values(1006,'16/10/2006','KH01','NV03',2430000)
insert into hoadon values(1007,'28/10/2006','KH03','NV03',510000)
insert into hoadon values(1008,'28/10/2006','KH01','NV03',440000)
insert into hoadon values(1009,'28/10/2006','KH03','NV04',200000)
insert into hoadon values(1010,'01/11/2006','KH01','NV01',5200000)
insert into hoadon values(1011,'04/11/2006','KH04','NV03',250000)
insert into hoadon values(1012,'30/11/2006','KH05','NV03',21000)
insert into hoadon values(1013,'12/12/2006','KH06','NV01',5000)
insert into hoadon values(1014,'31/12/2006','KH03','NV02',3150000)
insert into hoadon values(1015,'01/01/2007','KH06','NV01',910000)
insert into hoadon values(1016,'01/01/2007','KH07','NV02',12500)
insert into hoadon values(1017,'02/01/2007','KH08','NV03',35000)
insert into hoadon values(1018,'13/01/2007','KH08','NV03',330000)
insert into hoadon values(1019,'13/01/2007','KH01','NV03',30000)
insert into hoadon values(1020,'14/01/2007','KH09','NV04',70000)
insert into hoadon values(1021,'16/01/2007','KH10','NV03',67500)
insert into hoadon values(1022,'16/01/2007',Null,'NV03',7000)
insert into hoadon values(1023,'17/01/2007',Null,'NV01',330000)

-------------------------------
-- CTHD
insert into cthd values(1001,'TV02',10)
insert into cthd values(1001,'ST01',5)
insert into cthd values(1001,'BC01',5)
insert into cthd values(1001,'BC02',10)
insert into cthd values(1001,'ST08',10)
insert into cthd values(1002,'BC04',20)
insert into cthd values(1002,'BB01',20)
insert into cthd values(1002,'BB02',20)
insert into cthd values(1003,'BB03',10)
insert into cthd values(1004,'TV01',20)
insert into cthd values(1004,'TV02',10)
insert into cthd values(1004,'TV03',10)
insert into cthd values(1004,'TV04',10)
insert into cthd values(1005,'TV05',50)
insert into cthd values(1005,'TV06',50)
insert into cthd values(1006,'TV07',20)
insert into cthd values(1006,'ST01',30)
insert into cthd values(1006,'ST02',10)
insert into cthd values(1007,'ST03',10)
insert into cthd values(1008,'ST04',8)
insert into cthd values(1009,'ST05',10)
insert into cthd values(1010,'TV07',50)
insert into cthd values(1010,'ST07',50)
insert into cthd values(1010,'ST08',100)
insert into cthd values(1010,'ST04',50)
insert into cthd values(1010,'TV03',100)
insert into cthd values(1011,'ST06',50)
insert into cthd values(1012,'ST07',3)
insert into cthd values(1013,'ST08',5)
insert into cthd values(1014,'BC02',80)
insert into cthd values(1014,'BB02',100)
insert into cthd values(1014,'BC04',60)
insert into cthd values(1014,'BB01',50)
insert into cthd values(1015,'BB02',30)
insert into cthd values(1015,'BB03',7)
insert into cthd values(1016,'TV01',5)
insert into cthd values(1017,'TV02',1)
insert into cthd values(1017,'TV03',1)
insert into cthd values(1017,'TV04',5)
insert into cthd values(1018,'ST04',6)
insert into cthd values(1019,'ST05',1)
insert into cthd values(1019,'ST06',2)
insert into cthd values(1020,'ST07',10)
insert into cthd values(1021,'ST08',5)
insert into cthd values(1021,'TV01',7)
insert into cthd values(1021,'TV02',10)
insert into cthd values(1022,'ST07',1)
insert into cthd values(1023,'ST04',6)


--------------------
--Buổi 2:
--Phần I:
--Câu 2:
alter table SANPHAM add GHICHU varchar(20)
--Câu 3:
alter table KhachHang add LOAIKH tinyint
--Câu 4:
alter table SANPHAM alter column GHICHU varchar(100)
--Câu 5:
alter table SANPHAM drop column GHICHU
--Câu 6:
alter table KhachHang alter column LOAIKH varchar(50)
--Câu 7:
alter table SANPHAM add constraint CK_DVT check (DVT in ('cay','hop','cai','quyen','chuc'))
--Câu 8:
alter table SANPHAM add constraint GIABAN check (GIA > 500)
--Câu 9:
alter table CTHD add constraint SOLUONG check (SL >= 1)
--Câu 10:
alter table KhachHang add constraint DANGKI check (NGDK > NGSINH)
--Phần II:
--Câu 2:
select * into SANPHAM1 from SANPHAM
select * into KHACHHANG1 from KhachHang
--Câu 3:
update SANPHAM1 set GIA = GIA + GIA * 0.5 where NUOCSX = 'Thai Lan'
--Câu 4:
update SANPHAM1 set GIA = GIA - GIA *0.5 where NUOCSX = 'Trung Quoc' and GIA <= 10000
--Câu 5:
update KHACHHANG1 set LOAIKH = 'Vip' 
where (NGDK < '1/1/2007' and DOANHSO >= 10000000) or (NGDK > '1/1/2007' and DOANHSO >= 2000000)
--Phần III:
--Câu 1:
select MASP, TENSP from SANPHAM where NUOCSX = 'Trung Quoc'
--Câu 2:
select MASP, TENSP from SANPHAM where DVT = 'cay' or DVT = 'quyen'
--Câu 3:
select MASP, TENSP from SANPHAM where MASP like 'B%01'
--Câu 4:
select MASP, TENSP from SANPHAM 
where NUOCSX = 'Trung Quoc' and GIA >= 30000 and GIA <= 40000
--Câu 5:
select MASP, TENSP from SANPHAM 
where (NUOCSX = 'Trung Quoc' or NUOCSX = 'Thai Lan') and (GIA >= 30000 and GIA <= 40000)

--Buổi 3: Phần III

--Câu 6:
select SOHD, TRIGIA from HOADON 
where NGHD = '1/1/2007' or NGHD = '2/1/2007'
--Câu 7:
select SOHD, TRIGIA, NGHD from HOADON 
where month(NGHD) = '1' and year(NGHD) = '2007'
order by NGHD ASC, TRIGIA DESC
--Câu 8:
select KhachHang.MAKH, KhachHang.HOTEN from KhachHang inner join HOADON 
on KhachHang.MAKH = HOADON.MAKH and HOADON.NGHD = '1/1/2007';
--Câu 9:
select HOADON.SOHD, HOADON.TRIGIA from HOADON join NHANVIEN
on NHANVIEN.MANV = HOADON.MANV and NHANVIEN.HOTEN = 'Nguyen Van B' and HOADON.NGHD = '28/10/2006';
--Câu 10:
select SP.MaSP, TenSP from SanPham SP, KhachHang KH, CTHD, HoaDon HD
where SP.MASP = CTHD.MaSP
and KH.MaKH = HD.MAKH
and CTHD.SOHD = HD.SOHD
and KH.HoTen = 'Nguyen Van A'
and year(HD.NGHD) = 2006 and month(HD.NGHD) = 10
--Câu 11:
select distinct SoHD from CTHD
where MaSP = 'BB01' or MaSP = 'BB02'
--Câu 12:
select SoHD from CTHD
where MaSP = 'BB01' or MaSP = 'BB02'
and SL between 10 and 20
--Câu 13:
(select SoHD from CTHD
where MaSP = 'BB01' and SL between 10 and 20)
intersect
(select SoHD from CTHD
where MaSP = 'BB02' and SL between 10 and 20)
--Câu 14:
select distinct SanPham.MaSP, TenSp from SanPham, HoaDon, CTHD
where (NUOCSX = 'Trung Quoc') or (NgHD = '1/1/2007')
and SanPham.MaSP = CTHD.MASP
and HoaDon.SoHD = CTHD.SoHD
--Câu 15:
select SanPham.MaSP, TenSP from SanPham
where MaSP not in (select MaSP from CTHD)
--Câu 16:
select MaSP, TenSP from SanPham
where MaSP not in 
(
	select MaSP from CTHD join HoaDon
	on CTHD.SOHD = HoaDon.SoHD
	and year(NgHD) = 2006
)
--Câu 17:
select MaSP, TenSP from SanPham
where NuocSX = 'Trung Quoc'
and MaSP not in 
(
	select MaSP from CTHD join HoaDon
	on CTHD.SOHD = HoaDon.SoHD
	and year(NgHD) = 2006
)
--Câu 18:
select SoHD from HoaDon
where not exists
(
	select * from SanPham where NuocSX = 'Singapore'
	and not exists 
		(select * from CTHD 
		where HoaDon.SoHD = CTHD.SoHD 
		and SanPham.MaSP = CTHD.MaSP)
)
--Câu 19:
select SoHD from HoaDon
where not exists
(
	select * from SanPham where NuocSX = 'Singapore'
	and not exists 
		(select * from CTHD 
		where HoaDon.SoHD = CTHD.SoHD 
		and SanPham.MaSP = CTHD.MaSP)
)
and year(NgHD) = 2006

--Buổi 4: Phần III

--Câu 20:
select count(SoHD) as SoLuongHoaDon from HoaDon
where MaKH is null
--Câu 21:
select count(distinct MaSP) from CTHD, HoaDon
where CTHD.SoHD = HoaDon.SOHD
and year(NgHD) = 2006
--Câu 22:
select max(TriGia) as CaoNhat, min(TriGia) as ThapNhat
from HoaDon
--Câu 23:
select avg(TriGia) as TrungBinh from HoaDon
where year(NgHD) = 2006
--Câu 24:
select sum(TriGia) as DoanhThu from HoaDon
where year(NgHD) = 2006
--Câu 25:
select top 1 SoHD from HoaDon
where year(NgHD) = 2006
order by TriGia desc
--Câu 26:
select top 1 with ties HoTen from KhachHang, HoaDon
where KhachHang.MaKH = HoaDon.MaKH
order by TriGia desc
--Câu 27:
select top 3 MaKH, HoTen from KhachHang
order by DoanhSo desc
--Câu 28:
select MaSP, TenSP from SanPham
where Gia in
(
	select distinct top 3 Gia from SanPham
	order by Gia desc
)
--Câu 29:
select MaSP, TenSP from SanPham
where Gia in
(
	select distinct top 3 Gia from SanPham
	order by Gia desc
)
and NuocSX = 'Thai Lan'
--Câu 30:
select MaSP, TenSP from SanPham
where Gia in
(
	select distinct top 3 Gia from SanPham
	where NuocSX = 'Trung Quoc'
	order by Gia desc
)
and NuocSX = 'Trung Quoc'
--Câu 31:
select top 3 * from KhachHang
order by DoanhSo desc
--Câu 32:
select count(MaSP) as SoSanPhamTQ from SanPham
where NuocSX = 'Trung Quoc'
--Câu 33:
select NuocSX, count(MaSP) as SoLuongSanXuat from SanPham
group by NuocSX
--Câu 34:
select NuocSX, max(Gia) as LonNhat, min(Gia) as NhoNhat, avg(Gia) as TrungBinh from SanPham
group by NuocSX
--Câu 35:
select NgHD, sum(TriGia) as DoanhThu from HoaDon
group by NgHD
--Câu 36:
select SanPham.MaSP, sum(SL) as SLBanRa from SanPham, HoaDon, CTHD
where SanPham.MaSP = CTHD.MaSP
and HoaDon.SoHD = CTHD.SoHD
and month(NgHD) = 10 and year(NgHD) = 2006
group by SanPham.MaSP
--Câu 37:
select month(NgHD) as Thang, sum(TriGia) as DoanhThu from HoaDon
where year(NgHD) = 2006
group by month(NgHD)
--Câu 38:
select SoHD, count(SoHD) as SLMua from CTHD
group by SoHD
having count(SoHD) >= 4
--Câu 39:
select SoHD from CTHD
where MaSP in
(
	select MaSP from SanPham
	where NuocSX = 'Viet Nam'
)
group by SoHD
having count(SoHD) = 3
--Câu 40:
select top 1 KhachHang.MaKH, HoTen from HoaDon, KhachHang
where KhachHang.MaKH = HoaDon.MaKH
group by KhachHang.MaKH, HoTen
order by count(HoaDon.MaKH) desc
--Câu 41:
select top 1 with ties month(NgHD) as Thang, sum(TriGia) as DoanhThu from HoaDon
where year(NgHD) = 2006
group by month(NgHD)
order by DoanhThu desc
--Câu 42:
select top 1 with ties SanPham.MaSP, SanPham.TenSP, sum(SL) as SLBanRa from SanPham, HoaDon, CTHD
where SanPham.MaSP = CTHD.MaSP
and HoaDon.SoHD = CTHD.SoHD
and year(NgHD) = 2006
group by SanPham.MaSP, SanPham.TenSP
order by SLBanRa asc
--Câu 43:
select MaSP, TenSP from SanPham as SP1
where Gia in
(
	select max(Gia) from SanPham as SP2
	where SP1.NuocSX = SP2.NuocSX
)
group by MaSP, TenSP
--Câu 44:
select NuocSX, count(distinct Gia) as SLKhacNhau from SanPham
group by NuocSX
having count(distinct Gia) >= 3
--Câu 45:
select top 1 with ties KhachHang.MaKH, KhachHang.HoTen, count(*) as SoLanMua 
from HoaDon join KhachHang
on HoaDon.MaKH = KhachHang.MaKH
where HoaDon.MaKH in
(
	select top 10 MaKH from KhachHang
	order by DoanhSo desc
)
group by KhachHang.MaKH, KhachHang.HoTen
order by count(*) desc



--Buổi 5: Trigger
--Phần I:
--Câu 11:
create trigger NgMua_DK
on HoaDon for insert, update
as
begin
	declare @NgDK smalldatetime
	declare @NgHD smalldatetime
	select @NgDK = NgDK, @NgHD = NgHD from inserted, KhachHang
	where KhachHang.MaKH = inserted.MaKH
	if (@NgHD < @NgDK)
	begin
		print N'Ngày lập hóa đơn phải lớn hơn ngày đăng kí của khách hàng'
		rollback transaction
	end
	else
		print N'Cập nhật/thêm thành công'
end
--Câu 12:
create trigger Trg_Check_NgVL
on NhanVien for insert, update
as
begin
	declare @NgVL smalldatetime
	declare @NgHD smalldatetime
	select @NgVL = NgVL, @NgHD = NgHD from inserted, HoaDon
	where inserted.MaNV = HoaDon.MaNV
	if (@NgVL > @NgHD)
	begin
		print N'Ngày vào làm của nhân viên phải nhỏ hơn ngày bán hàng'
		rollback transaction
	end
	else
		print N'Cập nhật/thêm thành công'
end
--Câu 13:
create trigger Trg_Check_CTHD
on HoaDon for delete, update
as
begin
	declare @SL int
	select @SL = count(CTHD.SoHD) from inserted, CTHD
	where inserted.SoHD = CTHD.SoHD
	if (@SL < 1)
	begin
		print N'Mỗi hóa đơn phải có ít nhất 1 chi tiết hóa đơn'
		rollback transaction
	end
end