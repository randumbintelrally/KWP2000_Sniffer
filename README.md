# KWP2000_Sniffer
This sketch is intended to break down KWP2000 messages and parse out their meanings. 

Using a FTDI breakout and a LM339 chip, this allows a Teensy LC to connect its RX Pin to the FTDI232 RX Pin and spy on all communications.  

It will Parse commands and subcommands to an extent.

In means from the ECU to the Microcontroller
Out means from the Microcontroller to the ECU

It will take extended messages for WriteMemoryToAddress and place them into a array to make it easier to copy/paste into a constant in a program.

Intention is to set up ME7Logger to log desired variables and then duplicate the configuration to be able to parse the data out on the back end.
