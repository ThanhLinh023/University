use QLBH_2020
select *From KHACHHANG
SELECT *FROM HOADON
--- THỰC HÀNH TRIGGER--
--- Câu 11: Ngày mua hàng (NGHD) của một khách hàng thành viên sẽ lớn hơn hoặc bằng ngày khách hàng đó đăng ký thành viên (NGDK)

--- Tạo triger trên bảng KHÁCH HÀNG để kiểm tra khi cập nhật ngày đăng ký---

CREATE TRIGGER TRG_CHECK_NGHD_NGDK -- CẬP NHẬT NGÀY ĐĂNG KÝ CỦA KHÁCH HÀNG
ON KHACHHANG FOR UPDATE
AS
BEGIN
	DECLARE @NGHD SMALLDATETIME
	DECLARE @NGDK SMALLDATETIME
	SELECT @NGDK=NGDK FROM inserted
	IF (@NGDK > ANY (SELECT HOADON.NGHD FROM HOADON, inserted WHERE HOADON.MAKH=inserted.MAKH))
	BEGIN
		PRINT N'NGÀY ĐĂNG KÝ PHẢI NHỎ HƠN NGÀY MUA HÀNG'
		ROLLBACK TRANSACTION
	END
END
go
update KHACHHANG SET NGDK='2006-07-26' WHERE MAKH='KH01' -- DEMO

select *from HOADON
insert into hoadon values(1025,'2006-07-21','KH01','NV01',320000)
select *from KHACHHANG
GO

--- Tạo trigger trên bảng HÓA ĐƠN để kiểm tra khi cập nhật và thêm hóa đơn mới---
create TRIGGER TRG_CHECK_NGHD 
ON HOADON FOR INSERT, UPDATE
AS
BEGIN
	DECLARE @NGDK SMALLDATETIME
	DECLARE @NGHD SMALLDATETIME
	SELECT @NGDK=NGDK, @NGHD= NGHD FROM inserted,KHACHHANG
	WHERE KHACHHANG.MAKH=inserted.MAKH
	IF (@NGDK>@NGHD)
	BEGIN
		PRINT N'Ngày lập hóa đơn phải lớn hơn ngày đăng ký của khách hàng'
		ROLLBACK TRANSACTION
	END
	ELSE
		PRINT N'CẬP NHẬT/THÊM THÀNH CÔNG'
END

insert into hoadon values(1024,'2006-07-21','KH01','NV01',320000) -- demo
insert into hoadon values(1024,'2006-07-30','KH01','NV01',320000) -- demo

SELECT *
FROM KHACHHANG
WHERE MAKH = 'KH01'


--- CÂU 12: Ngày bán hàng (NGHD) của một nhân viên phải lớn hơn hoặc bằng ngày nhân viên đó vào làm
CREATE TRIGGER Trg_KiemtraNGVL_NV -- Kiểm tra ngày vào làm tại bảng NHANVIEN
ON NHANVIEN FOR UPDATE
AS
BEGIN
	DECLARE @NGVL SMALLDATETIME
	DECLARE @NGHD SMALLDATETIME
	SELECT @NGVL=NGVL FROM inserted
	IF (@NGVL>ANY (SELECT HOADON.NGHD FROM HOADON, inserted WHERE HOADON.MANV=inserted.MANV))
	BEGIN
		PRINT N'NGÀY VÀO LÀM CỦA NHÂN VIÊN PHẢI NHỎ HƠN NGÀY LẬP HÓA ĐƠN'
	END
	ELSE PRINT N' CẬP NHẬT THÀNH CÔNG'
END
GO
CREATE TRIGGER TRG_KiemTraNHD_HD 
ON HOADON FOR INSERT, UPDATE
AS
BEGIN
	DECLARE @NGVL SMALLDATETIME
	DECLARE @NGHD SMALLDATETIME
	SELECT @NGVL=NGVL, @NGHD=NGHD FROM inserted, NHANVIEN WHERE inserted.MANV=NHANVIEN.MANV
	IF (@NGVL>@NGHD)
	BEGIN
		PRINT N' Ngày vào làm phải nhỏ hơn ngày lập hóa đơn'
	END
	ELSE PRINT N' UPDATE/THÊM THÀNH CÔNG'
END

insert into hoadon values(1026,'2005-07-21','KH01','NV01',320000)

SELECT *FROM NHANVIEN

--- Câu 13: Mỗi một hóa đơn phải có ít nhất một chi tiết hóa đơn
CREATE TRIGGER TRG_KIEMTRA_SL_CTHD -- Tạo trigger kiểm tra số lượng CTHD
ON CTHD FOR DELETE, UPDATE
AS
BEGIN
	DECLARE @SL INT
	SELECT @SL=COUNT(CTHD.SOHD) FROM CTHD,deleted 
	WHERE CTHD.SOHD=deleted.SOHD
	IF @SL<1
	BEGIN
		PRINT N' Mỗi hóa đơn phải có ít nhất một chi tiết hóa đơn'
		ROLLBACK TRANSACTION
	END
		ELSE PRINT N'XÓA THÀNH CÔNG'
END
GO

SELECT *FROM CTHD
SELECT *FROM HOADON
DELETE FROM CTHD WHERE SOHD='1021' AND MASP='TV02'
DELETE FROM CTHD WHERE SOHD='1021' AND MASP='ST08'
DELETE FROM CTHD WHERE SOHD='1021' AND MASP='TV01'-- DEMO

--- Câu 14: Trị giá của một hóa đơn là tổng thành tiền (số lượng*đơn giá) của các chi tiết thuộc hóa đơn đó
-- Trigger Gán Trị giá = 0 khi Thêm 1 Hóa đơn mới--
CREATE TRIGGER TRG_INSERT_HD
ON HOADON
FOR INSERT 
AS
BEGIN
		update HOADON set TRIGIA=0 
		where SOHD = (select SOHD from inserted)
		Print N'Đã tạo Trị giá mặc định bằng 0 khi thêm hóa đơn mới'
END
select *from HOADON

insert into hoadon values(1030,'2006-07-30','KH01','NV01',320000) --demo
insert into hoadon values(1031,'2006-07-30','KH01','NV01','')
insert into hoadon values(1033,'2006-07-30','KH01','NV01',320000)--- demo


--- Trigger khi thêm Hóa đơn mới thì ---
CREATE TRIGGER TRG_UPDATE_HD
ON HOADON
FOR INSERT
AS
BEGIN
	UPDATE HOADON
	SET TRIGIA=(SELECT TRIGIA FROM deleted)
	WHERE SOHD=(SELECT SOHD FROM inserted)
	PRINT N'Đã cập nhật 1 hóa đơn với trị giá không thay đổi'
END
--- Trigger tính thành tiền bằng Số lượng * Đơn giá
CREATE TRIGGER TRG_THANHTIEN
ON CTHD
FOR INSERT
AS
BEGIN
	DECLARE @SL INT, 
	@GIA MONEY
	--@SOHD INT
	SELECT @GIA=GIA,@SL=SL FROM inserted, SANPHAM
	WHERE inserted.MASP=SANPHAM.MASP
	UPDATE HOADON
	SET TRIGIA=TRIGIA+@SL*@GIA
	PRINT N'Đã thêm 1 chi tiết hóa đơn và cập nhật lại trị giá của hóa đơn'
END

select *From CTHD
select *From HOADON
select *from SANPHAM where MASP='TV01' --demo
insert into hoadon values(1032,'2006-07-30','KH02','NV01','') -- demo
insert into CTHD values (1032,'TV01',7) --demo
insert into CTHD values (1033,'BB01',7) --demo