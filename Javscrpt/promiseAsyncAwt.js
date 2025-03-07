
const p = new Promise(function (resolve, reject) {
    setTimeout(() => {
       resolve();
    }, 2000);
 });
 
 console.log(p);
 
 setTimeout(() => {
    console.log(p);
 }, 3000);

 /**
function onSuccess() {
   console.log("Success!");
}

function onError() {
   console.log("Error!");
}

const promise = new Promise(function (resolve, reject) {
   setTimeout(() => {
      resolve();
   }, 2000);
});

promise.then(onSuccess);
promise.catch(onError); 

*/

function getPromise() {
    return new Promise((resolve) => {
       setTimeout(resolve, 2000);
    });
 }
 
 function logA() {
    console.log("A");
 }
 
 function logB() {
    console.log("B");
 }
 
 function logCAndThrow() {
    console.log("C");
    throw new Error();
 }
 
 function catchError() {
    console.log("Error!");
 }
 getPromise().then(logA).then(logB).then(logCAndThrow).catch(catchError);


/* async function display() {
    return 1;
 }
 
 console.log(display());
 
 display()
    .then(() => console.log("Promise is resolved!"))
    .catch(() => console.log("Promise is rejected!")); */
 
  /*  const getData = () =>
    new Promise(function (resolve, reject) {
       setTimeout(() => {
          resolve("My Data");
       }, 2000);
    });
 async function display() {
    const userData = await getData();
    console.log(userData);
 }
 display(); */
 