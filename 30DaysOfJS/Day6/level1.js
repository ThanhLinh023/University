let rel = ""
for (let i = 0; i < 7; i++)
{
    rel += "#"
    console.log(rel)
}
for (let i = 0; i <= 10; i++)
{
    console.log(`${i} x ${i} = ${i * i}`)
}
console.log("i\ti^2\ti^3")
for (let i = 0; i <= 10; i++)
{
    console.log(`${i}\t ${i*i}\t ${i*i*i}`)
}
function isPrime(a)
{
    if (a < 2)
    {
        return false
    }
    else
    {
        for (let i = 2; i <= Math.sqrt(a); i++)
        {
            if (a % i == 0)
            {
                return false
            }
        }
        return true;
    }
}
for (let i = 0; i <= 100; i++)
{
    if (i % 2 == 0)
    {
        console.log(i);
    }
}
for (let i = 0; i <= 100; i++)
{
    if (i % 2 != 0)
    {
        console.log(i);
    }
}
for (let i = 0; i <= 100; i++)
{
    if (isPrime(i))
    {
        console.log(i);
    }
}
let sum = 0;
for (let i = 0; i <= 100; i++)
{
    sum += i
}
console.log(`The sum of all numbers from 0 to 100 is ${sum}.`)
let sumEven = 0;
let sumOdd = 0;
for (let i = 0; i <= 100; i++)
{
    if (i % 2 == 0)
    {
        sumEven += i
    }
    else
    {
        sumOdd += i
    }
}
console.log(`The sum of all evens from 0 to 100 is ${sumEven}. And the sum of all odds from 0 to 100 is ${sumOdd}.`)
let arr = []
for (let i = 0; i < 5; i++)
{
    arr[i] = Math.round(Math.random() * 10)
}
console.log(arr)