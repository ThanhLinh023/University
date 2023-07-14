const countries = ['Finland', 'Sweden', 'Denmark', 'Norway', 'IceLand']
const names = ['Asabeneh', 'Mathias', 'Elias', 'Brook']
const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
const products = [
    { product: 'banana', price: 3 },
    { product: 'mango', price: 6 },
    { product: 'potato', price: ' ' },
    { product: 'avocado', price: 8 },
    { product: 'coffee', price: 10 },
    { product: 'tea', price: '' },
]
// countries.forEach((a) => console.log(a))
// names.forEach((a) => console.log(a))
// numbers.forEach((a) => console.log(a))
const upperCountries = countries.map((a) => a.toUpperCase())
const countriesLength = countries.map((a) => a.length)
const squareNum = numbers.map((a) =>  a * a)
const upperName = names.map((name) => name.toUpperCase())
const productPrice = products.map((a) => `${a.product} - ${a.price}`)
// console.log(upperCountries)
// console.log(countriesLength)
// console.log(squareNum)
// console.log(upperName)
// console.log(productPrice)
const countriesLand = countries.filter((a) => a.includes("land"))
const countries6Char = countries.filter((a) => a.length == 6)
const coutriesGreater6 = countries.filter((a) => a.length >= 6)
const countryStartE = countries.filter((a) => a.startsWith("E"))
const priceValue = products.filter((a) => a.price != '')
// console.log(countriesLand)
// console.log(countries6Char)
// console.log(coutriesGreater6)
// console.log(countryStartE)
// console.log(priceValue)
const getStringList = (arr) => arr.map((a) => typeof a == 'string')
// console.log(getStringList([1, 2, 'test', 'abc', '123']))
const sumUseReduce = numbers.reduce((a, b) => a + b, 0)
// console.log(sumUseReduce)
const concatCountry = "Estonia, " + countries.reduce((a, b) => `${a}, ${b}`) + " and Iceland are north European countries"
// console.log(concatCountry)
// console.log(names.some((a) => a.length > 7))
// console.log(countries.every((a) => a.includes("land")))
// console.log(countries.find((a) => a.length === 6))
// console.log(countries.findIndex((a) => a.length === 6))
console.log(countries.findIndex((a) => a === "Russia"))