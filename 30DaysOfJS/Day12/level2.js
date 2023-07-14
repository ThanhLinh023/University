const tenMostFrequentWords = (text, num) => {
    const result = []
    const words = text.match(/\b[a-zA-Z]{1,}\b/g)
    const wordSet = new Set(words)
    for (const i of wordSet)
    {
        const repeatWord = words.filter((word) => word === i)
        result.push({word: i, count: repeatWord.length})
    }
    return result.sort((a,b) =>
    {
        if (a.count < b.count) return 1
        if (a.count > b.count) return -1
        return 0
    }).reduce((a, b) =>
    {
        if (a.length < num) 
        {
            a.push(b)
        }
        return a
    }, [])
}
let paragraph = `I love teaching. If you do not love teaching what else can you love. I love Python if you do not love something
which can give you all the capabilities to develop an application what else can you love.`
console.log(tenMostFrequentWords(paragraph, 10))