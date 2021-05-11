import serial
import logging
import sys
import os
import subprocess

def loop():
    with  serial.Serial('/dev/ttyUSB0') as ser:  # open serial port
        while True:
            try:
                line = ser.read()   # read a '\n' terminated line
                if line == b'0':
                    print('muted')
                    subprocess.Popen(('amixer', '-D', 'pulse', 'set', 'Capture', 'nocap'), stdout=subprocess.PIPE)
                if line == b'1':
                    print('on air!')
                    subprocess.Popen(('amixer', '-D', 'pulse', 'set', 'Capture', 'cap'), stdout=subprocess.PIPE)
            except KeyboardInterrupt:
                print('Interrupted')
                try:
                   sys.exit(0)
                except SystemExit:
                   os._exit(0)    
            except:
              logging.exception("message")
loop()
