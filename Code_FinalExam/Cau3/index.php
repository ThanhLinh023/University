<html>
<head>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>
</head>
<body>
<?php
$servername = "localhost";
$username = "root";
$password = "vtl10122003";

$conn = mysqli_connect($servername, $username, $password, 'sys');
$conn->set_charset('utf8');
?>
<div>
    Mã hóa đơn:
    <select name="mahd">
        <?php 
            $q = "select mahd from hoadon";
            if ($rel = $conn->query($q))
            {
                while ($row  = $rel->fetch_row())
                {
                    echo "<option value=\"" . $row[0] . "\">" . $row[0] . "</option>";
                }
            }
        ?>
    </select>
</div>
<h3>Danh sách các phòng còn trống</h3>
<div>
    <table style="border: solid black;">
        <thead>
            <th><b>STT</b></th>
            <th><b>Mã phòng</b></th>
            <th><b>Tên phòng</b></th>
            <th><b>Chức năng</b></th>
        </thead>
        <tbody class="chuadat">
            <?php
                $q = "select maphong, tenphong from phong where tinhtrang = 'Còn phòng'";
                if ($rel = $conn->query($q))
                {
                    while ($row = $rel->fetch_row())
                    {
                        $roomId = $row[0];
                        $pattern = "/\d+/";
                        preg_match($pattern, $roomId, $matches);
                        $number = (int)$matches[0];
                        echo "<tr id=\"not_$roomId\"><td>$number</td><td>$roomId</td><td>$row[1]</td>";
                        echo "<td><button class=\"addRoom\" type=\"button\" data-id=\"$roomId\">Thêm</button></td></tr>";
                    }
                }
            ?>
        </tbody>
    </table>
</div>
<h3>Danh sách phòng đã đặt</h3>
<div>
    <table style="border: solid black">
        <thead>
            <th><b>STT</b></th>
            <th><b>Mã phòng</b></th>
            <th><b>Tên phòng</b></th>
            <th><b>Chức năng</b></th>
        </thead>
        <tbody class="phongdat">
            <?php
                    $q = "select maphong, tenphong from phong where tinhtrang = 'Đã đặt'";
                    if ($rel = $conn->query($q))
                    {
                        while ($row = $rel->fetch_row())
                        {
                            $roomId = $row[0];
                            $pattern = "/\d+/";
                            preg_match($pattern, $roomId, $matches);
                            $number = (int)$matches[0];
                            echo "<tr id=\"not_$roomId\"><td>$number</td><td>$roomId</td><td>$row[1]</td>";
                            echo "<td><button class=\"delRoom\" type=\"button\" data-id=\"$roomId\">Xóa</button></td></tr>";
                        }
                    }
            ?>
        </tbody>
    </table>
</div>
</body>
<script type="text/javascript">
    $(document).ready(function () {
        $('.addRoom').click(function () {
            var roomId = $(this).data('id');
            $.ajax({
                url: 'themPhongAjax.php',
                method: 'POST',
                data: {
                    maphong: roomId
                },
                success: function(data) {
                    $('.phongdat').html(data);
                }
            });
        })
        $(this).parent().parent().remove();
    })
</script>
<script type="text/javascript">
    $(document).ready(function () {
        $('.delRoom').click(function () {
            var roomId = $(this).data('id');
            $.ajax({
                url: 'xoaPhongAjax.php',
                method: 'POST',
                data: {
                    maphong: roomId
                },
                success: function(data) {
                    $('.chuadat').html(data);
                }
            });
        })
    })
</script>
</html>