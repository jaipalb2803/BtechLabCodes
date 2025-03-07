function validateform(){  

    const usrname= document.getElementById("usrname").value;
    const pwd=document.getElementById("pwd").value;
    const confpwd=document.getElementById("confpwd").value;
   
    if (usrname==null || usrname=="")  
      alert("usename can't be blank");   
    else if(pwd.length<6)
      alert("Password must be at least 6 characters long.");  
    else if(pwd!=confpwd)
      alert("Password must be same.");    
    else 
      alert("Sucessfully submitted");    
} 
