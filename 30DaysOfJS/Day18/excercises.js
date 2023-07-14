const countriesAPI = 'https://restcountries.com/v2/all'
const catsAPI = 'https://api.thecatapi.com/v1/breeds'
// fetch(countriesAPI)
// .then(res => res.json())
// .then(data => 
//     {
//         for (i in data)
//         {
//             console.log(data[i].name + ' - ' + data[i].capital + ' - ' + data[i].languages + ' - ' + data[i].population + ' - ' + data[i].area)
//         }
//     })
// .catch(err => console.log(err))
const fetchData = async (url) =>
{
    try 
    {   
        const res = await fetch(url)
        const data = await res.json()
        return data
    }
    catch(err)
    {
        console.log(err)
    }
}
const catNames = fetchData(catsAPI)