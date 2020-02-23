import subprocess
import serial
import http
import requests


URL = "https://core.blockstack.org/v1/names/{names}".replace("{names}","muneeb.id")
data = requests.get(URL).json()['grace_period']

serial = serial.Serial('COM3', 9600, None)
hardware_auth = serial.read()
serial.close()


if(software_auth and hardware_auth):
    serial = serial.Serial('COM3', 9600)
    serial.write(True)
    serial.close()
else:
    print("2-factor authentication failed")
