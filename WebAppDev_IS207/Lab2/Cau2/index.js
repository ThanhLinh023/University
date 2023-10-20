const foods = {
    "Bún bò": 20000,
    "Hủ tiếu": 18000,
    "Bánh canh": 17000,
    "Phở bò": 19000,
    "Nuôi": 15000,
    "Bánh mì thịt": 12000,
    "Bánh cuốn": 15000
}
const drinks = {
    "Cà phê đá": 12000,
    "Cà phê sữa": 15000,
    "Chanh dây": 13000,
    "Chanh muối": 12000,
    "Xí muội": 14000,
    "Sữa tươi": 13000,
    "Cam vắt": 17000
}
const foodOptions = document.querySelector('#food')
const drinkOptions = document.querySelector('#drink')
const btnCal = document.querySelector('#btn')
const money = document.querySelector('#total_money')
var totalMoney = 0
btnCal.onclick = function() {
    const selectedFoods = []
    const selectedDrinks = []
    for (const f_opt of foodOptions.options)
    {
        if (f_opt.selected)
        {
            selectedFoods.push(f_opt.value)
        }
    }
    for (const d_opt of drinkOptions.options)
    {
        if (d_opt.selected)
        {
            selectedDrinks.push(d_opt.value)
        }
    }
    for (let i = 0; i < selectedFoods.length; i++)
    {
        totalMoney += foods[selectedFoods[i]]
    }
    for (let i = 0; i < selectedDrinks.length; i++)
    {
        totalMoney += drinks[selectedDrinks[i]]
    }
    if (document.querySelector('#night').checked)
    {
        totalMoney *= 1.1
    }
    money.innerHTML = totalMoney
    totalMoney = 0
}