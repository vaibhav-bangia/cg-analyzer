credits = input("Enter Credits String : ") 
# credits  = "4 4 4 4 2 2"
credits = credits.split(" ")
grades = input("Enter Grades String: ")
grades = grades.split(" ")
credits_map = {
    "O":10,
    "A+":9,
    "A":8,
    "B+":7,
    "B":6,
    "C":5,
    "P":4,
    "F":0
}
# calculate sum of credits 
total_credits = 0 
for i in range(len(credits)):
    total_credits+=int(credits[i])

sum = 0  
for i in range(len(grades)):
    sum += credits_map[grades[i]]*int(credits[i])

result  = sum / total_credits 

print(f"cgpa :  {result}")
