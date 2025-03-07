document.getElementById("getDataButton").addEventListener("click", getData);

function getData() {
   const userName = document.getElementById("username").value;

   fetch(`http://api.github.com/users/${userName}/repos`)
      .then((response) => response.json())
      .then((data) => {
         console.log(data);
         document.getElementById("displayData").innerText = JSON.stringify(data);
      })
      .catch((error) => console.log(error));
}
