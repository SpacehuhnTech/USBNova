![USB Nova Logo](https://usbnova.com/img/about/nova_yellow.png)
![USB Nova Photo](https://usbnova.com/img/home/nova2-small.png)

Get firmware updates on the [release page](https://github.com/SpacehuhnTech/USBNova/releases)

For documentation, please visit: [usbnova.com](https://usbnova.com/)

<a href='https://spacehuhn.store/products/usb-nova' target='_blank'>
  <img height='36' style={{border:0,height:'36px'}} src='https://usbnova.com/img/about/buy.png' border='0' alt='Buy Now' />
</a>
&nbsp;
<a href='https://ko-fi.com/G2G75FA4V' target='_blank'>
  <img height='36' style={{border:0,height:'36px'}} src='https://usbnova.com/img/about/kofi_button.png' border='0' alt='Buy Me a Coffee at ko-fi.com' />
</a>

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
(To install uf2conv, install rust, then `cargo install uf2conv`) 

---

For RP2040:  
`arduino-cli compile --fqbn rp2040:rp2040:generic:flash=16777216_15728640,usbstack=tinyusb --output-dir build/`
(usually not required, but just in case: `elf2uf2-rs build/USBNova.ino.elf build/USBNova.ino.uf2`)
(To install `cargo install elf2uf2-rs`)

---

For Adafruit Trinkey RP2040:
`arduino-cli compile --fqbn rp2040:rp2040:adafruit_trinkeyrp2040qt:flash=8388608_7340032,usbstack=tinyusb --output-dir build/`

