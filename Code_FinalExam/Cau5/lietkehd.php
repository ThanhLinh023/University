<?php
    $servername = "localhost";
    $username = "root";
    $password = "vtl10122003";
    $conn = mysqli_connect($servername, $username, $password, 'sys');
    $conn->set_charset('utf8');

    $makh = $_POST['makh'];
    $q = "select mahd from hoadon where makh = '$makh'";
    $rel = $conn->query($q);
    echo "Mã hóa đơn <select onchange=\"handleHD(event)\">";
    while ($row = $rel->fetch_row())
    {
        echo "<option value=\"" . $row[0] . "\"" . ">$row[0]</option>";
    }
    echo "</select>";
?>