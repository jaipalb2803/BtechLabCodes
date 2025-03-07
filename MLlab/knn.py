import math

def classify(points,p,k=3):
    distance = []
    for key in points:
        for values in points[key]:
            ed = math.sqrt((values[0]-p[0])**2 + (values[1]-p[1])**2)
            distance.append((ed,key))
    distance = sorted(distance)[:k]
    freq1 = 0
    freq2 = 0
    for t in distance:
        if t[1] == 0:
            freq1 += 1
        if t[1] == 1:
            freq2 += 1
    return 0 if freq1>freq2 else 1

def main():
    points = {
        0:[(1,12),(2,5),(3,6),(3,10),(3,5.8),(2,11),(2,9),(1,7)],
        1:[(5,3),(3,2),(1.5,9),(7,2),(6,1),(3.8,1),(5.6,4),(4,2),(2,5)]
    }
    
    # p = (x,y)
    # print(type(p))
    p = (2.5,1)
    k = int(input("K :"))
    # k = 5
    print("The point is classified into the group {}".format(classify(points,p,k)))

if __name__ == '__main__':
    main()