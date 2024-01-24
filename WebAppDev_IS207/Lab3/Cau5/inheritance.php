<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tính diện tích và thể tích hình lập phương</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Tính diện tích và chu vi hình lập phương</h1>
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
                <td>Chiều cao</td>
                <td><input type="text" name="height"/></td>
            </tr>
            <tr>
                <td colspan="2">
                    <button type="submit" name="submit" value="calculate">Tính</button>
                </td>
            </tr>
        </table>
    </form>
    <?php 
        abstract class ParentClass
        {
            protected $length, $width;
            public function __construct($a, $b)
            {
                $this->length = $a;
                $this->width = $b;
            }
            public function volume()
            {
                return $this->length * $this->width;
            }
        }
        class DerivedClass extends ParentClass
        {
            private $height;
            public function __construct($a, $b, $c)
            {
                parent::__construct($a, $b);
                $this->height = $c;
            }
            public function square()
            {
                return 2 * $this->height * ($this->length + $this->width) + 2 * $this->length * $this->width;
            }
            public function volume()
            {
                return parent::volume() * $this->height;
            }
        }
        if (isset($_GET['submit']) && $_GET['submit'] == "calculate")
        {
            $tmp = new DerivedClass((float)$_GET['length'], (float)$_GET['height'], (float)$_GET['width']);
            echo "Diện tích: " . $tmp->square() . "<br>";
            echo "Thể tích: " . $tmp->volume() . "<br>";
        }
    ?>
</body>
</html>