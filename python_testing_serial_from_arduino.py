import serial
import time

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
    ser.flush()
    
    while True:
        val = input("Enter string: ")
        input_string = val + '\n'
        ser.write(input_string.encode('utf-8'))
        
        #if ser.in_waiting > 0:
        #line = ser.readline().decode('utf-8').rstrip()
        #print(line)
        time.sleep(1)