let age = prompt("Enter your age: ")
if (age >= 18)
{
    alert("You are old enough to drive.")
}
else
{
    alert(`You are left with ${18 - age} years to drive.`)
}
let myAge = 20
if (age == myAge)
{
    alert("You are as old as me")
}
else if (age > myAge)
{
    alert(`You are ${age - myAge} years older than me`)
}
else
{
    alert(`You are ${myAge - age} years younger than me`)
}
let a3 = 4
let b3 = 3
if (a3 > b3)
{
    console.log(`${a3} is greater than ${b3}`)
}
else
{
    console.log(`${a3} is less than ${b3}\n`)
}
console.log(a3 > b3 ? `${a3} is greater than ${b3}` : `${a3} is smaller than ${b3}`)
let a4 = prompt("Enter a number: ")
if (a4 % 2 == 0)
{
    alert(`${a4} is an even number`)
}
else
{
    alert(`${a4} is an odd number`)
}