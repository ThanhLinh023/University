let text = 'I love teaching and empowering people. I teach HTML, CSS, JS, React, Python.'
text.replace(',', ' ')
text.replace('.', ' ')
let words = text.split(' ')
console.log(words)
console.log(words.length)
const shoppingCart = ['Milk', 'Coffee', 'Tea', 'Honey']
if (!shoppingCart.includes("Meat") == true)
{
    shoppingCart.unshift("Meat")
}
if (!shoppingCart.includes("Sugar") == true)
{
    shoppingCart.push("Sugar")
}
shoppingCart.splice(shoppingCart.indexOf("Honey"), 1)
shoppingCart[shoppingCart.indexOf("Tea")] = "Green Tea"
console.log(shoppingCart)
const frontEnd = ['HTML', 'CSS', 'JS', 'React', 'Redux']
const backEnd = ['Node','Express', 'MongoDB']
const fullStack = frontEnd.concat(backEnd)
console.log(fullStack)