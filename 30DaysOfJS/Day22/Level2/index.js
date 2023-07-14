const liTags = document.getElementsByTagName('li')
for (let i = 0; i < liTags.length; i++)
{
    if (liTags[i].textContent.includes("Done"))
    {
        liTags[i].style.backgroundColor = '#21bf73'
    }
    else if (liTags[i].textContent.includes("Ongoing"))
    {
        liTags[i].style.backgroundColor = '#fddb3a'
    }
    else
    {
        liTags[i].style.backgroundColor = '#fd5e53'
    }
}
//----------------------------------------------------------------
function checkTime(i)
{
    if (i < 10) i = "0" + i
    return i
}
function dateTimeSetting()
{
    const monthNames = ["January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"
];
    const today = new Date()
    var dateTime = monthNames[today.getMonth()] + ' ' + today.getDate() + ', ' + today.getFullYear() + ' ' + today.getHours() + ':' + checkTime(today.getMinutes()) + ':' + checkTime(today.getSeconds())
    const dtText = document.querySelector('#datetime')
    dtText.textContent = dateTime
}
setInterval(dateTimeSetting, 1000)
function colorChange()
{
    const characters = '0123456789abcdef'
    let color1 = '#'
    let color2 = '#'
    for (let i = 0; i < 6; i++)
    {
        color1 += characters[Math.floor(Math.random() * 16)]
        color2 += characters[15 - Math.floor(Math.random() * 16)]
    }
    const number = document.querySelector('b')
    number.style.color = color1
    const dateTime = document.querySelector('#datetime')
    dateTime.style.backgroundColor = color2
}
setInterval(colorChange, 1000)