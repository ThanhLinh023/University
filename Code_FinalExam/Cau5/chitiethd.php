<?php
    $servername = "localhost";
    $username = "root";
    $password = "vtl10122003";
    $conn = mysqli_connect($servername, $username, $password, 'sys');
    $conn->set_charset('utf8');

    $mahd = $_POST['mahd'];
    $q = "select thue.maphong, loaiphong from thue, phong
    where thue.maphong = phong.maphong
    and mahd = '$mahd'";
    $rel = $conn->query($q);
    echo "<p>Danh sách phòng trong hóa đơn</p>";
    echo "<table style=\"border: solid black\">
          <thead>
            <th><b>STT</b></th>
            <th><b>Mã phòng</b></th>
            <th><b>Loại phòng</b></th>
          </thead>
          <tbody>";
    $i = 1;
    while ($row = $rel->fetch_row())
    {
        echo "<tr>
            <td>$i</td>
            <td>$row[0]</td>
            <td>$row[1]</td>
        </tr>";
        $i++;
    }
    echo "</tbody";
    echo "</table>";
?>