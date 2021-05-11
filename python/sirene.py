import serial
import logging
import sys
import os
import subprocess
from pygame import mixer

def loop():
    mixer.init()
    with  serial.Serial('/dev/ttyUSB1') as ser:  # open serial port
        while True:
            try:
                line = ser.read()   # read a '\n' terminated line
                if line == b'0':
                    print('off')
                    mixer.music.stop()
                if line == b'1':
                    print('on')
                    mixer.music.load('sirene.wav')
                    mixer.music.play()
            except KeyboardInterrupt:
                print('Interrupted')
                try:
                   sys.exit(0)
                except SystemExit:
                   os._exit(0)    
            except:
              logging.exception("message")
loop()
