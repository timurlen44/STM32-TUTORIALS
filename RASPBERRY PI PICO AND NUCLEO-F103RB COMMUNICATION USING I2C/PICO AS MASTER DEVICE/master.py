
from machine import Pin
import utime
from machine import I2C
import utime
import machine

i2c = I2C(0, sda=machine.Pin(20), scl=machine.Pin(21), freq=100000)
I2C_ADDR_LIST = i2c.scan()
I2C_ADDR = 0


led = Pin('LED', Pin.OUT)
led.low()
push_button = Pin(13, Pin.IN)

low_data = "0000"
high_data = "1000"
if I2C_ADDR_LIST:
    I2C_ADDR = I2C_ADDR_LIST[0]
    print(I2C_ADDR)
else:
    while(True):
        print("ADDRESS IS NOT FOUND")
        utime.sleep(1)


while True:
    if(push_button.value() == True):
        led.high()
        i2c.writeto(I2C_ADDR, high_data)
        print("high")
        while(push_button.value() == True):
            wait = 1
        i2c.writeto(I2C_ADDR, low_data)
        led.low()
        print("high")



