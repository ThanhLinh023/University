<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tính tổng số ngày</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <form method="get" action="#">
        <table>
            <tr>
                <td>Ngày</td>
                <td><input type="text" name="day"/></td>
            </tr>
            <tr>
                <td>Tháng</td>
                <td><input type="text" name="month"/></td>
            </tr>
            <tr>
                <td>Năm</td>
                <td><input type="text" name="year"/></td>
            </tr>
            <tr>
                <td colspan="2">
                    <button type="submit" name="submit" value="calculate">Tổng</button>
                </td>
            </tr>
        </table>
    </form>
    <?php 
        if (isset($_GET['submit']) && $_GET['submit'] == "calculate")
        {
            $day = $_GET['day'];
            $month = $_GET['month'];
            $year = $_GET['year'];
            $totalDates = 0;
            if (($day > 0 && $day < 32) && ($month > 0 && $month < 13) && $year > 0)
            {
                $dateInMonth = [
                    "1" => 31,
                    "2" => 28,
                    "3" => 31,
                    "4" => 30,
                    "5" => 31,
                    "6" => 30,
                    "7" => 31,
                    "8" => 31,
                    "9" => 30,
                    "10" => 31,
                    "11" => 30,
                    "12" => 31
                ];
                if ($year % 400 == 0 || ($year % 4 == 0 && $year % 100 != 0))
                {
                    $dateInMonth['2'] = 29;
                }
                for ($i = 1; $i < $month; $i++)
                {
                    $totalDates += $dateInMonth[$i];
                }
                echo "Total days from 01/01/" . $year . " to " . $day . "/" . $month . "/" . $year . ": " . $totalDates + $day;
            }
            else
            {
                echo "Invalid input";
            }
        }
    ?>
</body>
</html>