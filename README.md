## WPI Summer Research 2017

This was the start of some summer reasearch I participated at WPI.
We needed a really fast ADCs to sample E-Fields around a phantom head to then back 
calculate where the applied magnetic field affected the head. We thought that by using multiple Teensy boards we could create an antenna array. The boards had to be programmed to sample their ADCs faster and they had to be synchronized to sample together. The Code is in the Arduino folder. All the code was written in Arduino which is C based.

Apart from the fast ADC, the signal needs to be free of noise, so when the summer ended we were working on the circuitry
and antenna to properly measure the E-field. Those designs are in the eagle folder


## Configuration to Synchronize and Sample using 16 Teensy Boards
![](https://user-images.githubusercontent.com/13021723/29470858-ff85390e-841b-11e7-89cc-80fd2874df0f.png)




