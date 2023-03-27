// var grade = ""
// let scores = 95
// if (scores >= 0 && scores <= 49)
// {
//     grade = "F"
// }
// else if (scores >= 50 && scores <= 59)
// {
//     grade = "D"
// }
// else if (scores >= 60 && scores <= 69)
// {
//     grade = "C"
// }
// else if (scores >= 70 && scores <= 89)
// {
//     grade = "B"
// }
// else
// {
//     grade = "A"
// }
// console.log(grade)
// let month = 5
// let season = ""
// switch (month)
// {
//     case 9:
//     case 10:
//     case 11:
//         season = "Autumn"
//         break
//     case 12:
//     case 1:
//     case 2:
//         season = "Winter"
//         break
//     case 3:
//     case 4:
//     case 5:
//         season = "Spring"
//         break
//     default:
//         season = "Summer"
//         break;
// }
// console.log(season)
let date = "sAtURdaY"
date = date.toLowerCase()
switch (date)
{
    case "monday":
    case "tuesday":
    case "wednesday":
    case "thursday":
    case "friday":
        console.log(`${date.charAt(0).toUpperCase() + date.slice(1)} is a working day`)
        break
    case "saturday":
    case "sunday":
        console.log(`${date.charAt(0).toUpperCase() + date.slice(1)} is a weekend`)
        break
}