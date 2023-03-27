const ages = [19, 22, 19, 24, 20, 25, 26, 24, 25, 24]
ages.sort()
let minAge = ages[0]
let maxAge = ages[ages.length - 1]
let medianAge = ages[ages.length / 2]
let avgAge = 0
for (let i = 0; i < ages.length; i++) {
    avgAge += ages[i]
}
avgAge /= ages.length
let range = maxAge - minAge
let minAvg = Math.abs(minAge - avgAge)
let maxAvg = Math.abs(maxAge - avgAge)
console.log("Min age: " + minAge)
console.log("Max age: " + maxAge)
console.log("Median age:", medianAge)
console.log("Average age:", avgAge)
console.log("Range: ", range)
console.log("Min - average age:", minAvg)
console.log("Max - average age:", maxAvg)