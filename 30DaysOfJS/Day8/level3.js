const personAccount = {
    firstName: "Michael",
    lastName: "Filbert",
    incomes: {
        salary: 2000,
        bonus: 500,
        other: 1000
    },
    expenses: {
        houseExpenses: 2400,
        fuel: 300,
        eating: 200,
        other: 100
    },
    totalIncome: function () {
        let sum = 0
        let arr = Object.values(this.incomes)
        for (let i = 0; i < arr.length; i++) {
            sum += arr[i]
        }
        return sum
    },
    totalExpenses: function () {
        let sum = 0
        let arr = Object.values(this.expenses)
        for (let i = 0; i < arr.length; i++) {
            sum += arr[i]
        }
        return sum
    },
    addIncome: function (a) {
        this.incomes.other += a
    },
    addExpense: function (a) {
        this.expenses.other += a
    },
    accountBalance: function () {
        return this.totalIncome() - this.totalExpenses()
    }
}
const users = [
    {
        _id: 'ab12ex',
        username: 'Alex',
        email: 'alex@alex.com',
        password: '123123',
        createdAt: '08/01/2020 9:00 AM',
        isLoggedIn: false
    },
    {
        _id: 'fg12cy',
        username: 'Asab',
        email: 'asab@asab.com',
        password: '123456',
        createdAt: '08/01/2020 9:30 AM',
        isLoggedIn: true
    },
    {
        _id: 'zwf8md',
        username: 'Brook',
        email: 'brook@brook.com',
        password: '123111',
        createdAt: '08/01/2020 9:45 AM',
        isLoggedIn: true
    },
    {
        _id: 'eefamr',
        username: 'Martha',
        email: 'martha@martha.com',
        password: '123222',
        createdAt: '08/01/2020 9:50 AM',
        isLoggedIn: false
    },
    {
        _id: 'ghderc',
        username: 'Thomas',
        email: 'thomas@thomas.com',
        password: '123333',
        createdAt: '08/01/2020 10:00 AM',
        isLoggedIn: false
    }
];

const products = [
    {
        _id: 'eedfcf',
        name: 'mobile phone',
        description: 'Huawei Honor',
        price: 200,
        ratings: [
            { userId: 'fg12cy', rate: 5 },
            { userId: 'zwf8md', rate: 4.5 }
        ],
        likes: []
    },
    {
        _id: 'aegfal',
        name: 'Laptop',
        description: 'MacPro: System Darwin',
        price: 2500,
        ratings: [],
        likes: ['fg12cy']
    },
    {
        _id: 'hedfcg',
        name: 'TV',
        description: 'Smart TV:Procaster',
        price: 400,
        ratings: [{ userId: 'fg12cy', rate: 5 }],
        likes: ['fg12cy']
    }
]