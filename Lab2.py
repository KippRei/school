#Get student name
firstName = input("Type your first name and press enter: ")
lastName = input("Type your last name and press enter: ")

#Get student college info and goals
collegeName = input("Type your college name and press enter: ")
collegeMajor = input("Type your college major and press enter: ")
collegeGoal = input("Type your college goal and press enter: ")

#Get 1 current class info and expected grade
collegeClass = input("Type the name of one class you're enrolled in and press enter: ")
expGrade = input("Enter your expected grade in " + collegeClass + " then press enter: ")

#Print information to console
print("Hello " + firstName + " " + lastName + ".")
print("You currently attend " + collegeName + " and your major is " + collegeMajor + ".")
print("Your college goal is to complete a " + collegeMajor + " degree.")
print("You are enrolled in " + collegeClass + " and expect to receive a grade of " + expGrade + ".")