import random
class Vehicle:
    def __init__(self,Make, Model, Year, w ,t=0 , n=False):
        self.Make = Make
        self.Model = Model
        self.Year = Year
        self.Weight = w
        self.NeedsMaintenance = n
        self.TripsSinceMaintenance = t
    def Vehicle_spec(self):
        return " make  : {}\n Model : {}\n Year  : {}\n Weight: {}kg".format(self.Make,self.Model,self.Year,self.Weight)
    def Vehicle_status(self):
        return "NeedsMaintenance: {}\n TripsSinceMaintenance: {}".format(self.NeedsMaintenance,self.TripsSinceMaintenance)
    def repair(self):
        self.NeedsMaintenance = False
        self.TripsSinceMaintenance = 0
class Cars(Vehicle):
    def __init__(self, Make, Model, Year, w, t=0, n=False):
        super().__init__(Make, Model, Year, w, t, n)
        self.driver = True
        self.stop = False
        if self.TripsSinceMaintenance >= 100:
            self.NeedsMaintenance = True
            self.driver = False
            self.stop = True
        else:
            self.driver = True
            self.stop = False
    def drive(self):
        if self.NeedsMaintenance == True:
            self.driver = False
            self.stop = True
        else:
            self.TripsSinceMaintenance += 1
            self.driver = True
            self.stop = False
    def stops(self):
        self.driver = False
        self.stop = True
class Planes(Vehicle):
    def __init__(self, Make, Model, Year, w, t=0, n=False):
        super().__init__(Make, Model, Year, w, t, n)
        self.flying = True
        self.landing = False
        if self.TripsSinceMaintenance >= 100:
            self.NeedsMaintenance = True
            self.flying = False
            self.landing = True
        else:
            self.flying = True
            self.landing = False
    def check(self):
        if self.NeedsMaintenance == True:
            print('plane cant fly until its repaired!!!')
    def fly(self):
        if self.NeedsMaintenance == True:
            print('plane cant fly until its repaired!!!')
            self.flying = False
            self.landing = True
        else:
            self.TripsSinceMaintenance += 1
            self.flying = True
            self.landing = False
    def landings(self):
        self.flying = False
        self.landing = True


def print_car1():
    print('='*27)
    print(Cars1.Vehicle_spec(), '\n', Cars1.Vehicle_status())
    print('='*27)
def print_car2():
    print('=' * 27)
    print(Cars2.Vehicle_spec(), '\n', Cars2.Vehicle_status())
    print('='*27)
def print_car3():
    print('='*27)
    print(Cars3.Vehicle_spec(), '\n', Cars3.Vehicle_status())
    print('='*27)
def print_plane():
    print('=' * 27)
    print(plane.Vehicle_spec(), '\n', plane.Vehicle_status())
    plane.check()
    print('='*27)

value = random.randint(0 , 100)
Cars1 = Cars('Mercedes-Benz', 'A-class', 2019, 1.555, value)
Cars2 = Cars('Tesla', 'Model X', 2020, 2.509, value)
Cars3 = Cars('ferrari', '458 spider', 2016, 2.538, value)
plane = Planes('Boeing', '737-400', 2017, 41.413, value)


print_car1()
print_car2()
print_car3()
print_plane()

