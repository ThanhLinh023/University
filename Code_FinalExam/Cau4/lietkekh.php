<?php
    $servername = "localhost";
    $username = "root";
    $password = "vtl10122003";

    $conn = mysqli_connect($servername, $username, $password, 'sys');
    $conn->set_charset('utf8');
    $slkh = $_POST['slkh'];
    $cmd = "select kh.makh, tenkh, sum(tongtien) as total from hoadon hd, khachhang kh
    where kh.makh = hd.makh
    group by hd.makh
    order by total desc
    limit $slkh";
    $rel = $conn->query($cmd);
    echo "<h3>$slkh khách hàng có số tiền thuê nhiều nhất</h3>";
    echo "<table stlye=\"border: solid black\">
        <thead>
            <th><b>STT</b></th>
            <th><b>Mã khách hàng</b></th>
            <th><b>Tên khách hàng</b></th>
            <th><b>Tổng tiền thuê</b></th>
        </thead>
        <tbody>";
    $i = 1;
    while ($row = $rel->fetch_row())
    {

        echo "<tr>
            <td>$i</td>
            <td>$row[0]</td>
            <td>$row[1]</td>
            <td>$row[2]</td>
        </tr>";
        $i++;
    }
    echo "</tbody>";
    echo "</table>";
?>