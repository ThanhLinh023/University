<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tìm kiếm tên</title>
    <style>
        label {
            font-size: 30px;
        }
        input {
            height: 30px;
            font-size: 25px;
        }
        button {
            font-size: 20px;
        }
    </style>
</head>
<body>
    <form method="get" action="#">
        <label for="find">Nhập tên cần tìm</label>
        <input type="text" name="find">
        <br>
        <button type="submit" name="findBtn" value="finding">Tìm</button>
    </form>
    <?php 
        $people = [
            "Tuấn" => 21,
            "Tú" => 19,
            "Tâm" => 22,
            "Tùng" => 20,
            "Thành" => 21,
            "Thọ" => 18
        ];
        if (isset($_GET['findBtn']) && $_GET['findBtn'] == "finding")
        {
            $name = $_GET['find'];
            $d = 0;
            foreach ($people as $person => $age)
            {
                if ($name == $person)
                {
                    $d++;
                    break;
                }
            }
            if ($d != 0)
            {
                echo "Tìm thấy " . $name . " trong mảng<br>";
            }
            else
            {
                echo "Không tìm thấy " . $name . " trong mảng<br>";
                echo "<h1>Xuất mảng</h1>";
                foreach ($people as $person => $age)
                {
                    echo $person . " " . $age . "<br>";
                }
            }
        }
    ?>
</body>
</html>