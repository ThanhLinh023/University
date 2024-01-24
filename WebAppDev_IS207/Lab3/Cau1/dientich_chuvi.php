<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tính diện tích và chu vi hình chữ nhật</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Tính diện tích và chu vi hình chữ nhật</h1>
    <form method="get" action="#">
        <table>
            <tr>
                <td>Chiều dài</td>
                <td><input type="text" name="length"/></td>
            </tr>
            <tr>
                <td>Chiều rộng</td>
                <td><input type="text" name="width"/></td>
            </tr>
            <tr>
                <td colspan="2">
                    <button type="submit" name="submit" value="calculate">Tính</button>
                </td>
            </tr>
        </table>
    </form>
    <?php 
        if (isset($_GET['submit']) && $_GET['submit'] == "calculate")
        {
            $l = $_GET['length'];
            $w = $_GET['width'];
            $square = (float)$l * (float)$w;
            $peri = ((float)$l + (float)$w) * 2;
            echo "Square: " . $square . "<br>";
            echo "Perimeter: " . $peri . "<br>";
        }
    ?>
</body>
</html>