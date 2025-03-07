
class Animal {
    constructor(name) {
       this.name = name;
    }
    walk() {
       console.log(this.name + " can Walk!");
    }
    eat() {
       console.log(this.name + " can Eat!");
    }
    sleep() {
       console.log(this.name + " can Sleep!");
    }
 }
 
 const a1 = new Animal("Lion");
 console.log(a1);
 a1.eat();

 /*class Animal {
   constructor(name) {
      this.name = name;
   }
   walk() {
      console.log(this.name + " can Walk!");
   }
   eat() {
      console.log(this.name + " can Eat!");
   }
   sleep() {
      console.log(this.name + " can Sleep!");
   }
}

class Human extends Animal {
   constructor(name) {
      super(name);
   }
   think() {
      console.log(this.name + "can Think!");
   }
}

const a1 = new Animal("Lion");
console.log(a1);
a1.eat();

const h1 = new Human("Jayesh");
console.log(h1);
h1.eat();
 */

/*class Animal {
   constructor(name) {
      this.name = name;
   }
   walk() {
      console.log(this.name + " can Walk!");
   }
   eat() {
      console.log(this.name + " can Eat!");
   }
   sleep() {
      console.log(this.name + " can Sleep!");
   }
}

class Human extends Animal {
   constructor(name) {
      super(name);
   }
   think() {
      console.log(this.name + "can Think!");
   }
}

class Bird extends Human {
   constructor(name) {
      super(name);
   }
   fly() {
      console.log(this.name + "  can Fly!");
   }
}

const a1 = new Animal("Lion");
console.log(a1);
a1.eat();

const h1 = new Human("Jayesh");
console.log(h1);
h1.eat();

const b1 = new Bird("Pigeon");
console.log(b1);
b1.think();
b1.eat(); */
