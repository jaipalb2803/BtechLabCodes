
function display() {
    console.log("You clicked on the Button!");
} 
document.getElementById("clickButton").addEventListener("click", display);

document.getElementById("clickButton").removeEventListener("click", display); 