const showKey = document.querySelector('.showKey')
const key = document.querySelector('.key')
const keyName = document.querySelector('.keyName')
showKey.style.display = 'none'
document.body.addEventListener('keypress', e =>
{
    keyName.textContent = 'You pressed '
    let newB = document.createElement('b')
    newB.textContent = checkKeyName(e.keyCode)
    newB.style.color = '#21bf73'
    keyName.appendChild(newB)
    key.textContent = e.keyCode
    showKey.style.display = 'block'
})
function checkKeyName(i)
{
    if (i === 13)
    {
        return 'Enter'
    }
    else if (i === 32)
    {
        return 'Space'
    }
    else
    {
        return String.fromCharCode(i)
    }
}