//1. Tạo user tên BAITHI gồm có 4 table USER, CHANNEL, VIDEO, SHARE. Tạo khóa chính, khóa ngoại cho các table đó.
create user c##baithi identified by baithi;
create table user1
(
    uid1 number not null, 
    username varchar(50), 
    pass char(50), 
    regday date, 
    nationality varchar(50), 
    constraint pk_uid primary key(uid1)
);
create table channel
(
    channelid char(20) not null, 
    cname varchar(50), 
    subscribers number, 
    owner number, 
    created date, 
    constraint pk_channelid primary key(channelid)
);
create table video
(
    videoid char(20) not null, 
    title varchar(100), 
    duration number,
    age number, 
    constraint pk_videoid primary key(videoid)
);
create table share1
(
    videoid char(20) not null, 
    channelid char(20) not null,
    constraint pk_vd_cnid primary key(videoid, channelid)
);
alter table channel add constraint fk_channel_owner foreign key(owner) references user1(uid1);
alter table share1 add constraint fk_video_share foreign key(videoid) references video(videoid);
alter table share1 add constraint fk_channel_share foreign key(channelid) references channel(channelid);
//2. Nhập dữ liệu
insert into user1(uid1, username, pass, regday, nationality) values (001, 'faptv', '123456abc', '01/01/2014', 'Viet Nam');
insert into user1(uid1, username, pass, regday, nationality) values (002, 'kemxoitv', '@147869iii', '05/06/2015', 'Campuchia');
insert into user1(uid1, username, pass, regday, nationality) values (003, 'openshare', 'qwertyuiop', '12/05/2009', 'Viet Nam');

insert into  channel(channelid, cname, subscribers, owner, created) values ('C120', 'FAP TV', 2343, 001, '02/01/2014');
insert into  channel(channelid, cname, subscribers, owner, created) values ('C905', 'Kem Xoi TV', 1032, 002, '09/07/2015');
insert into  channel(channelid, cname, subscribers, owner, created) values ('C357', 'OpenShare Cafe', 5064, 003, '10/12/2010');

insert into video(videoid, title, duration, age) values ('V100229', 'FAPtv Com Nguoi Tap 41 - Dot Nhap', 469, 18);
insert into video(videoid, title, duration, age) values ('V211002', 'Kem xoi: Tap 31 - May Kool Tinh Yeu Cua Anh', 312, 16);
insert into video(videoid, title, duration, age) values ('V400002', 'Noi Tinh Yeu Ket Thuc',378, 0);

insert into share1(videoid, channelid) values ('V100229', 'C905');
insert into share1(videoid, channelid) values ('V211002', 'C120');
insert into share1(videoid, channelid) values ('V400002', 'C357');
//3.Ràng buộc toàn vẹn sau: Ngày đăng ký đượcmặc định là ngày hiện tại.
create or replace trigger set_default_regday
before insert on user1
for each row
begin
    if :new.regday is null then
        :new.regday := SYSDATE;
    end if;
end;
/
//4. Ràng buộc toàn vẹn sau: Ngày tạo kênh luôn lớn hơn hoặc bằng ngày đăng ký của người dùng sở hữu kênh đó.
create or replace trigger check_created_greater_than_regday
before insert on channel
for each row
declare
    user_regday date;
begin
    select regday into user_regday from user1 where uid1 = :new.owner;
    if :new.created < user_regday then
        RAISE_APPLICATION_ERROR(-20001, 'Created day must be greater or equal to regday');
    end if;
end;
/
//5. Tìm tất cả các video có giới hạn độ tuổi từ 16 trở lên.
select * from video where age >= 16;
//6.Tìm kênh có số người theo dõi nhiều nhất.
select *  from channel
where rownum = 1
order by subscribers desc;
//7.Với mỗi video có giới hạn độ tuổi là 18, thống kê số kênh đã chia sẻ.
select count(*) as soluongkenh from video, share1
where video.videoid = share1.videoid and age = 18;
//8. Tìm video được tất cả các kênh chia sẻ.
select * from video v
where not exists 
(
    select *  from channel c
    where not exists (
            select * from share1
            where share1.videoid = v.videoid
            and share1.channelid = c.channelid
    )
);