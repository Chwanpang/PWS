import serial
from time import sleep
import numpy as np
import matplotlib.pyplot as plt
import keyboard
y=[0]
x=[0]
input()
ser = serial.Serial('COM5', baudrate=115200)
while True:
    if float(str(ser.readline())[2:-5])<0:
        y.append(0)
    else:
        y.append(float(str(ser.readline())[2:-5]))
    x.append(x[-1]+0.1)
    print("hey")
    try:
        if keyboard.is_pressed('space'):print("Aborted");break
    except:
        sleep(0.1)
        print("hey")
plt.plot(x,y)
plt.title('Motortest')
plt.xlabel('Tijd')
plt.ylabel('Newton')
plt.show()