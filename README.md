# USBNova

## Arduino-CLI
* Install it (Download it and add it to PATH)
* Initiate it `arduino-cli config init` (it is saved at `C:\Users\username\AppData\Local\Arduino15\arduino-cli.yaml`)
* Update cores `arduino-cli core update-index`
* Install core `arduino-cli core install adafruit:samd`
* Check your boards `arduino-cli board list`
* Compile `arduino-cli compile --profile adafruit_qtpy_m0`
* Compile `arduino-cli upload -p COM3`