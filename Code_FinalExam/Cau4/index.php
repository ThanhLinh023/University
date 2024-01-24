<html>
    <head>
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>
    </head>
    <body>
    <div>
        Số lượng khách hàng <input type="text" class="slkh" onkeydown="handle(event)">
    </div>
    <div class="show">
    </div>
    </body>
    <script>
        function handle(event) {
            if (event.key == "Enter")
            {
                var number = event.target.value;
                $.ajax({
                    url: 'lietkekh.php',
                    method: 'POST',
                    data: {
                        slkh: number
                    },
                    success: function(data)
                    {
                        $('.show').html(data);
                    }
                });
            }
        }
    </script>
</html>