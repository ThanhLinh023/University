<form method="post">
    Tên khách hàng 
    <select name="tenkh">
        <?php 
            include "connection.php";
            $q = "select tenkh, makh from khachhang";
            if ($rel = $conn->query($q))
            {
                while ($row = $rel->fetch_row())
                {
                    echo "<option value=\"" . $row[1] . "\"" . ">$row[0]</option>";
                }
            }
        ?>
    </select> <br />
    Mã hóa đơn <input type="text" name="mahd"><br/>
    Tên hóa đơn <input type="text" name="tenhd"><br />
    Tổng tiền <input type="text" name="tongtien"><br />
    <input type="submit" value="Thêm" name="themhd">
</form>
<?php 
    include "connection.php";
    if (isset($_POST['themhd']) && $_POST['themhd'] == "Thêm")
    {
        $makh =  $_POST['tenkh'];
        $mahd = $_POST['mahd'];
        $tenhd = $_POST['tenhd'];
        $tongtien = $_POST['tongtien'];
        $cmd = "insert into hoadon values ('$mahd', '$tenhd', '$makh', '$tongtien')";
        if ($conn->query($cmd))
        {
            echo "Them hoa don thanh cong";
        }
        else echo "Them khong thanh cong";
    }
    $conn->close();
?>