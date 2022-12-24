create database QuanLyGiaoVu
go
use QuanLyGiaoVu
go
--------------
CREATE TABLE KHOA(
	MAKHOA	char(4),
	TENKHOA	varchar(40),
	NGTLAP	smalldatetime,
	TRGKHOA	char(4)
	CONSTRAINT PK_KHOA PRIMARY KEY(MAKHOA)
)

CREATE TABLE MONHOC(
	MAMH	char(10),
	TENMH	varchar(40),
	TCLT	tinyint,
	TCTH	tinyint,
	MAKHOA	char(4),
	CONSTRAINT PK_MH PRIMARY KEY(MAMH)
)

CREATE TABLE DIEUKIEN(
	MAMH		char(10),
	MAMH_TRUOC	char(10),
	CONSTRAINT PK_DK PRIMARY KEY(MAMH,MAMH_TRUOC)
)

CREATE TABLE GIAOVIEN(
	MAGV		char(4),
	HOTEN		varchar(40),
	HOCVI		varchar(10),
	HOCHAM		varchar(10),
	GIOITINH	varchar(3),
	NGSINH		smalldatetime,
	NGVL		smalldatetime,
	HESO		numeric(4,2),
	MUCLUONG	money,
	MAKHOA		char(4),
	CONSTRAINT PK_GV PRIMARY KEY(MAGV)
)

CREATE TABLE LOP(
	MALOP	char(3),
	TENLOP	varchar(40),
	TRGLOP	char(5),
	SISO	tinyint,
	MAGVCN	char(4),
	CONSTRAINT PK_LOP PRIMARY KEY(MALOP)
)

CREATE TABLE HOCVIEN(
	MAHV		char(5),
	HO		varchar(40),
	TEN		varchar(10),
	NGSINH		smalldatetime,
	GIOITINH	varchar(3),
	NOISINH		varchar(40),
	MALOP		char(3),
	CONSTRAINT PK_HV PRIMARY KEY(MAHV)
)


CREATE TABLE GIANGDAY(
	MALOP	char(3),
	MAMH	char(10),
	MAGV	char(4),
	HOCKY	tinyint,
	NAM	smallint,
	TUNGAY	smalldatetime,
	DENNGAY	smalldatetime,
	CONSTRAINT PK_GD PRIMARY KEY(MALOP,MAMH)
)

CREATE TABLE KETQUATHI(
	MAHV	char(5),
	MAMH	char(10),
	LANTHI	tinyint,
	NGTHI	smalldatetime,
	DIEM	numeric(4,2),
	KQUA	varchar(10),
	CONSTRAINT PK_KQ PRIMARY KEY(MAHV,MAMH,LANTHI)
)

-------------------------------------------
-- KHOA 	
ALTER TABLE KHOA ADD CONSTRAINT FK_KHOA FOREIGN KEY(TRGKHOA) REFERENCES GIAOVIEN(MAGV)
-------------------------------------------
-- MONHOC 		
ALTER TABLE MONHOC ADD CONSTRAINT FK_MH FOREIGN KEY(MAKHOA) REFERENCES KHOA(MAKHOA)
-------------------------------------------
-- DIEUKIEN 	
ALTER TABLE DIEUKIEN ADD CONSTRAINT FK01_DK FOREIGN KEY(MAMH) REFERENCES MONHOC(MAMH)
ALTER TABLE DIEUKIEN ADD CONSTRAINT FK02_DK FOREIGN KEY(MAMH_TRUOC) REFERENCES MONHOC(MAMH)
-------------------------------------------
-- GIAOVIEN
ALTER TABLE GIAOVIEN ADD CONSTRAINT FK_GV FOREIGN KEY(MAKHOA) REFERENCES KHOA(MAKHOA)
-------------------------------------------
-- LOP
ALTER TABLE LOP ADD CONSTRAINT FK01_LOP FOREIGN KEY(TRGLOP) REFERENCES HOCVIEN(MAHV)
ALTER TABLE LOP ADD CONSTRAINT FK02_LOP FOREIGN KEY(MAGVCN) REFERENCES GIAOVIEN(MAGV)
-------------------------------------------
-- HOCVIEN
ALTER TABLE HOCVIEN ADD CONSTRAINT FK_HV FOREIGN KEY(MALOP) REFERENCES LOP(MALOP)
-------------------------------------------
-- GIANGDAY
ALTER TABLE GIANGDAY ADD CONSTRAINT FK01_GD FOREIGN KEY(MALOP) REFERENCES LOP(MALOP)
ALTER TABLE GIANGDAY ADD CONSTRAINT FK02_GD FOREIGN KEY(MAMH) REFERENCES MONHOC(MAMH)
ALTER TABLE GIANGDAY ADD CONSTRAINT FK03_GD FOREIGN KEY(MAGV) REFERENCES GIAOVIEN(MAGV)
-------------------------------------------
-- KETQUATHI
ALTER TABLE KETQUATHI ADD CONSTRAINT FK01_KQ FOREIGN KEY(MAHV) REFERENCES HOCVIEN(MAHV)
ALTER TABLE KETQUATHI ADD CONSTRAINT FK02_KQ FOREIGN KEY(MAMH) REFERENCES MONHOC(MAMH)

-- KHOA
INSERT INTO KHOA VALUES('KHMT','Khoa hoc may tinh','06/07/2005','GV01')
INSERT INTO KHOA VALUES('HTTT','He thong thong tin','06/07/2005','GV02')
INSERT INTO KHOA VALUES('CNPM','Cong nghe phan mem','06/07/2005','GV04')
INSERT INTO KHOA VALUES('MTT','Mang va truyen thong','20/10/2005','GV03')
INSERT INTO KHOA VALUES('KTMT','Ky thuat may tinh','20/12/2005','Null')

-- LOP
INSERT INTO LOP VALUES('K11','Lop 1 khoa 1','K1108',11,'GV07')
INSERT INTO LOP VALUES('K12','Lop 2 khoa 1','K1205',12,'GV09')
INSERT INTO LOP VALUES('K13','Lop 3 khoa 1','K1305',12,'GV14')

-- MONHOC
INSERT INTO MONHOC VALUES('THDC','Tin hoc dai cuong',4,1,'KHMT')
INSERT INTO MONHOC VALUES('CTRR','Cau truc roi rac',5,0,'KHMT')
INSERT INTO MONHOC VALUES('CSDL','Co so du lieu',3,1,'HTTT')
INSERT INTO MONHOC VALUES('CTDLGT','Cau truc du lieu va giai thuat',3,1,'KHMT')
INSERT INTO MONHOC VALUES('PTTKTT','Phan tich thiet ke thuat toan',3,0,'KHMT')
INSERT INTO MONHOC VALUES('DHMT','Do hoa may tinh',3,1,'KHMT')
INSERT INTO MONHOC VALUES('KTMT','Kien truc may tinh',3,0,'KTMT')
INSERT INTO MONHOC VALUES('TKCSDL','Thiet ke co so du lieu',3,1,'HTTT')
INSERT INTO MONHOC VALUES('PTTKHTTT','Phan tich thiet ke he thong thong tin',4,1,'HTTT')
INSERT INTO MONHOC VALUES('HDH','He dieu hanh',4,0,'KTMT')
INSERT INTO MONHOC VALUES('NMCNPM','Nhap mon cong nghe phan mem',3,0,'CNPM')
INSERT INTO MONHOC VALUES('LTCFW','Lap trinh C for win',3,1,'CNPM')
INSERT INTO MONHOC VALUES('LTHDT','Lap trinh huong doi tuong',3,1,'CNPM')

-- DIEUKIEN
INSERT INTO DIEUKIEN VALUES('CSDL','CTRR')
INSERT INTO DIEUKIEN VALUES('CSDL','CTDLGT')
INSERT INTO DIEUKIEN VALUES('CTDLGT','THDC')
INSERT INTO DIEUKIEN VALUES('PTTKTT','THDC')
INSERT INTO DIEUKIEN VALUES('PTTKTT','CTDLGT')
INSERT INTO DIEUKIEN VALUES('DHMT','THDC')
INSERT INTO DIEUKIEN VALUES('LTHDT','THDC')
INSERT INTO DIEUKIEN VALUES('PTTKHTTT','CSDL')

-- GIANGDAY
INSERT INTO GIANGDAY VALUES('K11','THDC','GV07',1,2006,'01/02/2006','05/12/2006')
INSERT INTO GIANGDAY VALUES('K12','THDC','GV06',1,2006,'01/02/2006','05/12/2006')
INSERT INTO GIANGDAY VALUES('K13','THDC','GV15',1,2006,'01/02/2006','05/12/2006')
INSERT INTO GIANGDAY VALUES('K11','CTRR','GV02',1,2006,'01/09/2006','17/5/2006')
INSERT INTO GIANGDAY VALUES('K12','CTRR','GV02',1,2006,'01/09/2006','17/5/2006')
INSERT INTO GIANGDAY VALUES('K13','CTRR','GV08',1,2006,'01/09/2006','17/5/2006')
INSERT INTO GIANGDAY VALUES('K11','CSDL','GV05',2,2006,'06/01/2006','15/7/2006')
INSERT INTO GIANGDAY VALUES('K12','CSDL','GV09',2,2006,'06/01/2006','15/7/2006')
INSERT INTO GIANGDAY VALUES('K13','CTDLGT','GV15',2,2006,'06/01/2006','15/7/2006')
INSERT INTO GIANGDAY VALUES('K13','CSDL','GV05',3,2006,'08/01/2006','15/12/2006')
INSERT INTO GIANGDAY VALUES('K13','DHMT','GV07',3,2006,'08/01/2006','15/12/2006')
INSERT INTO GIANGDAY VALUES('K11','CTDLGT','GV15',3,2006,'08/01/2006','15/12/2006')
INSERT INTO GIANGDAY VALUES('K12','CTDLGT','GV15',3,2006,'08/01/2006','15/12/2006')
INSERT INTO GIANGDAY VALUES('K11','HDH','GV04',1,2007,'01/02/2007','18/2/2007')
INSERT INTO GIANGDAY VALUES('K12','HDH','GV04',1,2007,'01/02/2007','20/3/2007')
INSERT INTO GIANGDAY VALUES('K11','DHMT','GV07',1,2007,'18/2/2007','20/3/2007')

-- GIAOVIEN
INSERT INTO GIAOVIEN VALUES('GV01','Ho Thanh Son','PTS','GS','Nam','05/02/1950','01/11/2004',5,2250000,'KHMT')
INSERT INTO GIAOVIEN VALUES('GV02','Tran Tam Thanh','TS','PGS','Nam','17/12/1965','20/4/2004',4.5,2025000,'HTTT')
INSERT INTO GIAOVIEN VALUES('GV03','Do Nghiem Phung','TS','GS','Nu','08/01/1950','23/9/2004',4,1800000,'CNPM')
INSERT INTO GIAOVIEN VALUES('GV04','Tran Nam Son','TS','PGS','Nam','22/2/1961','01/12/2005',4.5,2025000,'KTMT')
INSERT INTO GIAOVIEN VALUES('GV05','Mai Thanh Danh','ThS','GV','Nam','03/12/1958','01/12/2005',3,1350000,'HTTT')
INSERT INTO GIAOVIEN VALUES('GV06','Tran Doan Hung','TS','GV','Nam','03/11/1953','01/12/2005',4.5,2025000,'KHMT')
INSERT INTO GIAOVIEN VALUES('GV07','Nguyen Minh Tien','ThS','GV','Nam','23/11/1971','03/01/2005',4,1800000,'KHMT')
INSERT INTO GIAOVIEN VALUES('GV08','Le Thi Tran','KS','Null','Nu','26/3/1974','03/01/2005',1.69,760500,'KHMT')
INSERT INTO GIAOVIEN VALUES('GV09','Nguyen To Lan','ThS','GV','Nu','31/12/1966','03/01/2005',4,1800000,'HTTT')
INSERT INTO GIAOVIEN VALUES('GV10','Le Tran Anh Loan','KS','Null','Nu','17/7/1972','03/01/2005',1.86,837000,'CNPM')
INSERT INTO GIAOVIEN VALUES('GV11','Ho Thanh Tung','CN','GV','Nam','01/12/1980','15/5/2005',2.67,1201500,'MTT')
INSERT INTO GIAOVIEN VALUES('GV12','Tran Van Anh','CN','Null','Nu','29/3/1981','15/5/2005',1.69,760500,'CNPM')
INSERT INTO GIAOVIEN VALUES('GV13','Nguyen Linh Dan','CN','Null','Nu','23/5/1980','15/5/2005',1.69,760500,'KTMT')
INSERT INTO GIAOVIEN VALUES('GV14','Truong Minh Chau','ThS','GV','Nu','30/11/1976','15/5/2005',3,1350000,'MTT')
INSERT INTO GIAOVIEN VALUES('GV15','Le Ha Thanh','ThS','GV','Nam','05/04/1978','15/5/2005',3,1350000,'KHMT')

-- HOCVIEN
INSERT INTO HOCVIEN VALUES('K1101','Nguyen Van','A','27/1/1986','Nam','TpHCM','K11')
INSERT INTO HOCVIEN VALUES('K1102','Tran Ngoc','Han','14/3/1986','Nu','Kien Giang','K11')
INSERT INTO HOCVIEN VALUES('K1103','Ha Duy','Lap','18/4/1986','Nam','Nghe An','K11')
INSERT INTO HOCVIEN VALUES('K1104','Tran Ngoc','Linh','30/3/1986','Nu','Tay Ninh','K11')
INSERT INTO HOCVIEN VALUES('K1105','Tran Minh','Long','27/2/1986','Nam','TpHCM','K11')
INSERT INTO HOCVIEN VALUES('K1106','Le Nhat','Minh','24/1/1986','Nam','TpHCM','K11')
INSERT INTO HOCVIEN VALUES('K1107','Nguyen Nhu','Nhut','27/1/1986','Nam','Ha Noi','K11')
INSERT INTO HOCVIEN VALUES('K1108','Nguyen Manh','Tam','27/2/1986','Nam','Kien Giang','K11')
INSERT INTO HOCVIEN VALUES('K1109','Phan Thi Thanh','Tam','27/1/1986','Nu','Vinh Long','K11')
INSERT INTO HOCVIEN VALUES('K1110','Le Hoai','Thuong','02/05/1986','Nu','Can Tho','K11')
INSERT INTO HOCVIEN VALUES('K1111','Le Ha','Vinh','25/12/1986','Nam','Vinh Long','K11')
INSERT INTO HOCVIEN VALUES('K1201','Nguyen Van','B','02/11/1986','Nam','TpHCM','K12')
INSERT INTO HOCVIEN VALUES('K1202','Nguyen Thi Kim','Duyen','18/1/1986','Nu','TpHCM','K12')
INSERT INTO HOCVIEN VALUES('K1203','Tran Thi Kim','Duyen','17/9/1986','Nu','TpHCM','K12')
INSERT INTO HOCVIEN VALUES('K1204','Truong My','Hanh','19/5/1986','Nu','Dong Nai','K12')
INSERT INTO HOCVIEN VALUES('K1205','Nguyen Thanh','Nam','17/4/1986','Nam','TpHCM','K12')
INSERT INTO HOCVIEN VALUES('K1206','Nguyen Thi Truc','Thanh','03/04/1986','Nu','Kien Giang','K12')
INSERT INTO HOCVIEN VALUES('K1207','Tran Thi Bich','Thuy','02/08/1986','Nu','Nghe An','K12')
INSERT INTO HOCVIEN VALUES('K1208','Huynh Thi Kim','Trieu','04/08/1986','Nu','Tay Ninh','K12')
INSERT INTO HOCVIEN VALUES('K1209','Pham Thanh','Trieu','23/2/1986','Nam','TpHCM','K12')
INSERT INTO HOCVIEN VALUES('K1210','Ngo Thanh','Tuan','14/2/1986','Nam','TpHCM','K12')
INSERT INTO HOCVIEN VALUES('K1211','Do Thi','Xuan','03/09/1986','Nu','Ha Noi','K12')
INSERT INTO HOCVIEN VALUES('K1212','Le Thi Phi','Yen','03/12/1986','Nu','TpHCM','K12')
INSERT INTO HOCVIEN VALUES('K1301','Nguyen Thi Kim','Cuc','06/09/1986','Nu','Kien Giang','K13')
INSERT INTO HOCVIEN VALUES('K1302','Truong Thi My','Hien','18/3/1986','Nu','Nghe An','K13')
INSERT INTO HOCVIEN VALUES('K1303','Le Duc','Hien','21/3/1986','Nam','Tay Ninh','K13')
INSERT INTO HOCVIEN VALUES('K1304','Le Quang','Hien','18/4/1986','Nam','TpHCM','K13')
INSERT INTO HOCVIEN VALUES('K1305','Le Thi','Huong','27/3/1986','Nu','TpHCM','K13')
INSERT INTO HOCVIEN VALUES('K1306','Nguyen Thai','Huu','30/3/1986','Nam','Ha Noi','K13')
INSERT INTO HOCVIEN VALUES('K1307','Tran Minh','Man','28/5/1986','Nam','TpHCM','K13')
INSERT INTO HOCVIEN VALUES('K1308','Nguyen Hieu','Nghia','04/08/1986','Nam','Kien Giang','K13')
INSERT INTO HOCVIEN VALUES('K1309','Nguyen Trung','Nghia','18/1/1987','Nam','Nghe An','K13')
INSERT INTO HOCVIEN VALUES('K1310','Tran Thi Hong','Tham','22/4/1986','Nu','Tay Ninh','K13')
INSERT INTO HOCVIEN VALUES('K1311','Tran Minh','Thuc','04/04/1986','Nam','TpHCM','K13')
INSERT INTO HOCVIEN VALUES('K1312','Nguyen Thi Kim','Yen','09/07/1986','Nu','TpHCM','K13')

-- KETQUATHI
INSERT INTO KETQUATHI VALUES('K1101','CSDL',1,'20/7/2006',10,'Dat')
INSERT INTO KETQUATHI VALUES('K1101','CTDLGT',1,'28/12/2006',9,'Dat')
INSERT INTO KETQUATHI VALUES('K1101','THDC',1,'20/5/2006',9,'Dat')
INSERT INTO KETQUATHI VALUES('K1101','CTRR',1,'13/5/2006',9.5,'Dat')
INSERT INTO KETQUATHI VALUES('K1102','CSDL',1,'20/7/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1102','CSDL',2,'27/7/2006',4.25,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1102','CSDL',3,'08/10/2006',4.5,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1102','CTDLGT',1,'28/12/2006',4.5,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1102','CTDLGT',2,'01/05/2007',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1102','CTDLGT',3,'15/1/2007',6,'Dat')
INSERT INTO KETQUATHI VALUES('K1102','THDC',1,'20/5/2006',5,'Dat')
INSERT INTO KETQUATHI VALUES('K1102','CTRR',1,'13/5/2006',7,'Dat')
INSERT INTO KETQUATHI VALUES('K1103','CSDL',1,'20/7/2006',3.5,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1103','CSDL',2,'27/7/2006',8.25,'Dat')
INSERT INTO KETQUATHI VALUES('K1103','CTDLGT',1,'28/12/2006',7,'Dat')
INSERT INTO KETQUATHI VALUES('K1103','THDC',1,'20/5/2006',8,'Dat')
INSERT INTO KETQUATHI VALUES('K1103','CTRR',1,'13/5/2006',6.5,'Dat')
INSERT INTO KETQUATHI VALUES('K1104','CSDL',1,'20/7/2006',3.75,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1104','CTDLGT',1,'28/12/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1104','THDC',1,'20/5/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1104','CTRR',1,'13/5/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1104','CTRR',2,'20/5/2006',3.5,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1104','CTRR',3,'30/6/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1201','CSDL',1,'20/7/2006',6,'Dat')
INSERT INTO KETQUATHI VALUES('K1201','CTDLGT',1,'28/12/2006',5,'Dat')
INSERT INTO KETQUATHI VALUES('K1201','THDC',1,'20/5/2006',8.5,'Dat')
INSERT INTO KETQUATHI VALUES('K1201','CTRR',1,'13/5/2006',9,'Dat')
INSERT INTO KETQUATHI VALUES('K1202','CSDL',1,'20/7/2006',8,'Dat')
INSERT INTO KETQUATHI VALUES('K1202','CTDLGT',1,'28/12/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1202','CTDLGT',2,'01/05/2007',5,'Dat')
INSERT INTO KETQUATHI VALUES('K1202','THDC',1,'20/5/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1202','THDC',2,'27/5/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1202','CTRR',1,'13/5/2006',3,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1202','CTRR',2,'20/5/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1202','CTRR',3,'30/6/2006',6.25,'Dat')
INSERT INTO KETQUATHI VALUES('K1203','CSDL',1,'20/7/2006',9.25,'Dat')
INSERT INTO KETQUATHI VALUES('K1203','CTDLGT',1,'28/12/2006',9.5,'Dat')
INSERT INTO KETQUATHI VALUES('K1203','THDC',1,'20/5/2006',10,'Dat')
INSERT INTO KETQUATHI VALUES('K1203','CTRR',1,'13/5/2006',10,'Dat')
INSERT INTO KETQUATHI VALUES('K1204','CSDL',1,'20/7/2006',8.5,'Dat')
INSERT INTO KETQUATHI VALUES('K1204','CTDLGT',1,'28/12/2006',6.75,'Dat')
INSERT INTO KETQUATHI VALUES('K1204','THDC',1,'20/5/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1204','CTRR',1,'13/5/2006',6,'Dat')
INSERT INTO KETQUATHI VALUES('K1301','CSDL',1,'20/12/2006',4.25,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1301','CTDLGT',1,'25/7/2006',8,'Dat')
INSERT INTO KETQUATHI VALUES('K1301','THDC',1,'20/5/2006',7.75,'Dat')
INSERT INTO KETQUATHI VALUES('K1301','CTRR',1,'13/5/2006',8,'Dat')
INSERT INTO KETQUATHI VALUES('K1302','CSDL',1,'20/12/2006',6.75,'Dat')
INSERT INTO KETQUATHI VALUES('K1302','CTDLGT',1,'25/7/2006',5,'Dat')
INSERT INTO KETQUATHI VALUES('K1302','THDC',1,'20/5/2006',8,'Dat')
INSERT INTO KETQUATHI VALUES('K1302','CTRR',1,'13/5/2006',8.5,'Dat')
INSERT INTO KETQUATHI VALUES('K1303','CSDL',1,'20/12/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1303','CTDLGT',1,'25/7/2006',4.5,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1303','CTDLGT',2,'08/07/2006',4,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1303','CTDLGT',3,'15/8/2006',4.25,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1303','THDC',1,'20/5/2006',4.5,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1303','CTRR',1,'13/5/2006',3.25,'Khong Dat')
INSERT INTO KETQUATHI VALUES('K1303','CTRR',2,'20/5/2006',5,'Dat')
INSERT INTO KETQUATHI VALUES('K1304','CSDL',1,'20/12/2006',7.75,'Dat')
INSERT INTO KETQUATHI VALUES('K1304','CTDLGT',1,'25/7/2006',9.75,'Dat')
INSERT INTO KETQUATHI VALUES('K1304','THDC',1,'20/5/2006',5.5,'Dat')
INSERT INTO KETQUATHI VALUES('K1304','CTRR',1,'13/5/2006',5,'Dat')
INSERT INTO KETQUATHI VALUES('K1305','CSDL',1,'20/12/2006',9.25,'Dat')
INSERT INTO KETQUATHI VALUES('K1305','CTDLGT',1,'25/7/2006',10,'Dat')
INSERT INTO KETQUATHI VALUES('K1305','THDC',1,'20/5/2006',8,'Dat')
INSERT INTO KETQUATHI VALUES('K1305','CTRR',1,'13/5/2006',10,'Dat')
----------


--Buổi 2:
--Phần I:
--Câu 3:Thuộc tính GIOITINH chỉ có giá trị là "Nam" hoặc "Nu"
alter table GiaoVien add constraint CK_GT check (GioiTinh in ('Nam', 'Nu'))
alter table HocVien add constraint CK_GTHV check (GioiTinh in ('Nam', 'Nu'))
--Câu 4:Điểm số của một lần thi có giá trị từ 0 đến 10 và cần lưu đến 2 số lẽ
alter table KetQuaThi add constraint CK_Diem check (Diem between 0 and 10)
update KetQuaThi set Diem = round(Diem, 2)
--Câu 5:Kết quả thi là “Dat” nếu điểm từ 5 đến 10 và “Khong dat” nếu điểm nhỏ hơn 5.
alter table KetQuaThi add constraint CK_KQ 
check ((Diem >= 5 and Diem <= 10 and KQua = 'Dat') or (Diem < 5 and KQua = 'Khong Dat'))
--Câu 6:Học viên thi một môn tối đa 3 lần.
alter table KetQuaThi add constraint CK_LanThi check (LanThi <= 3)
--Câu 7:Học kỳ chỉ có giá trị từ 1 đến 3.
alter table GiangDay add constraint CK_HK check (HocKy >= 1 and HocKy <= 3)
--Câu 8:Học vị của giáo viên chỉ có thể là “CN”, “KS”, “Ths”, ”TS”, ”PTS”
alter table GiaoVien add constraint CK_HocVi check (HocVi in ('CN', 'KS', 'Ths', 'TS', 'PTS'))
--Câu 11:Học viên ít nhất là 18 tuổi
alter table HocVien add constraint CK_Tuoi check (year(GETDATE()) - year(NgSinh) >= 18)
--Câu 12:Lỗi, Giảng dạy một môn học ngày bắt đầu (TUNGAY) phải nhỏ hơn ngày kết thúc (DENNGAY).
alter table GiangDay add constraint CK_TgDay check (TuNgay < DenNgay)
--Câu 13:Giáo viên khi vào làm ít nhất là 22 tuổi.
alter table GiaoVien add constraint CK_NgVao check (year(NGVL) - year(NGSinh) >= 22)
--Câu 14:Lỗi, Tất cả các môn học đều có số tín chỉ lý thuyết và tín chỉ thực hành chênh lệch nhau không quá 3.
alter table MonHoc add constraint CK_LTTH check (abs(TCLT - TCTH) <= 3 or TCTH = 0)

--Phần III:
--Câu 1:In ra danh sách (mã học viên, họ tên, ngày sinh, mã lớp) lớp trưởng của các lớp.
select MaHV, (Ho + '' + Ten) as HoTen, NgSinh, HocVien.MaLop from HocVien, Lop
where HocVien.MaHV = Lop.TrgLop
/*Câu 2:In ra bảng điểm khi thi (mã học viên, họ tên , lần thi, điểm số) môn CTRR của lớp “K12”, sắp xếp 
theo tên, họ học viên.*/
select HocVien.MaHV, (Ho + '' + Ten) as HoTen, LanThi, Diem from HocVien, KetQuaThi
where MaMH = 'CTRR' and MaLop = 'K12' and HocVien.MaHV = KetQuaThi.MaHV
order by Ten, Ho
/*Câu 3:In ra danh sách những học viên (mã học viên, họ tên) và những môn học mà học viên đó thi lần thứ 
nhất đã đạt.*/
select HocVien.MaHV, (Ho + '' + Ten) as HoTen, MonHoc.TenMH from HocVien, KetQuaThi, MonHoc
where LanThi = 1 and KQua = 'Dat' and KetQuaThi.MaMH = MonHoc.MaMH and HocVien.MaHV = KetQuaThi.MaHV
/*Câu 4:In ra danh sách học viên (mã học viên, họ tên) của lớp “K11” thi môn CTRR không đạt (ở lần thi 1).*/
select HocVien.MaHV, (Ho + '' + Ten) as HoTen from HocVien, KetQuaThi
where MaMH = 'CTRR' and HocVien.MaLop = 'K11' and LanThi = 1 and KQua = 'Khong Dat'
and HocVien.MaHV = KetQuaThi.MaHV
/*Câu 5: Danh sách học viên (mã học viên, họ tên) của lớp “K” thi môn CTRR không đạt (ở tất cả các lần 
thi).*/
select distinct HocVien.MaHV, (Ho + '' + Ten) as HoTen from HocVien, KetQuaThi, Lop
where MaMH = 'CTRR' and Lop.MaLop like 'K%' and KQua = 'Khong Dat'
and HocVien.MaHV = KetQuaThi.MaHV and HocVien.MaLop = Lop.MaLop

--Buổi 3:
--Phần II:
--Câu 1:
update GiaoVien set HeSo = HeSo + 0.2
where MaGV in
(
	select TrgKhoa from Khoa
)
--Câu 2:
update HocVien
set DiemTB =
(
	select AVG(Diem) from KetQuaThi
	where LanThi = 
	(
		select max(LanThi) from KetQuaThi
		where HocVien.MaHV = KetQuaThi.MaHV
		group by MaHV
	)
	group by MaHV
	having KetQuaThi.MaHV = HocVien.MaHV)
--Câu 3:
update HocVien
set GhiChu = 'Cam Thi'
where exists (select * from KetQuaThi
where MaHV = HocVien.MaHV and LanThi = 3 and Diem < 5)
--Câu 4:
update HocVien set XepLoai = 'XS' where DiemTB >= 9
update HocVien set XepLoai = 'G' where DiemTB >= 8 and DiemTB < 9
update HocVien set XepLoai = 'K' where DiemTB >= 6.5 and DiemTB < 8
update HocVien set XepLoai = 'TB' where DiemTB >= 5 and DiemTB < 6.5
update HocVien set XepLoai = 'Y' where DiemTB < 5


--Phần III:
--Câu 6:
select TenMH from MonHoc, GiangDay, GiaoVien
where MonHoc.MaMH = GiangDay.MaMH
and GiangDay.MaGV = GiaoVien.MaGV
and HoTen = 'Tran Tam Thanh'
and HocKy = 1 and Nam = 2006
--Câu 7:
select MonHoc.MaMH, TenMH from MonHoc, GiangDay, GiaoVien
where MonHoc.MaMH = GiangDay.MaMH
and GiangDay.MaGV = GiaoVien.MaGV
and GiaoVien.MaGV in
(
	select MaGVCN from Lop
	where MaLop = 'K11'
)
and HocKy = 1 and Nam = 2006
--Câu 8:
select distinct (Ho + ' ' + Ten) as HoTen from HocVien, GiangDay, GiaoVien, MonHoc, Lop
where Lop.MaGVCN = GiaoVien.MaGV
and Lop.TrgLop = HocVien.MaHV
and GiangDay.MaMH = MonHoc.MaMH
and HocVien.MaLop = Lop.MaLop
and HoTen = 'Nguyen To Lan'
and TenMH = 'Co So Du Lieu'
--Câu 9:
select MonHoc.MaMH, TenMH
from MonHoc join DieuKien
on MonHoc.MaMH = MaMH_Truoc and DieuKien.MaMH = 'CSDL'
--Câu 10:
select MonHoc.MaMH, TenMH
from MonHoc join DieuKien
on MonHoc.MaMH = DieuKien.MaMh and MaMH_Truoc = 'CTRR'
--Câu 11:
select distinct HoTen from GiaoVien join GiangDay
on GiaoVien.MaGV = GiangDay.MaGV
where MaLop in ('K11', 'K12')
and MaMH = 'CTRR'
and HocKy = 1 and Nam = 2006
--Câu 12:
select HocVien.MaHV, (Ho+' '+Ten) as HoTen from HocVien join KetQuaThi
on HocVien.MaHV = KetQuaThi.MaHV
where KQua = 'Khong Dat' and LanThi = 1 and MaMH = 'CSDL'
and HocVien.MaHV not in
(
	select MaHV from KetQuaThi
	where KQua = 'Dat' and LanThi >= 2
)
--Câu 13:
select MaGV, HoTen from GiaoVien
where MaGV not in
(
	select MaGV from GiangDay
)
--Câu 14:
select MaGV, HoTen from GiaoVien
where MaGV not in
(
	select distinct GiangDay.MaGV from 
	(GiangDay join MonHoc on GiangDay.MaMH = MonHoc.MaMH)
	join GiaoVien on GiangDay.MaGV = GiaoVien.MaGV
	where GiaoVien.MaKhoa = MonHoc.MaKhoa
)
--Câu 15:
select HocVien.MaHV, (Ho+' '+Ten) as HoTen from HocVien join KetQuaThi on HocVien.MaHV = KetQuaThi.MaHV
where MaLop = 'K11'
and ((LanThi >= 3 and KQua = 'Khong Dat')
or (LanThi = 2 and MaMH = 'CTRR' and Diem = 5))
--Câu 16:
select HoTen from GiaoVien join GiangDay
on GiaoVien.MaGV = GiangDay.MaGV
where MaMH = 'CTRR'
group by Nam, HocKy, HoTen
having count(*) >= 2
--Câu 17:
select HocVien.MaHV, (Ho+' '+Ten) as HoTen, Diem from HocVien join KetQuaThi
on HocVien.MaHV = KetQuaThi.MaHV
where MaMH = 'CSDL'
and LanThi = 
(
	select max(LanThi) from KetQuaThi
	where HocVien.MaHV = KetQuaThi.MaHV
	and MaMH = 'CSDL'
	group by MaHV
)
order by MaHV
--Câu 18:Lỗi
select distinct HocVien.MaHV, (Ho+' '+Ten) as HoTen, Diem from HocVien, KetQuaThi, MonHoc
where HocVien.MaHV = KetQuaThi.MaHV
and KetQuaThi.MaMH = MonHoc.MaMH
and TenMH = 'Co So Du Lieu'
and Diem = 
(
	select max(Diem) from KetQuaThi, MonHoc
	where KetQuaThi.MaMH = MonHoc.MaMH
	and TenMH = 'Co So Du Lieu'
	and MaHV = HocVien.MaHV
	group by MaHV
)
--Buổi 4
--Câu 19:
select top 1 MaKhoa, TenKhoa from Khoa
order by NgTlap asc
--Câu 20:
select count(*) as SoLuong from GiaoVien
where HocHam = 'GS' or HocHam = 'PGS'
--Câu 21:
select HocVi, count(*) as SoLuong from GiaoVien
group by HocVi
--Câu 22:
select TenMH, count(*) as SLHV from MonHoc, KetQuaThi
where MonHoc.MaMH = KetQuaThi.MaMH
group by TenMH
--Câu 23:
select distinct GiaoVien.MaGV, HoTen from GiaoVien, GiangDay, Lop
where GiaoVien.MaGV = Lop.MaGVCN
and GiaoVien.MaGV = GiangDay.MaGV
and GiangDay.MaLop = Lop.MaLop
--Câu 24:
select Ho + ' ' + Ten as HoTen from HocVien, Lop
where MaHV = TrgLop
and SiSo in
(
	select top 1 SiSo from Lop
	order by SiSo desc
)
--Câu 26:
select top 1 with ties HocVien.MaHV, Ho + ' ' + Ten as HoTen from HocVien, KetQuaThi
where HocVien.MaHV = KetQuaThi.MaHV
and Diem >= 9 and Diem <= 10
group by HocVien.MaHV, Ho + ' ' + Ten
order by count(Diem) desc
--Câu 27:???
select Lop.MaLop, HocVien.MaHV, Ho + ' ' + Ten as HoTen from Lop, HocVien
where HocVien.MaLop = Lop.MaLop
group by Lop.MaLop, HocVien.MaHV, Ho + ' ' + Ten


SELECT HV1.MAHV, HO, TEN, MALOP
FROM HOCVIEN HV1 JOIN KETQUATHI KQT1 ON HV1.MAHV = KQT1.MAHV
WHERE DIEM = 9 OR DIEM = 10
GROUP BY MALOP, HV1.MAHV, HO, TEN
HAVING COUNT(MAMH) >= ALL(	SELECT COUNT(MAMH)
							FROM HOCVIEN HV2 JOIN KETQUATHI KQT2 ON HV2.MAHV = KQT2.MAHV
							WHERE (DIEM = 9 OR DIEM = 10)
							AND HV1.MALOP = HV2.MALOP
							GROUP BY HV2.MAHV, MALOP)

--Câu 28:
select HocKy, GiaoVien.MaGV, HoTen, count(MaMH) as SLMH, count(MaLop) as SLLop from GiaoVien, GiangDay
where GiaoVien.MaGV = GiangDay.MaGV
group by HocKy, GiaoVien.MaGV, HoTen
order by HocKy asc
--Câu 29:???
select HocKy, GiaoVien.MaGV, HoTen from GiaoVien, GiangDay
where GiaoVien.MaGV = GiangDay.MaGV
group by HocKy, GiaoVien.MaGV, HoTen
having count(*) >= all (select count(MaMH) from GiaoVien, GiangDay 
						where GiaoVien.MaGV = GiangDay.MaGV
						group by GiangDay.MaGV)