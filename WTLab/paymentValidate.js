function validateform(){  

    const crdNo= document.getElementById("crdNo").value;
    const expDate=document.getElementById("expDate").value;
    const cvv=document.getElementById("cvv").value;
    const cardHolderName=document.getElementById("cardHolderName").value;
   
    if (crdNo.length<10)  
      alert("Invalid CardNumber");   
    else if(expDate.indexOf("/")<1)
      alert("Invalid Expire date");  
    else if(cvv.length>4)
      alert("Invalid CVV");
    else if (cardHolderName==null || cardHolderName=="")  
      alert("cardholderName can't be blank");    
    else 
      alert("Payment Sucessfull");    
} 
