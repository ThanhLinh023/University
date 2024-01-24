<html>
    <head>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>
    </head>
    <body>
        Tên khách hàng
        <select class="makh" onchange="handle(event)">
        <?php
            $servername = "localhost";
            $username = "root";
            $password = "vtl10122003";
    
            $conn = mysqli_connect($servername, $username, $password, 'sys');
            $conn->set_charset('utf8');
            $q = "select tenkh, makh from khachhang";
            if ($rel = $conn->query($q))
            {
                while ($row = $rel->fetch_row())
                {
                    echo "<option value=\"" . $row[1] . "\"" . ">$row[0]</option>";
                }
            }
        ?>
        </select>
        <div class="showHD"></div>
        <div class="showThue"></div>
    </body>
    <script>
        function handle(event)
        {
            var cusId = event.target.value;
            $.ajax({
                url: 'lietkehd.php',
                method: 'POST',
                data: {
                    makh: cusId
                },
                success: function(data)
                {
                    $('.showHD').html(data);
                }
            });
        }
    </script>
    <script>
        function handleHD(event)
        {
            var oId = event.target.value;
            $.ajax({
                url: 'chitiethd.php',
                method: 'POST',
                data: {
                    mahd: oId
                },
                success: function(data)
                {
                    $('.showThue').html(data);
                }
            });
        }
    </script>
</html>