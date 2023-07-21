# USB Nova for MalDuino (SAMD21)
arduino-cli compile --fqbn adafruit:samd:adafruit_qtpy_m0_malduino:usbstack=tinyusb,debug=off --output-dir build/
uf2conv build/USBNova.ino.bin -o build/USBNova_MalDuino_SAMD.uf2

# Clean up
rm build/USBNova.ino.bin
rm build/USBNova.ino.elf
rm build/USBNova.ino.hex
rm build/USBNova.ino.map

echo "Done!"