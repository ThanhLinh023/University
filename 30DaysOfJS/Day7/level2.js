function showDateTime()
{
    let date = new Date
    let d = date.getDate() < 10 ? '0' + date.getDate() : date.getDate()
    let m = date.getMonth() < 10 ? '0' + date.getMonth() : date.getMonth()
    let hour = date.getHours() < 10 ? '0' + date.getHours() : date.getHours()
    let minute = date.getMinutes() < 10 ? '0' + date.getMinutes() : date.getMinutes()
    console.log(d + '/' + m + '/' + date.getFullYear() + ' ' + hour + ':' + minute)
}
function solveEquation(a = 0, b = 0, c = 0)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                console.log("Many solutions")
            }
            else
            {
                console.log("No solutions")
            }
        }
        else
        {
            console.log("One solution x = " + -c / b)
        }
    }
    else
    {
        let delta = b * b - 4 * a * c
        if (delta < 0)
        {
            console.log("No solution")
        }
        else if (delta == 0)
        {
            console.log("Dual solutions x = " + -b / (2 *a))
        }
        else
        {
            console.log("Solutions x1 = " + (-b + Math.sqrt(delta)) / (2 * a))
            console.log("Solutions x2 = " + (-b - Math.sqrt(delta)) / (2 * a))
        }
    }
}
swapValue = (a, b) => {
    console.log("Before swapping: x = " + a + ", y = " + b)
    let temp = a
    a = b
    b = temp
    console.log("After swapping: x = " + a + ", y = " + b)
}
reverseArray = arr => {
    let temp = []
    for (i in arr)
    {
        temp.unshift(arr[i])
    }
    return temp
}
