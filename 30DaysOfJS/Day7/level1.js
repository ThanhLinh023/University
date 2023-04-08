function fullName() 
{
    console.log("Michael Filbert")
}
const fullName2 = (first, last) => `${first} ${last}`
const addNumbers = (a, b) => a + b
const areaOfRectangle = (l, w) => l * w
const perimeterOfRectangle = (l, w) => 2 * (l + w)
const volumeOfRectPrism = (l, w, h) => l*w*h
const areaOfCircle = (r) => Math.PI * r * r
const circumOfCircle = (r) => Math.PI * 2 * r
const weightSubtance = (mass, gravity) => mass * gravity
const BMI = (w, h) => w / (h * h)
let bmi = BMI(50, 1.7)
let type = ''
if (bmi < 18.5)
{
    type = "Underweight"
}
else if (bmi >= 18.5 && bmi <= 24.9)
{
    type = "Normal"
}
else if (bmi >= 25 && bmi <= 29.9)
{
    type = "Overweight"
}
else
{
    type = "Obese"
}
const findMax = (a, b, c) => {
    return a > b ? a : (b > c ? b : c)
}
const findMin = (a, b, c) => {
    return a < b ? a : (b < c ? b : c)
}