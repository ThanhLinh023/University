--Câu 1:
create database ThucHanh
go
use ThucHanh
go
create table KhachHang
(
	MaKH char(4) not null,
	TenKH char(30),
	QuocTich char(30),
	Tuoi int
	constraint PK_KH primary key(MaKH)
)
create table Phong
(
	SoPhong char(4) not null,
	LoaiPhong char(10) not null,
	GiaPhong money,
	TinhTrang char(50)
	constraint PK_P primary key(SoPhong, LoaiPhong)
)
create table HoaDon
(
	SoHD char(4) not null,
	NgHD smalldatetime,
	MaKH char(4)
	constraint PK_HD primary key(SoHD)
	constraint FK_HDKH foreign key (MaKH) references KhachHang(MaKH)
)
create table CTTP
(
	SoHD char(4) not null,
	SoPhong char(4) not null,
	NgayDen smalldatetime,
	NgayDi smalldatetime
	constraint PK_CTTP primary key(SoHD, SoPhong)
	constraint FK_CTTP_HD foreign key (SoHD) references HoaDon(SoHD)
)
alter table CTTP add constraint FK_CTTP_PH foreign key (SoPhong) references Phong(SoPhong)
--Câu 2:
insert into KhachHang values ('KH01', 'Nguyen Phu Kiet', 'Viet Nam', 19)
insert into KhachHang values('KH02', 'Hao Hien', 'Trung Quoc', 30)
insert into KhachHang values ('KH03', 'David John', 'My', 22)

insert into Phong values ('PH01', 'Vip', 550000, 'Available')
insert into Phong values ('PH02', 'Thuong', 300000, 'Booked')
insert into Phong values ('PH03', 'Tot', 400000, 'Booked')

insert into HoaDon values ('0001', '20220214', 'KH01')
insert into HoaDon values ('0002', '20220219', 'KH03')
insert into HoaDon values ('0003', '20220310', 'KH02')

insert into CTTP values ('0001', 'PH02', '20220128', '20220214')
insert into CTTP values ('0001', 'PH03', '20220210', '20220214')
insert into CTTP values ('0002', 'PH02', '20220215', '20220219')
insert into CTTP values ('0003', 'PH03', '20220307', '20220310')
--Câu 3:
alter table KhachHang add constraint CK_Tuoi check (Tuoi >= 18)
--Câu 4:
create trigger Trg_NgHD_NgayDen
on HoaDon
for insert
as
begin
	declare @NgayDen smalldatetime
	declare @NgHD smalldatetime
	select @NgayDen = NgayDen, @NgHD = NgHD from inserted, CTTP
	where inserted.SoHD = CTTP.SoHD
	if @NgayDen > @NgHD
	begin
		print N'Ngày đến thuê phòng phải nhỏ hơn hoặc bằng ngày lập hóa đơn'
	end
	else
		print N'Thêm thành công'
end
--Câu 5:
select KhachHang.MaKH, TenKH  from KhachHang, HoaDon
where KhachHang.MaKH = HoaDon.MaKH
and NgHD = '20220214'
--Câu 6:
select Phong.SoPhong, LoaiPhong from Phong, CTTP
where Phong.SoPhong = CTTP.SoPhong
and year(NgayDen) = 2022
group by Phong.SoPhong, LoaiPhong
having count(*) > any(select count(SoPhong) from Phong group by SoPhong)
--Câu 7:
select HoaDon.MaKH, count(*) as Tong_so_phong from HoaDon, CTTP
where HoaDon.SoHD = CTTP.SoHD
and year(NgHD) = 2022
group by HoaDon.MaKH
order by Tong_so_phong desc
--Câu 8:
select SoHD, NgHD from HoaDon
where not exists (select * from Phong
					where not exists (select * from CTTP
										where HoaDon.SoHD = CTTP.SoHD
										and Phong.SoPhong = CTTP.SoPhong)
										and LoaiPhong = 'Tot')