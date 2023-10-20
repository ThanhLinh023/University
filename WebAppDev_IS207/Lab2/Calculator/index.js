var expression = document.querySelector('.expression')
var result = document.querySelector('.show_result')
var btns = Array.from(document.querySelectorAll('.btn')) //Đẩy tất cả giá trị các nút vào một mảng

btns.forEach(function (btn) {
    btn.addEventListener('click', function () {
        if (btn.innerHTML == '0') {
            //Trường hợp người dùng nhập số 0 đầu tiên
            expression.innerHTML = ''
        }
        if (btn.innerHTML == "CE") {
            //Trường hợp nút CE
            expression.innerHTML = ''
            result.innerHTML = '0'
        }
        else if (btn.innerHTML == "Del") {
            var arrText = Array.from(expression.innerHTML) // Lưu các expresion vào một mảng để tách (string -> array)
            arrText.splice(arrText.length - 1, 1) // Xoá đi kí tự cuối
            if (arrText.length != 0) {
                expression.innerHTML = arrText.join('')
            }
            else { expression.innerHTML = '' }
        }
        else if (btn.innerHTML == "=") {
            result.innerHTML = eval(expression.innerHTML) //Hàm eval() để tính phép tính cơ sở: +,-,*,/
        }
        else expression.innerHTML += btn.innerHTML
    })
})