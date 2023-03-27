let emptyArray = []
let numbers = [1, 2, 3, 4, 5]
console.log(numbers.length)
console.log(numbers[0] + " " + numbers[(numbers.length + 1)/ 2] + " " + numbers[numbers.length - 1])
let mixedDataTypes = [1, "one", 2, "three", 4]
let itCompanies = ["Facebook", "Google", "Microsoft", "Apple", "IBM", "Oracle and Amazon"]
console.log(itCompanies)
console.log(itCompanies.length)
console.log(itCompanies[0] + " " + itCompanies[(itCompanies.length + 1) / 2] + " " + itCompanies[itCompanies.length - 1])
console.log(itCompanies[0].toUpperCase())
console.log(itCompanies.toString() + " are big companies") 
let ooComp = []
for (let i = 0; i < itCompanies.length; i++)
{
    if (itCompanies[i].includes("oo")) {
        ooComp.push(itCompanies[i])
    }
}
console.log(ooComp)
itCompanies.sort()
console.log(itCompanies)
numbers.reverse()
console.log(numbers)
console.log(itCompanies.slice(0, 3))
console.log(itCompanies.slice(itCompanies.length - 3, itCompanies.length))
itCompanies.shift()
console.log(itCompanies)
itCompanies.splice((itCompanies.length / 2), 1)
console.log(itCompanies)
itCompanies.pop()
console.log(itCompanies)
itCompanies.splice(itCompanies)
console.log(itCompanies)