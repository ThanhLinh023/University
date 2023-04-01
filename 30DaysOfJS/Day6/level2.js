let s = "qwertyuiopasdfghjklzxcvbnm0123456789"
let idLength = Math.round(Math.random() * 20)
let id = ""
for (let i = 0; i < idLength; i++)
{
    id += s[Math.round(Math.random() * s.length)]
}
console.log(id)
const hexValue = "0123456789abcdef"
let hexima = "#"
for (let i = 0; i < 6; i++)
{
    hexima += hexValue[Math.round(Math.random() * 15)]
}
console.log(hexima)
let red, green, blue
red = Math.round(Math.random() * 255)
green = Math.round(Math.random() * 255)
blue = Math.round(Math.random() * 255)
console.log(`rgb(${red},${green},${blue})`)
const countries = [
    'Albania',
    'Bolivia',
    'Canada',
    'Denmark',
    'Ethiopia',
    'Finland',
    'Germany',
    'Hungary',
    'Ireland',
    'Japan',
    'Kenya'
]
const webTechs = [
    'HTML',
    'CSS',
    'JavaScript',
    'React',
    'Redux',
    'Node',
    'MongoDB'
]
const newCountries = []
for (let i = 0; i < countries.length; i++)
{
    newCountries.push(countries[i].toUpperCase())
}
console.log(newCountries)
const countriesLength = []
for (let i = 0; i < countries.length; i++)
{
    countriesLength.push(countries[i].length)
}
console.log(countriesLength)
const detailCountries = []
for (let i = 0; i < countries.length; i++)
{
    let index = []
    index.push(countries[i])
    index.push(newCountries[i].slice(0, 3))
    index.push(countriesLength[i])
    detailCountries.push(index)
}
console.log(detailCountries)
let findLand = []
for (let i = 0; i < countries.length; i++)
{
    if (countries[i].includes("land"))
    {
        findLand.push(countries[i])
    }
}
if (findLand.length == 0)
{
    console.log('All these countries are without land')
}
else
{
    console.log(findLand)
}
let FindIA = []
for (let i = 0; i < countries.length; i++)
{
    if (countries[i].includes("ia"))
    {
        FindIA.push(countries[i])
    }
}
if (FindIA.length == 0)
{
    console.log('All these countries are without land')
}
else
{
    console.log(FindIA)
}
let tmp = ""
let max1 = -1
for (let i = 0; i < countries.length; i++)
{
    if (countries[i].length >= max)
    {
        max = countries[i].length
        tmp = countries[i]
    }
}
console.log(tmp)
for (let i = 0; i < countries.length; i++)
{
    if (countries[i].length == 5)
    {
        console.log(countries[i])
    }
}
let tmp2 = ""
let max2 = -1
for (let i = 0; i < webTechs.length; i++)
{
    if (webTechs[i].length >= max2)
    {
        max = webTechs[i].length
        tmp2 = webTechs[i]
    }
}
console.log(tmp2)
let newWebTechs = []
for (let i = 0; i < webTechs.length; i++)
{
    let index2 = []
    index2.push(webTechs[i])
    index2.push(webTechs[i].length)
    newWebTechs.push(index2)
}
console.log(newWebTechs)
const fullStack = [
    ['HTML', 'CSS', 'JS', 'React'],
    ['Node', 'Express', 'MongoDB']
]
for (let i = 0; i < fullStack.length; i++)
{
    for (let j = 0; j < fullStack[i].length; j++)
    {
        console.log(fullStack[i][j])
    }
}
