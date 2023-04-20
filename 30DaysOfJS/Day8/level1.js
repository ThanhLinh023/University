const dog = {}
dog.name = "Mickey"
dog.legs = 4
dog.color = "Black"
dog.age = 2
dog.bark = "woof woof"
dog.breed = "Bergie"
dog.getInfo = function() {
    console.log("Dog's name: " + this.name)
    console.log("Dog's leg: " + this.leg)
    console.log("Dog's color: " + this.color)
    console.log("Dog's age: " + this.age)
    console.log("Breed: " + this.breed)
    console.log("Bark: " + this.bark)
}
dog.getInfo()