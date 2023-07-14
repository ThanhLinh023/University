const text = 'He earns 4000 euro from salary per month, 10000 euro annual bonus, 5500 euro online courses per month.'
const num = text.match(/\d{4,5}/g)
const sum = arr => {
    let s = 0
    for (i in arr) s += Number(arr[i])
    return s
}
// console.log("Total income: " + sum(num))
const validVariable = text => {
    const pattern = /^[0-9]|-/g
    if (pattern.test(text)) return false
    else return true
}
console.log(validVariable('first_name')) 
console.log(validVariable('first-name'))
console.log(validVariable('1first_name'))
console.log(validVariable('firstname')) 