# OpenILDA
Cheap ILDA SPI DAC board for Raspberry Pi.
**Work in progress.**

ILDA output: balanced X/Y - 12 bit,  balanced R/G/B/I - 8 bit.

Playback of ILDA files from external SD card.

OSC support (using RPi <- UART/USB -> PC[java] <- UDP-> iPad/iPod)

This OpenILDA DAC board uses the SPI interface for controlling 3 DAC's. The MCP49x2 device is a dual channel DAC.
As the RPi just has 2 SPI chip enable lines, the DAC /CS lines are created by using a HC139. See https://www.raspberrypi.org/forums/viewtopic.php?p=333992#p333992.

Of course, I could have used a 12-bit 8-channel DAC (for example TLV5610IDW). This would create less components. However, such a DAC is relatively expensive (about 24 euro), and it would have a SO-20 package.

I will post the OpenILDA SD card player with OSC support (written for bare-metal) soon.

## What's next?
* Reduce the amount of OPAMP's (from 6 to 3)
* Enable using single voltage power supply
	* Use DC/DC converter for -12 volt / +12 volt
	* Use 7805 for 5 volt output voltage


See also https://www.raspberrypi.org/forums/viewtopic.php?p=366647#p366647.
