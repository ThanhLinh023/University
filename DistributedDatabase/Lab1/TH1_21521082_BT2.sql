/*
- Tầm quan trọng của việc phân quyền người dùng : đóng vai trò cực kỳ quan trọng trong việc bảo mật dữ liệu tránh bị truy cập , thay đổi và xem dữ liệu cụ thể. Giảm thiểu
nguy cơ rủi ro về lỗi hoặc bị tấn công từ bên ngoài. Đảm bảo tính nhất quán và kiểm soát . Quản lý hiệu suất hệ thống. Dễ dàng theo dõi và ghi lại hoạt động.
- Các role thường gặp trong Oracle:
    + CONNECT: role cho phép người dùng kết nối vào cơ sở dữ liệu, thực hiện các truy vấn và thao tác trên các đối tượng mà người dùng tạo. 
CONNECT role không cung cấp quyền truy cập vào bất kỳ đối tượng nào khác.
    + RESOURCE: role  bao gồm các quyền cần thiết để tạo, sửa đổi và xóa các đối tượng cơ sở dữ liệu cơ bản như bảng, chỉ mục, tham chiếu khóa ngoại,
quyền và các đối tượng khác.
    + DBA: role cung cấp quyền truy cập vào hầu hết các đối tượng trong cơ sở dữ liệu và nó còn cho phép người dùng thực hiện nhiều thao tác quản trị hơn, 
bao gồm cả tạo và xóa cơ sở dữ liệu.
    + SELECT_CATALOG_ROLE: role này cung cấp quyền truy cập vào các view và bảng hệ thống, giúp người dùng truy vấn thông tin về các đối tượng trong cơ sở dữ liệu.
    + CREATE SESSION: Cho phép người dùng kết nối vào cơ sở dữ liệu. Đây là quyền tối thiểu cần thiết để người dùng có thể kết nối.
    + CREATE TABLESPACE: Cho phép người dùng tạo mới các không gian lưu trữ (tablespace) trong cơ sở dữ liệu.
    + ALTER SESSION: Cho phép người dùng thay đổi các thuộc tính phiên làm việc của họ sau khi đã kết nối vào cơ sở dữ liệu, chẳng hạn như ngôn ngữ, múi giờ, v.v.
    + CREATE USER: Cho phép người dùng tạo mới các tài khoản người dùng trong cơ sở dữ liệu.
    + DROP USER: Cho phép người dùng xóa các tài khoản người dùng trong cơ sở dữ liệu.
    + ALTER USER: Cho phép người dùng thay đổi cấu hình và thuộc tính của tài khoản người dùng.
- Không nên phân quyền DBA cho các người dùng thông thường. Vì một số lý do sau:
    + Quyền truy cập không kiểm soát
    + Rủi ro về bảo mật
    + Nguy cơ lỗi và vấn đề hiệu suất
    + Không tuân thủ các quy định và chuẩn mực
- Các cú pháp:
    + Tạo role: create role <tên role>;
    + Xóa role: drop role <tên role>;
    + Cấp role: grant <tên role> role to <tên user>;
*/
// Tạo user is01 và is02
        create user is01 identified by is01; - create user is02 identified by is02;
// Tạo role cho phép các thao tác cơ bản sau đó gán cho các user
        create role manager;  grant CREATE SESSION, CREATE TABLE to manager;
        grant manager to is01;
        grant manager to is02;
// Kết nối vào is01, tạo bảng và thêm dữ liệu
        connect is01/is01@localhost:1521/sys;
        create table info (name varchar(50), sex varchar(5));
        create table work (wname varchar(50), datebegin datetime);
        create table hometown (htname varchar(50), postalcode char(20));
        insert into info(name, sex) values ('Micheal', 'Nam');
        insert into work(wname, datebegin) values ('Developer', '2022/09/08');
        insert into hometown(htname, postalcode) values ('HCM City', '590001');
//Kết nối vào is02, tạo bảng và thêm dữ liệu 
        connect is02/is02@localhost:1521/sys;
        create table info (name varchar(50), sex varchar(5));
        create table order1 (orderid number, orderdate datetime);
        create table bill (billid number, money number);
        insert into info(name, sex) values ('Micheal', 'Nam');
        insert into order1(orderid, orderdate) values (1, '2022/09/08');
        insert into bill(billid, money) values (2, '150000');
//Cấp quyền thêm, xóa, sửa dữ liệu trên bảng work của is01 cho is02
        grant insert, update, delete on is01.work to is02;
        insert into is01.work(wname, datebegin) values ('Tester', '2023/01/01');
        update is01.work set wname='Backend' where datebegin='2023/01/01';
        delete from is01.work where wname='Developer';
