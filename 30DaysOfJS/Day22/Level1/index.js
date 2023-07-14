function isPrime(n)
{
    for (let i = 2; i <= Math.sqrt(n); i++)
    {
        if (n % i === 0) return false
    }
    return true
}
let item 
const container = document.querySelector('.numbers')
for (let i = 0; i <= 101; i++)
{
    item = document.createElement('div')
    item.style.height = '60px'
    item.style.width = '70px'
    item.style.marginRight = '0.2em'
    item.style.marginBottom = '0.2em'
    item.style.font = '500px'
    item.style.textAlign = 'center'
    item.style.paddingTop = '20px'
    item.style.right = '10px'
    item.style.fontSize = '30px'
    item.style.color = 'white'
    item.style.fontWeight = '500'
    item.textContent = i.toString()
    item.style.flexBasis = '15%'
    if (i % 2 === 0)
    {
        item.style.backgroundColor = '#21bf73'
    }
    else 
    {
        item.style.backgroundColor = '#fddb3a'
    }
    if (isPrime(i))
    {
        item.style.backgroundColor = '#fd5e53'
    }
    container.appendChild(item)
}