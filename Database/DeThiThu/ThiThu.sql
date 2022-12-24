create database Test
go
use Test
create table XepLoai
(
	MaXepLoai char(4) not null,
	TenXepLoai varchar(20)
	constraint PK_XL primary key (MaXepLoai)
)
create table HocVien
(
	MaHV char(4) not null,
	HoTen varchar(30),
	NgSinh smalldatetime,
	DiaChi varchar(30),
	Email varchar(30),
	SDT varchar(15),
	MaXepLoai char(4)
	constraint PK_HV primary key(MaHV)
	constraint FK_HVXL foreign key (MaXepLoai) references XepLoai(MaXepLoai)
)
create table GiaoVien
(
	MaGV char(4) not null,
	HoTen varchar(30),
	NgSinh smalldatetime,
	NgVL smalldatetime
	constraint PK_GV primary key(MaGV)
)
create table Xe
(
	MaXe char(4) not null,
	BienSo varchar(10),
	TenLoaiXe varchar(20)
	constraint PK_Xe primary key(MaXe)
)
create table BaiHoc
(
	MaBaiHoc char(4) not null,
	NgayHoc smalldatetime,
	SoGio int,
	Gia money,
	MaHV char(4),
	MaGV char(4),
	MaXe char(4)
	constraint PK_BH primary key(MaBaiHoc),
	constraint FK_BHHV foreign key(MaHV) references HocVien(MaHV),
	constraint FK_BHGV foreign key(MaGV) references GiaoVien(MaGV),
	constraint FK_BHXe foreign key(MaXe) references Xe(MaXe)
)
--1.2
insert into HocVien 
values ('HV01', 'Thanh Linh', '20031204', 'BMT', '123@gmail.com', '123456', 'G')
insert into GiaoVien
values ('GV01', 'NguyenVanA', '19970704', '20150908')
insert into Xe
values ('Mer', '123.345', 'Mercedes')
insert into BaiHoc
values ('BH01', '20200904', 36, 5000000, 'HV01', 'GV01', 'Mer')
--1.3
update HocVien
set DiaChi = 'Dak Lak'
where MaHV = 'HV01'
--2.1
alter table XepLoai add constraint CK_TXL check (TenXepLoai in ('gioi', 'kha', 'trung binh', 'kem'))
--2.2
alter table BaiHoc add constraint CK_Gia check (Gia > 0)
--2.3
create trigger Trg_NgSinh_NgHoc
on BaiHoc for insert
as
begin
	declare @NgSinh smalldatetime
	declare @NgHoc smalldatetime
	select @NgHoc = NgayHoc, @NgSinh = NgSinh from inserted, HocVien
	where inserted.MaHV = HocVien.MaHV
	if @NgSinh > @NgHoc
	begin
		print 'Error'
		rollback transaction
	end
	else 
		print 'Successfull'
end
--3.1
select HocVien.MaHV, HoTen from HocVien, XepLoai
where HocVien.MaXepLoai = XepLoai.MaXepLoai
and TenXepLoai = 'gioi'
--3.2
select top 1 with ties MaBaiHoc, NgayHoc, SoGio from BaiHoc
order by Gia desc
--3.3
(select HocVien.MaHV, HoTen from HocVien, BaiHoc
where HocVien.MaXepLoai = BaiHoc.MaHV
and NgayHoc = '20180505')
intersect
(select HocVien.MaHV, HoTen from HocVien, BaiHoc
where HocVien.MaXepLoai = BaiHoc.MaHV
and NgayHoc = '20180506')
--3.4
(select Xe.MaXe, BienSo from Xe,BaiHoc
where Xe.MaXe = BaiHoc.MaXe
and NgayHoc = '20180101')
except
(select Xe.MaXe, BienSo from Xe,BaiHoc
where Xe.MaXe = BaiHoc.MaXe
and NgayHoc = '20180102')
--3.5
select Xe.MaXe, BienSo from Xe, BaiHoc
where Xe.MaXe = BaiHoc.MaXe
and month(NgayHoc) = 8 and year(NgayHoc) = 2018
group by Xe.MaXe, BienSo
having count(*) > 100
--3.6
select MaGV, HoTen from GiaoVien
where not exists (select * from Xe
					where not exists (select * from BaiHoc
										where BaiHoc.MaGV = GiaoVien.MaGV
										and BaiHoc.MaXe = Xe.MaXe
										and TenLoaiXe = 'Ford'
										and year(NgayHoc) = 2017))
--3.7
select HocVien.MaHV, HoTen, sum(SoGio) as TSGH from HocVien, BaiHoc
where HocVien.MaHV = BaiHoc.MaHV
and year(NgayHoc) = 2016
group by HocVien.MaHV, HoTen