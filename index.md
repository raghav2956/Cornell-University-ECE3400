# The Life of of my Robot -- TOTO


To check out the code, head over to my repository on [GitHub](https://github.com/raghav2956/Cornell-University-ECE3400)


# Week 1

### Overview
In week 1, we put together Toto's structural frame and got familiar with the Arduino, the microncontroller that is supposed to act
as her brains. Other things involved ->

1. Getting familiar with the Photoresistors that would act as Toto's 'eyes'.
2. Playing around with the Analog to Digital converter on the arduino to read the values off the photoresistors. We talked about the 
   significance of the reference voltage, the sampling rate and the resolution.

### Challenges
1. It was a little challenging to figure out how to use the photoresistors. We had to dig into the datasheet, make a voltage divider
   circuit and test the sensors out before using it as Toto's eyes.
2. It was fun to understand, in more detail, how the ADC on the Arduino works and what happens behind the scenes when we do an 
   AnalogRead('Pin').

## Toto at Birth
There is an aluminium frame which has two DC motors as wheels. The batteries will eventually power the Arduino and the motors -- seperate
power has been provided since the motors will consume a non-trivial amount of power. The breadboard on top will house all the circuitry.

![](Toto-Frame.png)


## Toto's Eyes
A not-so-pretty prototype of the 'vision' of the robot. The two photoresistors on either side respond to light by changing their resistance, 
providing an analog measurement on the basis of which the motors will be controlled.  

![](Toto-Eyes.png)


