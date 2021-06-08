import serial

s = serial.Serial('COM4')
res = s.read(5)
print(res)
