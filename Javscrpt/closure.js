
const count = 1;
function outer(x) {
    return function inner(y) {
        return x + y;
    };
}

const outerReturnedValue = outer(4);
const innerReturnedValue = outerReturnedValue(5);

console.dir(outerReturnedValue);

console.log(innerReturnedValue);

const sum = count + innerReturnedValue;

console.log("Sum is ", sum);
