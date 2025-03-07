
console.log(this);

var name = "Spoken Tutorials!";
console.log(this.name);

/*const empDetails = {
    name: "Jayesh",
    designation: "Instructor",
    displayName: function () {
       console.log(this.name);  },
 };
empDetails.displayName();*/

 /*const lang = ["HTML", "CSS", "JS"];
const empDetails = {
   name: "Jayesh",
};
function display(languages) {
   console.log(`${this.name} knows ${languages}`);
}
display.call(empDetails, lang);
display.call(empDetails, lang[0], lang[1], lang[2]);*/

const lang = ["HTML", "CSS", "JS"];
const empDetails = {
   name: "Jayesh",
};
function display(languages) {
   console.log(`${this.name} knows ${languages}`);
}
const returnedFn = display.bind(empDetails, lang); 
console.log(returnedFn);
returnedFn();

/*const lang = ["HTML", "CSS", "JS"];
const empDetails = {
   name: "Jayesh!",
};
function display(lan1, lan2, lan3) {
   console.log(`${this.name} knows ${lan1}, ${lan2} and ${lan3}`);
}
display.apply(empDetails, lang);
 */

function Student(name) {
    this.stuName = name;
 }
 
 const s1 = new Student("Jayesh"); console.log(s1);