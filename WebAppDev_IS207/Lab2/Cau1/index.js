const input_sal = document.getElementById('input_sal')
const hs = document.getElementById('heso')
var inputSal, heso
input_sal.oninput = function(e) {
    inputSal = e.target.value
}
hs.oninput = function(e) {
    heso = e.target.value
}
var salary = 0
const showSal = document.getElementById('salary')
function compute() {
    salary = inputSal * heso
    showSal.innerHTML = salary
    salary = 0
    event.preventDefault()
}