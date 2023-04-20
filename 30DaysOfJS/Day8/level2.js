const users = {
    Alex: {
      email: 'alex@alex.com',
      skills: ['HTML', 'CSS', 'JavaScript'],
      age: 20,
      isLoggedIn: false,
      points: 30
    },
    Asab: {
      email: 'asab@asab.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'Redux', 'MongoDB', 'Express', 'React', 'Node'],
      age: 25,
      isLoggedIn: false,
      points: 50
    },
    Brook: {
      email: 'daniel@daniel.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'React', 'Redux'],
      age: 30,
      isLoggedIn: true,
      points: 50
    },
    Daniel: {
      email: 'daniel@alex.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'Python'],
      age: 20,
      isLoggedIn: false,
      points: 40
    },
    John: {
      email: 'john@john.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'React', 'Redux', 'Node.js'],
      age: 20,
      isLoggedIn: true,
      points: 50
    },
    Thomas: {
      email: 'thomas@thomas.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'React'],
      age: 20,
      isLoggedIn: false,
      points: 40
    },
    Paul: {
      email: 'paul@paul.com',
      skills: ['HTML', 'CSS', 'JavaScript', 'MongoDB', 'Express', 'React', 'Node'],
      age: 20,
      isLoggedIn: false,
      points: 40
    }
}
let maxSkill = 0
let name = {}
for (i in users) 
{
    if (users[i].skills.length > maxSkill)
    {
        maxSkill = users[i].skills.length
        name = i
    }
}
// console.log(name)
let countLog = 0
let count50P = 0
for (i in users)
{
    if (users[i].isLoggedIn == true) countLog++
    if (users[i].points >= 50) count50P++
}
// console.log("Logged in: " + countLog)
// console.log("Over 50: " + count50P)
let countMERN = 0
// console.log("MERN stack developer: ")
for (i in users)
{
    if (users[i].skills.includes("MongoDB", "Express", "React", "Node"))
    {
        // console.log(i)
    }
}
const copyUsers = Object.assign({}, users)
copyUsers.Michael = {}
const allKeys = Object.keys(copyUsers)
// console.log(allKeys)
const allValues = Object.values(copyUsers)
console.log(allValues)