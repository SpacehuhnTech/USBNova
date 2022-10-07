# USBNova

## Arduino-CLI
* Install it (Download it and add it to PATH)
* Initiate it `arduino-cli config init` (it is saved at `C:\Users\username\AppData\Local\Arduino15\arduino-cli.yaml`)
* Update cores `arduino-cli core update-index`
* Install core `arduino-cli core install adafruit:samd`
* Check your boards `arduino-cli board list`
* Compile `arduino-cli compile --profile adafruit_qtpy_m0`
* Upload `arduino-cli upload -p COM3`
* Compile and upload `arduino-cli compile --fqbn adafruit:samd:adafruit_qtpy_m0:opt=small,usbstack=tinyusb,debug=off -u -p COM3`
* Compile export `arduino-cli compile --fqbn adafruit:samd:adafruit_qtpy_m0:opt=small,usbstack=tinyusb,debug=off --output-dir build/`
* Convert to uf2 `uf2conv build/USBNova.ino.bin -o build/USBNova.ino.uf2`