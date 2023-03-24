let sentence1 = 'Love is the best thing in this world. Some found their love and some are still looking for their love.'
console.log((sentence1.toLowerCase().match(/love/g) || []).length)

const sentence2 = 'You cannot end a sentence with because because because is a conjunction'
console.log((sentence2.match(/because/g) || []).length)

const sentence = '%I $am@% a %tea@cher%, &and& I lo%#ve %te@a@ching%;. The@re $is no@th@ing; &as& mo@re rewarding as educa@ting &and& @emp%o@weri@ng peo@ple. ;I found tea@ching m%o@re interesting tha@n any ot#her %jo@bs. %Do@es thi%s mo@tiv#ate yo@u to be a tea@cher!? %Th#is 30#Days&OfJavaScript &is al@so $the $resu@lt of &love& of tea&ching'
console.log(sentence.replace(/[%@$;#&!?]/gi, ""))

const text = 'He earns 5000 euro from salary per month, 10000 euro annual bonus, 15000 euro online courses per month.'
var salary = text.match(/\d+/g)
let total = 0
salary.forEach(i => {
    total += +i
});
console.log(total)