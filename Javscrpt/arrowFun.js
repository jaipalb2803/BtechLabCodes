function Display() {
    this.speed = 0;
    var self = this;
    var stop = setInterval(function () {
       self.speed++;
       console.log(self.speed);
    }, 300);
    setTimeout(function () {
       clearInterval(stop);
    }, 5000);
 }
 
 var d1 = new Display();

 /*
 function Display() {
   this.speed = 0;
   var stop = setInterval(() => {
      this.speed++;
      console.log(this.speed);
   }, 300);
   setTimeout(() => clearInterval(stop), 5000);
}

var d1 = new Display();
  */