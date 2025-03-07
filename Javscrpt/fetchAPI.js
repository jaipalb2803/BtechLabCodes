fetch("http://api.github.com/users/jayeshkattar")
   .then((response) => {
      console.log(response);
      return response.json();
   })

.then((data) => console.log(data))
.catch((error) => console.log(error));