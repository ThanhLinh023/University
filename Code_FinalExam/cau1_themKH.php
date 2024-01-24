<form method="post" action="">
    <label>Mã khách hàng</label>
    <input type="text" name="makh" /><br />
    <label>Tên khách hàng</label>
    <input type="text" name="tenkh" /><br />
    <label>Số điện thoại</label>
    <input type="text" name="sdt" /><br />
    <label>Căn cước công dân</label>
    <input type="text" name="cccd" /><br />
    <input type="submit" value="Thêm" name="themkh">
</form>
<?php 
    include "connection.php";
    if (isset($_POST['themkh']) && $_POST['themkh'] == "Thêm")
    {
        $makh = $_POST["makh"];
        $tenkh = $_POST["tenkh"];
        $sdt = $_POST["sdt"];
        $cccd = $_POST["cccd"];
        $cmd = "insert into khachhang values ('$makh', '$tenkh', '$sdt', '$cccd')";
        if ($conn->query($cmd) == true)
        {
            echo "Da them khach hang moi.";
        }
        else echo "Them khong duoc.";
    }
    $conn->close();
?>