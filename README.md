# CAR_Wemos_based
CAR controlled by ESPnow protocol. ESP32 in the RC unit, Wemos ESP8266+motor control in the tank.

WemosD1 mini + Wemos motor Shield
Pinout:
D1 mini	GPIO	->  Motor Shield
D1	    5	        SCL
D2	    4	        SDA
RST	    RST       RST

Powering Wemos D1 mini:
  from USB or 5V pin (4-6V). It goes to ME6211 voltage regulator to power the ESP block. 
  3.3V is avialable as output also.
  
Analog pin: only ome (A0)
Digital pins: 8
  D0  IO                        GPIO 16
  D1  IO/SCL                    GPIO 5
  D2  IO/SDA                    GPIO 4
  D3  IO/10K pullup             GPIO 0
  D4  IO/10K pullup, builin Led GPIO 2
  D5  IO/SCK                    GPIO 14
  D6  IO/MISO                   GPIO 12
  D7  IO/MOSI                   GPIO 2
  D8  IO/10K pullup, SS          GPIO 2
  
  
  
  
  

Motor Shield:
  I2C interface: DCL/SDA pins have 4.7K pullups
  VM: Motors power (15V max)
  Current:  1.2A Avr, 3.2A peak max
  CW/CCW/short brake/stop motor control modes (Clock Wise, CounterClockWize)
  
