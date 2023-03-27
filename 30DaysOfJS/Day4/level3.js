let month = "FebRUARy"
month = month.toLowerCase()

switch (month)
{
    case "january":
    case "march":
    case "may":
    case "july":
    case "august":
    case "october":
    case "december":
        console.log(`${month.charAt(0).toUpperCase() + month.slice(1)} has 31 days`)
        break
    case "february":
    case "april":
    case "june":
    case "september":
    case "november":
        console.log(`${month.charAt(0).toUpperCase() + month.slice(1)} has 30 days`)
        break
    default:
        console.log(`${month.charAt(0).toUpperCase() + month.slice(1)} has 28 days`)
        break
}
let year = 2024
if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
{
    console.log("Leap year")
}