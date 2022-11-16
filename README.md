# USBNova

Source code of the USB Nova firmware.

For documentation, please visit: [usbnova.com](https://usbnova.com/)

## Compile using Arduino-CLI
Install [Arduino-CLI](https://arduino.github.io/arduino-cli/0.28/installation/).  
Add `https://adafruit.github.io/arduino-board-index/package_adafruit_index.json` to the additional board manager URLs.  
Edit boards.txt in `/packages/adafruit/hardware/samd/<version>/` and add [boards.txt](boards.txt).  

Compile and upload:  
`arduino-cli compile --fqbn adafruit:samd:adafruit_qtpy_m0_nova:usbstack=tinyusb,debug=off -u -p <PORT>`

Compile and export:  
`arduino-cli compile --fqbn adafruit:samd:adafruit_qtpy_m0_nova:usbstack=tinyusb,debug=off --output-dir build/`

Convert to uf2:  
`uf2conv build/USBNova.ino.bin -o build/USBNova.ino.uf2`