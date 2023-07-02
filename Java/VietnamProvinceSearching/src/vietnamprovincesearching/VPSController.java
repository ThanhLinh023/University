package vietnamprovincesearching;

public class VPSController {
    public String showInformation(String city, String district)
    {
        String infor = "";
        switch (city)
        {
            case "Hà Nội":
            {
                switch (district)
                {
                    case "Quận Ba Đình":
                    {
                        infor = "14 phường: Cống Vị, Điện Biên, Đội Cấn, Giảng Võ, Kim Mã, Liễu Giai, Ngọc Hà, Ngọc Khánh, Nguyễn Trung Trực, Phúc Xá, Quán Thánh,"
                                + " Thành Công, Trúc Bạch và Vĩnh Phúc";
                        break;
                    }
                    case "Quận Hoàn Kiếm":
                    {
                        infor = "18 phường: Chương Dương Độ, Cửa Đông, Cửa Nam, Đồng Xuân, Hàng Bạc, Hàng Bài, Hàng Bồ, Hàng Bông, Hàng Buồm, Hàng Đào, Hàng Gai, Hàng Mã, Hàng Trống,"
                                + " Lý Thái Tổ, Phan Chu Trinh, Phúc Tân, Trần Hưng Đạo, Tràng Tiền.";
                        break;
                    }
                    case "Quận Tây Hồ":
                    {
                        infor = "8 phường: Bưởi, Thụy Khuê, Yên Phụ, Tứ Liên, Nhật Tân, Quảng An, Xuân La và Phú Thượng";
                        break;
                    }
                    case "Quận Long Biên":
                    {
                        infor = "14 phường: Bồ Đề, Gia Thụy, Cự Khối, Đức Giang, Giang Biên, Long Biên, Ngọc Lâm, Ngọc Thụy, Phúc Đồng, Phúc Lợi,"
                                + " Sài Đồng, Thạch Bàn, Thượng Thanh và Việt Hưng";
                        break;
                    }
                    case "Quận Cầu Giấy":
                    {
                        infor = "8 phường: Nghĩa Đô, Quan Hoa, Dịch Vọng, Dịch Vọng Hậu,"
                                + " Trung Hòa, Nghĩa Tân, Mai Dịch, Yên Hòa";
                        break;
                    }
                    case "Quận Đống Đa":
                    {
                        infor = "21 phường: Văn Miếu, Quốc Tử Giám, Hàng Bột, Nam Đồng, Trung Liệt, Khâm Thiên, Phương Liên, Phương Mai, Khương Thượng, Ngã Tư Sở, Láng Thượng, Cát Linh, Văn Chương, Ô Chợ Dừa, Quang Trung,"
                                + " Thổ Quan, Trung Phụng, Kim Liên, Trung Tự, Thịnh Quang, Láng Hạ";
                        break;
                    }
                    case "Quận Hai Bà Trưng":
                    {
                        infor = "20 phường: Nguyễn Du, Bùi Thị Xuân, Ngô Thì Nhậm, Đồng Nhân, Bạch Đằng, Thanh Nhàn, Bách Khoa, Vĩnh Tuy, Trương Định,"
                                + " Lê Đại Hành, Phố Huế, Phạm Đình Hổ, Đống Mác, Thanh Lương, Cầu Dền, Bạch Mai, Quỳnh Mai, Minh Khai, Đồng Tâm, Quỳnh Lôi";
                        break;
                    }
                    case "Quận Hoàng Mai":
                    {
                        infor = "14 phường: Định Công, Đại Kim, Giáp Bát, Hoàng Liệt, Hoàng Văn Thụ, Lĩnh Nam, Mai Động, Tân Mai, Thanh Trì, Thịnh Liệt,"
                                + " Trần Phú, Tương Mai, Vĩnh Hưng, Yên Sở";
                        break;
                    }
                    case "Quận Thanh Xuân":
                    {
                        infor = "11 phường: Hạ Đình, Kim Giang, Khương Đình, Khương Mai, Khương Trung, Nhân Chính, Phương Liệt, Thanh Xuân Bắc, Thanh Xuân Nam, Thanh Xuân Trung, Thượng Đình";
                        break;
                    }
                    case "Quận Hà Đông":
                    {
                        infor = "	17 phường: Quang Trung, Nguyễn Trãi, Hà Cầu, Vạn Phúc, Phúc La, Yết Kiêu, Mộ Lao, Văn Quán, La Khê, Phú La, Kiến Hưng, Yên Nghĩa, Phú Lương, Phú Lãm,"
                                + " Dương Nội, Biên Giang, Đồng Mai";
                        break;
                    }
                    case "Quận Bắc Từ Liêm":
                    {
                        infor = "13 phường: Cổ Nhuế 1, Cổ Nhuế 2, Đông Ngạc, Đức Thắng, Liên Mạc, Minh Khai, Phú Diễn, Phúc Diễn, Tây Tựu, Thượng Cát,"
                                + " Thụy Phương, Xuân Đỉnh, Xuân Tảo";
                        break;
                    }
                    case "Quận Nam Từ Liêm":
                    {
                        infor = "10 phường: Cầu Diễn, Đại Mỗ, Mễ Trì, Mỹ Đình 1, Mỹ Đình 2, Phú Đô, Phương Canh, Tây Mỗ, Trung Văn, Xuân Phương";
                        break;
                    }
                    case "Thị Xã Sơn Tây":
                    {
                        infor = "9 phường: Lê Lợi, Quang Trung, Phú Thịnh, Ngô Quyền, Sơn Lộc, Xuân Khanh, Trung Hưng, Viên Sơn, Trung Sơn Trầm." +
                            "6 xã: Đường Lâm, Thanh Mỹ, Xuân Sơn, Kim Sơn, Sơn Đông, Cổ Đông.";
                        break;
                    }
                    case "Huyện Ba Vì":
                    {
                        infor = "1 Thị trấn: Tây Đằng. 30 xã: Ba Trại, Ba Vì, Cẩm Lĩnh, Cam Thượng, Châu Sơn, Chu Minh, Cổ Đô, Đông Quang, Đồng Thái, Khánh Thượng,"
                                + " Minh Châu, Minh Quang, Phong Vân, Phú Châu, Phú Cường, Phú Đông, Phú Phương, Phú Sơn, Sơn Đà, Tản Hồng, Tản Lĩnh, Thái Hòa,"
                                + " Thuần Mỹ, Thụy An, Tiên Phong, Tòng Bạt, Vân Hòa, Vạn Thắng, Vật Lại, Yên Bái";
                        break;
                    }
                    case "Huyện Chương Mỹ":
                    {
                        infor = "2 thị trấn: Chúc Sơn, Xuân Mai. 31 xã: Đại Yên, Đông Phương Yên, Đông Sơn, Đồng Lạc, Đồng Phú, Hòa Chính, Hoàng Diệu, Hoàng Văn Thụ,"
                                + " Hồng Phong, Hợp Đồng, Hữu Văn, Lam Điền, Mỹ Lương, Nam Phương Tiến, Ngọc Hòa, Ngọc Sơn, Phú Nam An, Phú Nghĩa, Phụng Châu, Quảng Bị,"
                                + " Tân Tiến, Thanh Bình, Thụy Hương, Thủy Xuân Tiên, Thượng Vực, Tiên Phương, Tốt Động, Trần Phú, Trung Hòa, Trường Yên, Văn Võ";
                        break;
                    }
                    case "Huyện Đan Phượng":
                    {
                        infor = "1 thị trấn: Thị trấn Phùng. 15 xã: Xã Đan Phượng, Xã Đồng Tháp, Xã Hạ Mỗ, Xã Hồng Hà, Xã Liên Hà, Xã Liên Hồng, Xã Liên Trung, Xã Phương Đình,"
                                + " Xã Song Phượng, Xã Tân Hội, Xã Tân Lập, Xã Thọ An, Xã Thọ Xuân, Xã Thượng Mỗ, Xã Trung Châu.";
                        break;
                    }
                    case "Huyện Đông Anh":
                    {
                        infor = "1 Thị trấn: Đông Anh. 23 xã: Bắc Hồng, Cổ Loa, Dục Tú, Đại Mạch, Đông Hội, Hải Bối, Kim Chung, Kim Nỗ, Liên Hà, Mai Lâm, Nam Hồng, Nguyên Khê, Tầm Xá,"
                                + " Thụy Lâm, Tiên Dương, Uy Nỗ, Vân Hà, Vân Nội, Việt Hùng, Võng La, Xuân Canh, Xuân Nộn, Vĩnh Ngọc";
                        break;
                    }
                    case "Huyện Gia Lâm":
                    {
                        infor = "2 Thị trấn: Trâu Quỳ & Yên Viên. 20 xã: Bát Tràng, Cổ Bi, Đa Tốn, Đặng Xá, Đình Xuyên, Đông Dư, Dương Hà, Dương Quang, Dương Xá, Kiêu Kỵ, Kim Lan, Kim Sơn,"
                                + " Lệ Chi, Ninh Hiệp, Phù Đổng, Phú Thị, Trung Mầu, Văn Đức, Yên Thường, Yên Viên";
                        break;
                    }
                    case "Huyện Hoài Đức":
                    {
                        infor = "1 thị trấn: Thị trấn Trạm Trôi. 19 xã: Xã An Khánh, Xã An Thượng, Xã Cát Quế, Xã Di Trạch, Xã Dương Liễu, Xã Đắc Sở, Xã Đông La, Xã Đức Giang, Xã Đức Thượng, "
                                + "Xã Kim Chung, Xã La Phù, Xã Lại Yên, Xã Minh Khai, Xã Song Phương, Xã Sơn Đồng, Xã Tiền Yên, Xã Vân Canh, Xã Vân Côn, Xã Yên Sở.";
                        break;
                    }
                    case "Huyện Mê Linh":
                    {
                        infor = "2 thị trấn: Thị trấn Chi Đông, Thị trấn Quang Minh. 16 xã: Xã Chu Phan, Xã Đại Thịnh, Xã Hoàng Kim, Xã Kim Hoa, Xã Liên Mạc, Xã Mê Linh, Xã Tam Đồng, Xã Tiền Phong,"
                                + " Xã Tiến Thắng, Xã Tiến Thịnh, Xã Tự Lập, Xã Thạch Đà, Xã Thanh Lâm, Xã Tráng Việt, Xã Vạn Yên, Xã Văn Khê.";
                        break;
                    }
                    case "Huyện Mỹ Đức":
                    {
                        infor = "1 Thị trấn: Đại Nghĩa. 21 xã: An Mỹ, An Phú, An Tiến, Bột Xuyên, Đại Hưng, Đốc Tín, Đồng Tâm, Hồng Sơn, Hợp Thanh, Hợp Tiến, Hùng Tiến, Hương Sơn, Lê Thanh, Mỹ Thành, "
                                + "Phù Lưu Tế, Phúc Lâm, Phùng Xá, Thượng Lâm, Tuy Lai, Vạn Kim, Xuy Xá";
                        break;
                    }
                    case "Huyện Phú Xuyên":
                    {
                        infor = "2 thị trấn: Thị trấn Phú Xuyên, thị trấn Phú Minh. 26 xã: Hồng Minh, Tri Trung, Hoàng Long, Phú Túc, Văn Hoàng, Quang Trung, Đại Thắng, Phượng Dực, Chuyên Mỹ, Tân Dân, Sơn Hà,"
                                + " Nam Phong, Nam Triều, Thụy Phú, Văn Nhân, Khai Thái, Bạch Hạ, Minh Tân, Quang Lãng, Châu Can, Phú Yên, Phúc Tiến, Hồng Thái, Vân Từ, Đại Xuyên, Tri Thủy";
                        break;
                    }
                    case "Huyện Phúc Thọ":
                    {
                        infor = "1 thị trấn: Thị trấn Phúc Thọ. 22 xã: Xã Cẩm Đình, Xã Hát Môn, Xã Hiệp Thuận, Xã Liên Hiệp, Xã Long Xuyên, Xã Ngọc Tảo, Xã Phúc Hòa, Xã Phụng Thượng, Xã Phương Độ, Xã Sen Chiểu,"
                                + " Xã Tam Hiệp, Xã Tam Thuấn, Xã Tích Giang, Xã Thanh Đa, Xã Thọ Lộc, Xã Thượng Cốc, Xã Trạch Mỹ Lộc, Xã Vân Hà, Xã Vân Nam, Xã Vân Phúc, Xã Võng Xuyên, Xã Xuân Phú.";
                        break;
                    }
                    case "Huyện Quốc Oai":
                    {
                        infor = "1 Thị trấn: Quốc Oai. 20 xã: Phú Mãn, Phú Cát, Hoà Thạch, Tuyết Nghĩa, Đông Yên, Liệp Tuyết, Ngọc Liệp, Ngọc Mỹ, Cấn Hữu, Nghĩa Hương, Thạch Thán, Đồng Quang, Sài Sơn, Yên Sơn, Phượng Cách,"
                                + " Tân Phú, Đại Thành, Tân Hoà, Cộng Hoà, Đông Xuân";
                        break;
                    }
                    case "Huyện Sóc Sơn":
                    {
                        infor = "1 thị trấn: Thị trấn Sóc Sơn. 25 xã: Xã Bắc Phú, Xã Bắc Sơn, Xã Đông Xuân, Xã Đức Hoà, Xã Hiền Ninh, Xã Hồng Kỳ, Xã Kim Lũ, Xã Mai Đình, Xã Minh Phú, Xã Minh Trí, Xã Nam Sơn, Xã Phú Cường, "
                                + "Xã Phù Linh, Xã Phù Lỗ, Xã Phú Minh, Xã Quang Tiến, Xã Tân Dân, Xã Tân Hưng, Xã Tân Minh, Xã Tiên Dược, Xã Thanh Xuân, Xã Trung Giã, Xã Việt Long, Xã Xuân Giang, Xã Xuân Thu.";
                        break;
                    }
                    case "Huyện Thạch Thất":
                    {
                        infor = "1 thị trấn: Thị trấn Liên Quan. 22 xã: Xã Bình Phú, Xã Bình Yên, Xã Canh Nậu, Xã Cẩm Yên, Xã Cần Kiệm, Xã Chàng Sơn, Xã Dị Nậu, Xã Đại Đồng, Xã Đồng Trúc, Xã Hạ Bằng, Xã Hương Ngải, Xã Hữu Bằng,"
                                + " Xã Kim Quan, Xã Lại Thượng, Xã Phú Kim, Xã Phùng Xá, Xã Tân Xã, Xã Tiến Xuân, Xã Thạch Hoà, Xã Thạch Xá, Xã Yên Bình, Xã Yên Trung.";
                        break;
                    }
                    case "Huyện Thanh Oai":
                    {
                        infor = "1 Thị trấn: Kim Bài. 20 xã: Cao Viên, Bích Hòa, Cự Khê, Mỹ Hưng, Tam Hưng, Bình Minh, Thanh Mai, Thanh Cao, Thanh Thùy, Thanh Văn, Đỗ Động, Kim Thư, Kim An, Phương Trung, Dân Hòa, Tân Ước, Liên Châu,'"
                                + " Hồng Dương, Cao Dương, Xuân Dương";
                        break;
                    }
                    case "Huyện Thanh Trì":
                    {
                        infor = "1 Thị trấn: Văn Điển. 15 xã: Thanh Liệt, Đông Mỹ, Yên Mỹ, Duyên Hà, Tam Hiệp, Tứ Hiệp, Ngũ Hiệp, Ngọc Hồi, Vĩnh Quỳnh, Tả Thanh Oai, Đại Áng, Vạn Phúc, Liên Ninh, Hữu Hòa, Tân Triều";
                        break;
                    }
                    case "Huyện Thường Tín":
                    {
                        infor = "1 Thị Trấn: Thị trấn Thường Tín .28 Xã: Liên Phương, Minh Cường, Nghiêm Xuyên, Nguyễn Trãi, Nhị Khê, Ninh Sở, Quất Động, Tân Minh, Thắng Lợi, Thống Nhất, Thư Phú, Tiền Phong, Tô Hiệu, Tự Nhiên, Vạn Điểm, Văn Bình, Văn Phú, Văn Tự,"
                                + " Vân Tảo, Chương Dương, Dũng Tiến, Duyên Thái, Hà Hồi, Hiền Giang, Hòa Bình, Khánh Hà, Hồng Vân, Lê Lợi";
                        break;
                    }
                    case "Huyện Ứng Hòa":
                    {
                        infor = "1 thị trấn: Thị trấn Vân Đình. 28 xã: Xã Cao Thành, Xã Đại Cường, Xã Đại Hùng, Xã Đội Bình, Xã Đông Lỗ, Xã Đồng Tân, Xã Đồng Tiến, Xã Hòa Lâm, Xã Hòa Nam, Xã Hòa Phú, Xã Hoa Sơn, Xã Hòa Xá, Xã Hồng Quang, Xã Kim Đường, Xã Liên Bạt, "
                                + "Xã Lưu Hoàng, Xã Minh Đức, Xã Phù Lưu, Xã Phương Tú, Xã Quảng Phú Cầu, Xã Sơn Công, Xã Tảo Dương Văn, Xã Trầm Lộng, Xã Trung Tú, Xã Trường Thịnh, Xã Vạn Thái, Xã Viên An, Xã Viên Nội.";
                        break;
                    }
                }
                break;
            }
            case "Hải Phòng":
            {
                switch (district)
                {
                    case "Quận Đồ Sơn":
                    {
                        infor = "6 Phường: Phường Ngọc Xuyên, Phường Vạn Hương, Phường Minh Đức, Phường Bàng La, Phường Hợp Đức, Phường Hải Sơn";
                        break;
                    }
                    case "Quận Dương Kinh":
                    {
                        infor = "6 Phường: Phường Đa Phúc, Phường Hưng Đạo, Phường Anh Dũng, Phường Hải Thành, Phường Hoà Nghĩa, Phường Tân Thành";
                        break;
                    }
                    case "Quận Hải An":
                    {
                        infor = "8 Phường: Phường Đông Hải 1, Phường Đông Hải 2, Phường Đằng Lâm, Phường Thành Tô, Phường Đằng Hải, Phường Nam Hải, Phường Cát Bi, Phường Tràng Cát";
                        break;
                    }
                    case "Quận Hồng Bàng":
                    {
                        infor = "9 Phường: Phường Quán Toan, Phường Hùng Vương, Phường Sở Dầu, Phường Thượng Lý, Phường Hạ Lý, Phường Minh Khai, Phường Trại Chuối, Phường Hoàng Văn Thụ, Phường Phan Bội Châu";
                        break;
                    }
                    case "Quận Kiến An":
                    {
                        infor = "10 Phường: Phường Quán Trữ, Phường Lãm Hà, Phường Đồng Hoà, Phường Bắc Sơn, Phường Nam Sơn, Phường Ngọc Sơn, Phường Trần Thành Ngọ, Phường Văn Đẩu, Phường Phù Liễn, Phường Tràng Minh";
                        break;
                    }
                    case "Quận Lê Chân":
                    {
                        infor = "15 Phường: Phường Cát Dài, Phường An Biên, Phường Lam Sơn, Phường An Dương, Phường Trần Nguyên Hãn, Phường Hồ Nam, Phường Trại Cau, Phường Dư Hàng, Phường Hàng Kênh, Phường Đông Hải, Phường Niệm Nghĩa, Phường Nghĩa Xá, Phường Dư Hàng Kênh, Phường Kênh Dương, Phường Vĩnh Niệm";
                        break;
                    }
                    case "Quận Ngô Quyền":
                    {
                        infor = "12 Phường: Phường Máy Chai, Phường Máy Tơ, Phường Vạn Mỹ, Phường Cầu Tre, Phường Lạc Viên, Phường Gia Viên, Phường Đông Khê, Phường Cầu Đất, Phường Lê Lợi, Phường Đằng Giang, Phường Lạch Tray, Phường Đổng Quốc Bình";
                        break;
                    }
                    case "Huyện An Dương":
                    {
                        infor = "16 đơn vị: Thị trấn An Dương, Xã Lê Thiện, Xã Đại Bản, Xã An Hoà, Xã Hồng Phong, Xã Tân Tiến, Xã An Hưng, Xã An Hồng, Xã Bắc Sơn, Xã Nam Sơn, Xã Lê Lợi, Xã Đặng Cương, Xã Đồng Thái, Xã Quốc Tuấn, Xã An Đồng, Xã Hồng Thái";
                        break;
                    }
                    case "Huyện An Lão":
                    {
                        infor = "17 đơn vị: Thị trấn An Lão, Thị trấn Trường Sơn, Xã Bát Trang, Xã Trường Thọ, Xã Trường Thành, Xã An Tiến, Xã Quang Hưng, Xã Quang Trung, Xã Quốc Tuấn, Xã An Thắng, Xã Tân Dân, Xã Thái Sơn, Xã Tân Viên, Xã Mỹ Đức, Xã Chiến Thắng, Xã An Thọ, Xã An Thái";
                        break;
                    }
                    case "Huyện Bạch Long Vĩ":
                    {
                        infor = "0 đơn vị";
                        break;
                    }
                    case "Huyện Cát Hải":
                    {
                        infor = "12 đơn vị: Thị trấn Cát Bà, Thị trấn Cát Hải, Xã Nghĩa Lộ, Xã Đồng Bài, Xã Hoàng Châu, Xã Văn Phong, Xã Phù Long, Xã Gia Luận, Xã Hiền Hào, Xã Trân Châu, Xã Việt Hải, Xã Xuân Đám";
                        break;
                    }
                    case "Huyện Kiến Thụy":
                    {
                        infor = "18 đơn vị: Thị trấn Núi Đối, Xã Đông Phương, Xã Thuận Thiên, Xã Hữu Bằng, Xã Đại Đồng, Xã Ngũ Phúc, Xã Kiến Quốc, Xã Du Lễ, Xã Thuỵ Hương, Xã Thanh Sơn, Xã Minh Tân, Xã Đại Hà, Xã Ngũ Đoan, Xã Tân Phong, Xã Tân Trào, Xã Đoàn Xá, Xã Tú Sơn, Xã Đại Hợp";
                        break;
                    }
                    case "Huyện Thủy Nguyên":
                    {
                        infor = "37 đơn vị: Thị trấn Núi Đèo, Thị trấn Minh Đức, Xã Mỹ Đồng, Xã Đông Sơn, Xã Hoà Bình, Xã Trung Hà, Xã An Lư, Xã Thuỷ Triều, Xã Ngũ Lão, Xã Phục Lễ, Xã Tam Hưng, Xã Phả Lễ, Xã Lập Lễ, Xã Kiền Bái, Xã Thiên Hương, Xã Thuỷ Sơn, Xã Thuỷ Đường, Xã Hoàng Động, Xã Lâm Động, Xã Hoa Động, "
                                + "Xã Tân Dương, Xã Dương Quan, Xã Lại Xuân, Xã An Sơn, Xã Kỳ Sơn, Xã Liên Khê, Xã Lưu Kiếm, Xã Lưu Kỳ, Xã Gia Minh, Xã Gia Đức, Xã Minh Tân, Xã Phù Ninh, Xã Quảng Thanh, Xã Chính Mỹ, Xã Kênh Giang, Xã Hợp Thành, Xã Cao Nhân";
                        break;
                    }
                    case "Huyện Tiên Lãng":
                    {
                        infor = "21 đơn vị: Thị trấn Tiên Lãng, Xã Tiên Thanh, Xã Vinh Quang, Xã Cấp Tiến, Xã Kiến Thiết, Xã Đoàn Lập, Xã Bạch Đằng, Xã Quang Phục, Xã Toàn Thắng, Xã Tiên Thắng, Xã Tiên Minh, Xã Bắc Hưng, Xã Nam Hưng, Xã Hùng Thắng, Xã Tây Hưng, Xã Đông Hưng, Xã Đại Thắng, Xã Tiên Cường, Xã Tự Cường, Xã Quyết Tiến, Xã Khởi Nghĩa";
                        break;
                    }
                    case "Huyện Vĩnh Bảo":
                    {
                        infor = "30 đơn vị: Thị trấn Vĩnh Bảo, Xã Dũng Tiến, Xã Giang Biên, Xã Thắng Thuỷ, Xã Trung Lập, Xã Việt Tiến, Xã Vĩnh An, Xã Vĩnh Long, Xã Hiệp Hoà, Xã Hùng Tiến, Xã An Hoà, Xã Tân Hưng, Xã Tân Liên, Xã Nhân Hoà, Xã Tam Đa, Xã Hưng Nhân, Xã Vinh Quang, Xã Đồng Minh, Xã Thanh Lương, Xã Liên Am, Xã Lý Học, Xã Tam Cường, "
                                + "Xã Hoà Bình, Xã Tiền Phong, Xã Vĩnh Phong, Xã Cộng Hiền, Xã Cao Minh, Xã Cổ Am, Xã Vĩnh Tiến, Xã Trấn Dương";
                        break;
                    }
                }
                break;
            }
            case "Đà Nẵng":
            {
                switch (district)
                {
                    case "Quận Cẩm Lệ":
                    {
                        infor = "6 Phường";
                        break;
                    }
                    case "Quận Hải Châu":
                    {
                        infor = "13 Phường";
                        break;
                    }
                    case "Quận Liên Chiểu":
                    {
                        infor = "5 Phường";
                        break;
                    }
                    case "Quận Ngũ Hành Sơn":
                    {
                        infor = "4 Phường";
                        break;
                    }
                    case "Quận Sơn Trà":
                    {
                        infor = "7 Phường";
                        break;
                    }
                    case "Quận Thanh Khê":
                    {
                        infor = "10 Phường";
                        break;
                    }
                    case "Huyện Hòa Vang":
                    {
                        infor = "11 Xã";
                        break;
                    }
                    case "Huyện Hoàng Sa":
                    {
                        infor = "0 đơn vị";
                        break;
                    }
                }
                break;
            }
            case "Thành phố Hồ Chí Minh":
            {
                switch (district)
                {
                    case "Quận 1":
                    {
                        infor = "10 Phường";
                        break;
                    }
                    case "Quận 2":
                    {
                        infor = "Đã sát nhập vào thành phố Thủ Đức";
                        break;
                    }
                    case "Quận 3":
                    {
                        infor = "12 Phường";
                        break;
                    }
                    case "Quận 4":
                    {
                        infor = "13 Phường";
                        break;
                    }
                    case "Quận 5":
                    {
                        infor = "14 Phường";
                        break;
                    }
                    case "Quận 6":
                    {
                        infor = "14 Phường";
                        break;
                    }
                    case "Quận 7":
                    {
                        infor = "10 Phường";
                        break;
                    }
                    case "Quận 8":
                    {
                        infor = "16 Phường";
                        break;
                    }
                    case "Quận 9":
                    {
                        infor = "Đã sát nhập vào thành phố Thủ Đức";
                        break;
                    }
                    case "Quận 10":
                    {
                        infor = "15 Phường";
                        break;
                    }
                    case "Quận 11":
                    {
                        infor = "16 Phường";
                        break;
                    }
                    case "Quận 12":
                    {
                        infor = "11 Phường";
                        break;
                    }
                    case "Quận Tân Bình":
                    {
                        infor = "15 Phường";
                        break;
                    }
                    case "Quận Tân Phú":
                    {
                        infor = "11 Phường";
                        break;
                    }
                    case "Quận Bình Tân":
                    {
                        infor = "10 Phường";
                        break;
                    }
                    case "Quận Bình Thạnh":
                    {
                        infor = "20 Phường";
                        break;
                    }
                    case "Quận Gò Vấp":
                    {
                        infor = "16 Phường";
                        break;
                    }
                    case "Quận Phú Nhuận":
                    {
                        infor = "13 Phường";
                        break;
                    }
                    case "Thành phố Thủ Đức":
                    {
                        infor = "34 Phường";
                        break;
                    }
                    case "Huyện Bình Chánh":
                    {
                        infor = "16 Xã";
                        break;
                    }
                    case "Huyện Cần Giờ":
                    {
                        infor = "7 Xã/Thị trấn";
                        break;
                    }
                    case "Huyện Củ Chi":
                    {
                        infor = "21 Xã/Thị trấn";
                        break;
                    }
                    case "Huyện Nhà Bè":
                    {
                        infor = "7 Xã/Thị trấn";
                        break;
                    }
                    case "Huyện Hóc Môn":
                    {
                        infor = "12 Xã/Thị trấn";
                        break;
                    }
                }
                break;
            }
            case "Cần Thơ":
            {
                switch (district)
                {
                    case "Quận Bình Thủy":
                    {
                        infor = "8 Phường";
                        break;
                    }
                    case "Quận Cái Răng":
                    {
                        infor = "7 Phường";
                        break;
                    }
                    case "Quận Ninh Kiều":
                    {
                        infor = "11 Phường";
                        break;
                    }
                    case "Quận Ô Môn":
                    {
                        infor = "7 Phường";
                        break;
                    }
                    case "Quận Thốt Nốt":
                    {
                        infor = "9 Phường";
                        break;
                    }
                    case "Huyện Cờ Đỏ":
                    {
                        infor = "10 Xã/Thị Trấn";
                        break;
                    }
                    case "Huyện Phong Điền":
                    {
                        infor = "7 Xã/Thị trấn";
                        break;
                    }
                    case "Huyện Thới Lai":
                    {
                        infor = "13 Xã/Thị trấn";
                        break;
                    }
                    case "Huyện Vĩnh Thạnh":
                    {
                        infor = "11 Xã/Thị trấn";
                        break;
                    }
                }
                break;
            }
        }
        return infor;
    }
}
