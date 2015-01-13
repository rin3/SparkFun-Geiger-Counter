# SparkFun-Geiger-Counter
Arduino sources for SparkFun Geiger Counter
SEN-09298, SEN-09848, SEN-10742 and SEN-11345
https://www.sparkfun.com/products/11345

## Prerequisite
You must first install Arduino bootloader on your SparkFun Geiger Counter using one of the ISP programmers (eg. AVRISP mkII).

- Fuse settings: low:0xE2, high:0xDE, extended:0xFD
- Then burn optiboot bootloader: optiboot_atmega328.hex

Please pay due caution and DO THIS AT YOUR OWN RISK. If you burn with wrong parameters, you will brick your SparkFun Geiger Counter! (It runs on internal RC oscillator. So if you, by mistake, set fuses for use with an external oscillator, you will brick the unit. Amen.)

The earlier versions SEN-09298 and SEN-09848 don't have auto-reset circuitry. You have to do manual reset but the timing is very tricky. Use verbose output on uploading sketches in Arduino IDE to get the hang of it.

'Counter' LED is connected on Arduino A5 pin. To test with a 'Blink' sketch, change 'ledPin' from '13' to 'A5'.
