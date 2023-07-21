# USB Nova MKI (SAMD21)
arduino-cli compile --fqbn adafruit:samd:adafruit_qtpy_m0_nova:usbstack=tinyusb,debug=off --output-dir build/
uf2conv build/USBNova.ino.bin -o build/USBNova_mkI.uf2

# USB Nova MKII (RP2040)
arduino-cli compile --fqbn rp2040:rp2040:generic:flash=16777216_15728640,usbstack=tinyusb --output-dir build/
mv build/USBNova.ino.uf2 build/USBNova_mkII.uf2

# Adafruit Trinkey
arduino-cli compile --fqbn rp2040:rp2040:adafruit_trinkeyrp2040qt:flash=8388608_7340032,usbstack=tinyusb --output-dir build/
mv build/USBNova.ino.uf2 build/USBNova_trinkey.uf2

# Raspberry Pi Pico
arduino-cli compile --fqbn rp2040:rp2040:rpipico:flash=2097152_1048576,usbstack=tinyusb --output-dir build/
mv build/USBNova.ino.uf2 build/USBNova_pico.uf2

# Clean up
rm build/USBNova.ino.bin
rm build/USBNova.ino.elf
rm build/USBNova.ino.hex
rm build/USBNova.ino.map

echo "Done!"