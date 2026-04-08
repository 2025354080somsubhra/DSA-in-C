#Q-29
import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __sub__(self, p):
        d = math.sqrt((self.x - p.x)**2 + (self.y - p.y)**2)
        return d

    def __ge__(self, p):
        d1 = math.sqrt(self.x*self.x + self.y*self.y)
        d2 = math.sqrt(p.x*p.x + p.y*p.y)
        if d1 >= d2:
            return True
        else:
            return False


p1 = Point(3, 4)
p2 = Point(6, 8)

print("Distance =", p1 - p2)

if p1 >= p2:
    print("P1 is farther or equal from origin")
else:
    print("P2 is farther from origin")


# Q-30
class InvalidMarksException(Exception):
    pass


class Student:
    def __init__(self, name, roll, p, c, m):
        if p < 0 or p > 100 or c < 0 or c > 100 or m < 0 or m > 100:
            raise InvalidMarksException

        self.name = name
        self.roll = roll
        self.p = p
        self.c = c
        self.m = m

    def avg(self):
        return (self.p + self.c + self.m) / 3

    def show(self):
        print("Name:", self.name)
        print("Roll:", self.roll)
        print("Physics:", self.p)
        print("Chemistry:", self.c)
        print("Math:", self.m)
        print("Average:", self.avg())


try:
    name = input("Enter name: ")
    roll = int(input("Enter roll no: "))
    p = int(input("Enter physics marks: "))
    c = int(input("Enter chemistry marks: "))
    m = int(input("Enter math marks: "))

    s1 = Student(name, roll, p, c, m)
    s1.show()

except InvalidMarksException:
    print("Marks should be between 0 and 100")
except:
    print("Invalid input")

# Q-31
from abc import ABC, abstractmethod

class Account(ABC):
    def __init__(self, acc, name, bal):
        self.__acc = acc
        self.__name = name
        self.__bal = bal

    @abstractmethod
    def calculate_interest(self):
        pass

    def get_bal(self):
        return self.__bal


class Savings(Account):
    def calculate_interest(self):
        return self.get_bal() * 0.04


class Current(Account):
    def calculate_interest(self):
        return self.get_bal() * 0.02


a1 = Savings(101, "Rohit", 10000)
a2 = Current(102, "Aman", 10000)

print("Savings Interest:", a1.calculate_interest())
print("Current Interest:", a2.calculate_interest())