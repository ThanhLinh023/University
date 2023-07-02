package vietnamprovincesearching;
import java.util.*;

public class VPSModel {
    protected HashMap<String, String> city;
    protected HashMap<String, String> district;
    public VPSModel()
    {
        initialData();
    }
    public void initialData()
    {
        city = new HashMap<String, String>();
        district = new HashMap<String, String>();
        city.put("HN", "Hà Nội");
        city.put("HP", "Hải Phòng");
        city.put("DN", "Đà Nẵng");
        city.put("TPHCM", "Thành phố Hồ Chí Minh");
        city.put("CT", "Cần Thơ");
        district.put("HN1", "Quận Ba Đình");
        district.put("HN2", "Quận Hoàn Kiếm");
        district.put("HN3", "Quận Tây Hồ");
        district.put("HN4", "Quận Long Biên");
        district.put("HN5", "Quận Cầu Giấy");
        district.put("HN6", "Quận Đống Đa");
        district.put("HN7", "Quận Hai Bà Trưng");
        district.put("HN8", "Quận Hoàng Mai");
        district.put("HN9", "Quận Thanh Xuân");
        district.put("HN10", "Quận Hà Đông");
        district.put("HN11", "Quận Bắc Từ Liêm");
        district.put("HN12", "Quận Nam Từ Liêm");
        district.put("HN13", "Thị Xã Sơn Tây");
        district.put("HN14", "Huyện Ba Vì");
        district.put("HN15", "Huyện Chương Mỹ");
        district.put("HN16", "Huyện Đan Phượng");
        district.put("HN17", "Huyện Đông Anh");
        district.put("HN18", "Huyện Gia Lâm");
        district.put("HN19", "Huyện Hoài Đức");
        district.put("HN20", "Huyện Mê Linh");
        district.put("HN21", "Huyện Mỹ Đức");
        district.put("HN22", "Huyện Phú Xuyên");
        district.put("HN23", "Huyện Phúc Thọ");
        district.put("HN24", "Huyện Quốc Oai");
        district.put("HN25", "Huyện Sóc Sơn");
        district.put("HN26", "Huyện Thạch Thất");
        district.put("HN27", "Huyện Thanh Oai");
        district.put("HN28", "Huyện Thanh Trì");
        district.put("HN29", "Huyện Thường Tín");
        district.put("HN30", "Huyện Ứng Hòa");
        district.put("HP1", "Quận Đồ Sơn");
        district.put("HP2", "Quận Dương Kinh");
        district.put("HP3", "Quận Hải An");
        district.put("HP4", "Quận Hồng Bàng");
        district.put("HP5", "Quận Kiến An");
        district.put("HP6", "Quận Lê Chân");
        district.put("HP7", "Quận Ngô Quyền");
        district.put("HP8", "Huyện An Dương");
        district.put("HP9", "Huyện An Lão");
        district.put("HP10", "Huyện Bạch Long Vĩ");
        district.put("HP11", "Huyện Cát Hải");
        district.put("HP12", "Huyện Kiến Thụy");
        district.put("HP13", "Huyện Thủy Nguyên");
        district.put("HP14", "Huyện Tiên Lãng");
        district.put("HP15", "Huyện Vĩnh Bảo");
        district.put("DN1", "Quận Cẩm Lệ");
        district.put("DN2", "Quận Hải Châu");
        district.put("DN3", "Quận Liên Chiểu");
        district.put("DN4", "Quận Ngũ Hành Sơn");
        district.put("DN5", "Quận Sơn Trà");
        district.put("DN6", "Quận Thanh Khê");
        district.put("DN7", "Huyện Hòa Vang");
        district.put("DN8", "Huyện Hoàng Sa");
        district.put("TPHCM1", "Quận 1");
        district.put("TPHCM2", "Quận 2");
        district.put("TPHCM3", "Quận 3");
        district.put("TPHCM4", "Quận 4");
        district.put("TPHCM5", "Quận 5");
        district.put("TPHCM6", "Quận 6");
        district.put("TPHCM7", "Quận 7");
        district.put("TPHCM8", "Quận 8");
        district.put("TPHCM9", "Quận 9");
        district.put("TPHCM10", "Quận 10");
        district.put("TPHCM11", "Quận 11");
        district.put("TPHCM12", "Quận 12");
        district.put("TPHCM13", "Quận Bình Tân");
        district.put("TPHCM14", "Quận Bình Thạnh");
        district.put("TPHCM15", "Quận Gò Vấp");
        district.put("TPHCM16", "Quận Phú Nhuận");
        district.put("TPHCM17", "Quận Tân Phú");
        district.put("TPHCM18", "Quận Tân Bình");
        district.put("TPHCM19", "Thành phố Thủ Đức");
        district.put("TPHCM20", "Huyện Bình Chánh");
        district.put("TPHCM21", "Huyện Nhà Bè");
        district.put("TPHCM22", "Huyện Hóc Môn");
        district.put("TPHCM23", "Huyện Củ Chi");
        district.put("TPHCM24", "Huyện Cần Giờ");
        district.put("CT1", "Quận Bình Thủy");
        district.put("CT2", "Quận Cái Răng");
        district.put("CT3", "Quận Ninh Kiều");
        district.put("CT4", "Quận Ô Môn");
        district.put("CT5", "Quận Thốt Nốt");
        district.put("CT6", "Huyện Cờ Đỏ");
        district.put("CT7", "Huyện Phong Điền");
        district.put("CT8", "Huyện Thới Lai");
        district.put("CT9", "Huyện Vĩnh Thạnh");
    }
    HashMap<String, String> getCity()
    {
        return city;
    }
    HashMap<String, String> getDistrict()
    {
        return district;
    }
}
