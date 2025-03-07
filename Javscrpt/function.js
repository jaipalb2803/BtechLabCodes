//Basic fuction
function add() {
    console.log(1+2);
    return true;
}

add();
console.log(add());

//Parameterized function
function sub(a) {
    return a - 1;
}

var result  = sub(6);
console.log(result);

//Function as a value 
var mul = function () {
    return true;
};

var result = mul();
console.log(result);

//Function as a argument/Parameter
function d1() {
    console.log('Spoken');
}

function d2() {
    console.log('Tutorials');
}

function d3() {
    console.log('on JS');
}

function display(fn, fn1, fn2) {
    fn();
    fn1();
    fn2();
}

display(d1, d2, d3);

//Function as a property
var student = {
    marks: function () {
        return 100;
    },
};

var result = student.marks();
console.log(result);

//Function Arguments
function marks() {
    for (var i = 0; i < arguments.length; i++) {
        console.log(arguments[i]);
    }
}

marks(87, 78, 90, 81);

//Constructor function
function Student(stuName, stuAge) {
    this.name = stuName;
    this.age = stuAge;
}

var s1 = new Student("S1", 10);
var s2 = new Student("S2", 11);
console.log(s1);
console.log(s2);


