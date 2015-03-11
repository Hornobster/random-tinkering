import turtle
import random

def dragonIteration(string):
	rslt = ""
	
	i = 0
	while i < len(string):
		if string[i] == 'X':
			rslt += "X+YF"
		elif string[i] == 'Y':
			rslt += "FX-Y"
		else:
			rslt += string[i]
		i += 1
	
	return rslt
	
def draw(myTrt, string, angle):
	myTrt.hideturtle()
	myTrt.pu()
	myTrt.setposition(0,0)
	myTrt.pd()
	
	i = 0
	while i < len(string):
		#myTrt.color(random.random(), random.random(), random.random())
		
		if string[i] == 'F':
			myTrt.forward(1)
		elif string[i] == '+':
			myTrt.right(angle)
		elif string[i] == '-':
			myTrt.left(angle)
		
		i += 1

wn = turtle.Screen()

myTrt = turtle.Turtle()
myTrt.penup()
myTrt.setposition(0,0)
myTrt.pendown()
myTrt.speed("fastest")

string = "FX"

angle = 90

iterations = 15

i = 0
while i < iterations:
	string = dragonIteration(string)
	print(i)
	i+=1
print(len(string))

draw(myTrt, string, angle)

wn.exitonclick()

