import serial

s = serial.Serial('COM5')
res = s.read(5)
print(res)
