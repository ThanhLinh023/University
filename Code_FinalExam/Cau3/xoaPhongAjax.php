<?php
$servername = "localhost";
$username = "root";
$password = "vtl10122003";

$conn = mysqli_connect($servername, $username, $password, 'sys');
$conn->set_charset('utf8');

$maphong = $_POST['maphong'];
$update = "update phong set tinhtrang = 'Còn phòng' where maphong = '$maphong'";
$conn->query($update);
$q = "select maphong, tenphong from phong where tinhtrang = 'Còn phòng'";
                if ($rel = $conn->query($q))
                {
                    while ($row = $rel->fetch_row())
                    {
                        $roomId = $row[0];
                        $pattern = "/\d+/";
                        preg_match($pattern, $roomId, $matches);
                        $number = (int)$matches[0];
                        echo "<tr id=\"added_$roomId\"><td>$number</td><td>$roomId</td><td>$row[1]</td>";
                        echo "<td><button class=\"addRoom\" type=\"button\" data-id=\"$roomId\">Thêm</button></td></tr>";
                    }
                }
?>