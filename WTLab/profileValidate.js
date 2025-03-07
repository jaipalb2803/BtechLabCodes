function validateform(){  

    const usrname=document.getElementById("usrname").value;
    const pwd=document.getElementsById("pwd").value;
    const phNo=document.getElementById("phnnumber").value;
    const email=document.getElementById("email").value;

    if (usrname==null || usrname=="")  
      alert("userame can't be blank");   
    else if(pwd.length<6)
      alert("Password must be atleast 6 characters long."); 
    else if(email.indexOf("@")<1)
      alert("Invalid email ID");   
    else if(phNo.length!=10)
      alert("Invalid Phone Number");    
    else 
      alert("Sucessfully submitted");    
} 
