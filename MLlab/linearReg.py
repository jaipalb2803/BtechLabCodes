import math

def linear_Regression(x,y,n):
    sum_x=float(sum(x))
    sum_y=float(sum(y))
    sum_sq_x=float(sum(x_i**2 for x_i in x))
    sum_xy=float(sum( x[i] * y[i] for i in range(n)))
    """print(sum_x)
    print(sum_y)
    print(sum_xy)
    print(sum_sq_x)"""
    
    m=((n * sum_xy) - (sum_x * sum_y)) / ((n * sum_sq_x) - (sum_x)**2)
    c=((sum_y * sum_sq_x) - (sum_x * sum_xy)) / ((n * sum_sq_x) - (sum_x)**2)
    
    y_pred=[m*x_i + c for x_i in x]
    rmse=(sum((y_i - y_pred)**2 for y_i,y_pred in zip(y,y_pred))/n)**0.5
    
    return m,c,y_pred,rmse    
   
def main():
  n=int(input("Enter no of inputs="))
  print("Give input data points:")
  x,y=[],[]
  for i in range(0,n):
      print("(x",i+1,",y",i+1,")=",end="")
      x_val,y_val=input().split()
      x.append(int(x_val))
      y.append(int(y_val))
      
  m,c,y_pred,rmse=linear_Regression(x,y,n)
  print("Equation y={:.2f}x+{:.2f}".format(m,c))
  print("Predicted value=",y_pred)
  print("Root mean squared error for the prediction={:.2f}".format(rmse))    

if __name__ == '__main__':
    main()
    
""" 
from sklearn.linear_model import LinearRegression 
import matplotlib.pyplot as plt
import numpy as np 
x=np.array([[1],[2],[3],[4]])
y=np.array([5,6,7,8])
lr=LinearRegression().fit(x,y)
y_new=lr.predict(x)

plt.scatter(x,y,color="red",label="data points")
plt.plot(x,y_new,label="LinearRegression")
plt.xlabel('X-Axis')
plt.ylabel('Y-Axis')
plt.legend()
plt.show()   """