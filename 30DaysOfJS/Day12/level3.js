const cleanText = text =>
{
    return text.replace(/[!?#$;%@&]/g, '')
}
let sentence = `%I $am@% a %tea@cher%, &and& I lo%#ve %tea@ching%;. There $is nothing; &as& mo@re rewarding as educa@ting &and& @emp%o@wering peo@ple. ;
I found tea@ching m%o@re interesting tha@n any other %jo@bs. %Do@es thi%s mo@tivate yo@u to be a tea@cher!?`
console.log(cleanText(sentence))
const mostFrequentWords = text =>
{
    const result = []
    const words = text.match(/\b[A-Za-z]{1,}\b/g)
    const wordSet = new Set(words)
    for (const i of wordSet)
    {
        const repeat = words.filter((a) => a === i)
        result.push({word: i, count: repeat.length})
    }
    return result.sort((a, b) =>
    {
        if (a.count > b.count) return -1
        if (a.count < b.count) return 1
        return 0
    }).reduce((a,b) =>
    {
        if (a.length < 3) a.push(b)
        return a
    }, [])
}
console.log(mostFrequentWords(cleanText(sentence)))