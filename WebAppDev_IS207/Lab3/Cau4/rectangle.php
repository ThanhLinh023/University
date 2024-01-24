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
        class Rectangle
        {
            private $length, $width;
            public function __construct($a, $b)
            {
                $this->length = $a;
                $this->width = $b;
            }
            public function square()
            {
                return $this->length * $this->width;
            }
            public function perimeter()
            {
                return ($this->length + $this->width) * 2;
            }
        }
        if (isset($_GET['submit']) && $_GET['submit'] == "calculate")
        {
            $rec = new Rectangle((float)$_GET['length'], (float)$_GET['width']);
            echo "Square: " . $rec->square() . "<br>";
            echo "Perimeter: " . $rec->perimeter() . "<br>";
        }
    ?>
</body>
</html>