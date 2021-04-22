# The Life of of my Robot -- TOTO


To check out the website on Github, head over to my repository on [here](https://github.com/raghav2956/Cornell-University-ECE3400)


# Lab 1

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

![](Photos/Toto-Frame.png)


## Toto's Eyes
A not-so-pretty prototype of the 'vision' of the robot. The two photoresistors on either side respond to light by changing their resistance, 
providing an analog measurement on the basis of which the motors will be controlled.  

![](Photos/Toto-Eyes.png)

# Lab 2

### Overview 
In week 2, I substantially increased the functionality of Toto's life. He can move now and respond to light -- rotating in position if there 
he is confused (lights are dim) and following the light when it hits either of his eyes. Some details involved ->

1. Playing around with the ADC registers to find prescalar values that influenced the ADC clock which influenced sampling rate. 
2. Incorporating the H-Bridge as the controller to the motors. The IC took inputs from the Arduino and its output fed into the motors. The 
   main function of the H-Bridge is to control the direction of rotation of the DC motor using the digital inputs given by the Arduino.
3. Tinkering around to understand the PWM signal from the Arduino (functionality, syntax and values) that would control the motors via the H-Bridge. 
   I had to try several values of the PWM pins to figure out what made TOTO rotate, go in a straight line, etc.

## H-Bridge Circuit 
The internal circuit looks messy but hey, did you think your human biology is any simpler ?! I am playing god here.
![](Photos/Toto-Legs-Control.png)


## Toto Reacts to Light
To watch Toto in action click [here](https://youtu.be/HeyBRctOXM4)

# Lab 3
Considering Lab 3 was a significantly longer lab, it was divided into three 1 week modules. The weekly tasks were less daunting to tackle and allowed us to
stay on track to finish the whole lab by the deadline.

## Week 1 Overview
In week 1, we first learnt how to use LTSpice to simulate electrical circuits and model their characteristics. We simulted a low pass and a high pass filter, obtained their Bode Plots and found their cutoff frequencies. We were then tasked with building a microphone circuit that could listen for and transmit auditory data (specifically a note of 500 Hz) into the Arduino. Using the on board Analog to Digitial Converter, we sampled the incoming analog data, discretized it and transmitted it to Matlab. Using Matlab, we performed a Fourier transformation on the Arduino data and obtained a freqeuncy spectrum, which when plotted, yielded a peak at the note originally played. 

### Bode Plot for Low Pass Filter
![](Photos/Low-Pass-Bode.png)

### Bode Plot for High Pass Filter
![](Photos/High-Pass-Bode.png)


### Week 1 Challenges
1. One of the foremost challenges in using the microphone circuit was that our microphone was not of a very high quality and picked up a lot of noise along with
   the sound signal. There were many reasons for this noise -- 1/f noise, the 60Hz flickering noise from electronic applicances and finally the current flowing        through the wires on the breadboard itself. Due to this the spectrum obtained was very noisy and one had to really zoom in to find the peak at 500 Hz. We also      had to turn up the laptop volume to its highest and keep the microphone really close to the speakers
2. Setting up the ADC in freerun mode was also a bit tricky because one had to get familir with the ADC documentation in order to correctly set the ADC registers.
   I, particularly, had issues with finding the right analog pin declaration. For example, AIN3 on the arduino pinout is actually mapped to PORTD.PIN0CTRL instead      of PORTD.PIN3CTRL. This confused me for a while.
   
## Week 2 Overview
Week 2 was praticularly heavy because we had a lot of subtasks in the same week. To begin with, we first improved the microphone circuit by adding an LM358 op-amp amplifier. Upon amplification, the 500 Hz peak became much clearer but the peak was a little shifted ahead of the 500Hz mark like so ->

![](Photos/Improved_uphone_image.jpg)

Once the output from the microphone was amplified, we were tasked with passing the output through a low pass and high pass filter seperately. The goal was implement and observe the bhaviour of a real life filter as it is applied on an incoming sound signal and to then observe the implications on the Fourier Spectrum. Unfortunately the filters didn't behave as expected (due to the noise, again) and hence we could only approximate the effects of the filter on the actual signal. 

Here are two plot depicting the superimposition of the expected behaviour of the filter (obtained from the Bode Plot) and the real behaviour on the 500Hz sound signal. This is all plotted in Matlab. The LTSpice data (magnitude and phase) is first imported into a google sheet, cleaned and then read via Matlab. To observe the data, we zoomed in around the 500 Hz - 1K Hz mark since that is our frequency of interest. 

### Low Pass superimposition
![](Photos/LP-Superposition-Final.jpg)

### High Pass superimposition
![](Photos/HP_Superposition_Final.jpg)

As you can see, while the y-axis scales are different, there is a general trend that both, the theoretical and experimental data show. The delta magnitude is around 3dB in the experimental data as it ranges from 500Hz to 1KHz.

Finally, we were required to build a bandpass filter that, theoretically, attenuated frequencies below 500Hz and above 1KHz. The hope was that all the noise around the signal of interest would be eliminated to a great extent using the bandpass filter, however, that didn't quite happen since the bandpass filter, itself, was not spared from the perils of surrounding noise and the low quality of the op-amps used. The LTSpice simulations for the Bandpass filter looked like so ->

## BandPass Filter LTSpice Schematic
![](Photos/Band-Pass-Circuit.png)

## Bode Plot for BandPass Filter
![](Photos/Band-Pass-Bode.png)




