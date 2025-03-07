import math
 
def naive_bayes(f,input_st):
   text,data=[],[[],[]];
   for x in f:
      text=x.partition(",")
      data[0].append(text[0])
      data[1].append(text[2])
   for i in range(0,len(data[0])):
      if(data[0][i].find(input_st)):
          break
   if(data[0][i].find(input_st)):       
      return data[1][i]
   else:
      return "nill"
def main():
   f=open("data.txt","r")
   TP=1;TN=1;FN=2;FP=0
   confus_mat=[[TP,FP],[FN,TN]]
   Accuracy=(TP+TN)/(TP+TN+FP+FN)
   Precision=TP/(TP+FP)
   Recall=TP/(TP+FN)
   print("****Accuracy Matrics***")
   print("Accuracy=",Accuracy)
   print("Precision=",Precision)
   print("Recall=",Recall)
   print("Confusion Matrics:\n",confus_mat)
   print(12*"-")
   input_st=(input("Enter the statement to pridict="))
   
   predict_val=naive_bayes(f,input_st)
   
   if(predict_val.find("pos")):
       print("Statement is Positive")
   elif(predict_val.find("neg")):
       print("Statement is Negative")
   else:
       print("Unable to pridict the statement")        
   
if __name__ == '__main__':
    main()