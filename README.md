# TMS320-DSPkit-Averaging-Filter
In this project, I've gone over the process of using the TMS3206713 DSP kit for filter designing. First, I'll show the steps to correctly download, install and call libraries. Then, I'll go through a simple LED control exercise. Followed by a background study of Averaging Filters and writing an algorithm for it to test against an audio signal.

# Downloading the CCS IDE
The first step is to download the CCS coding environment. To do this, you can simply follow the video link given below: https://youtu.be/wcp2TzxCHHA

Once the IDE is installed, go ahead and follow the instructions of adding the libraries as well as any other process mentioned in the video. After that, restart your computer and launch the IDE again.

# Connecting the DSP kit with CCS & Test LED Blink
1. Once the CCS IDE is installed and properly setup, you can go ahead and connect the trainer cable and run the led.c code CCS.
2. Once you’ve copied the code, go ahead and click on the build option in the panel above.
3. Once done, see if any errors show up in the window below. If not, then follow the steps below. However, if you do face errors, then see if you followed the installation video correctly or not.
4. If there are no errors, then click on the bug option beside the build option and wait for a new window to appear.
5. Once the new window appears, wait for the instructions to setup.
6. Here, either an error may show up or not. If it does, then repeat the process a few times, or try deleting old programs saved earlier.
7. If no error shows up, then click on the Run button and see if an LED blinks on the trainer.

# Finite Impulse Response Filters
An FIR averaging filter is a category of FIR filter most commonly discussed in the theoretical study of DSP. This simple filter method is chosen to minimize the complexity of building filters using DSP kits. Once you understand and implement this filter, other implementations can be made easily.

# Problem Identification
Songs, or audio files that have noise in them are a common problem that can occur in several applications. Sometimes, these noises are to be eliminated every time they are processed or fed to the output. For this, a noise reduction filter is required that can provide linear phase delay and smoothing of audio signal.

# Proposed Solution
The FIR Moving Average Filter is a digital filter, specifically a five-point moving average filter that works by taking the average of the current sample and the four preceding samples.

# Why FIR Filters?
1. Stability
2. Linear Phase Response (Suitable for Songs)

FIR filters have a finite duration impulse response, meaning that their output is only a function of a finite number of input samples, and the filter’s impulse response decays to zero within a finite time interval. The impulse response of this filter is simply the unit impulse followed by four zeros. FIR filters have advantages over IIR filters, such as linear phase response, and stability, but may require more computational resources for long filter lengths compared to IIR.

![image](https://github.com/user-attachments/assets/8c17efda-186d-477e-a95d-ede5f25e1892)

$$y = \frac{x_1 + x_2 + x_3 + x_4 + x_5}{5}$$

# Why Averaging Filter?
1. Enhanced Noise Reduction
2. Smoothened Output
3. Reduced Signal Fidelity
4. Loss of High-Frequency Detail

When applying this filter to a song, the output you’d observe would depend on the specific application and the characteristics of the song. Generally, this can smooth out the fluctuations and noise in the signal, resulting in a smoother and more stable output.

This also, loses the detail in high-frequency information of the original song. Therefore, the effect of the filter will depend on specific goals of the filtering process and the desired trade-off between noise reduction and signal fidelity.

# Proposed Methodology
For this CEA, we are using the TMS3206713 Digital Signal Processing Kit, that comes along with a Line in and Line out Port. Using a smartphone for noisy signal generation, we’ll be feeding the DSP kit with it through the line in port. After that, a C based moving average filter sample processing is to be carried out for the buffer in and buffer out commands of the DSP trainer. Then, the output is to be buffered out to the line out port of the trainer.

# Block Diagram
![image](https://github.com/user-attachments/assets/015eb3b3-e37b-49e4-895f-a58adba87404)

# Algorithm
For every input sample x, do:
{
$$y = \frac{1}{5}(x + w_1 + w_2 + w_3 + w_4)$$
$$w_1 = w_2$$
$$w_2 = w_3$$
$$w_3 = w_4$$
$$w_4 = y$$
}

# Run The FIR Filter
Run the fir.c code in CCS.

# Code Explanation

**Libraries:**

In this code, first we introduce all the necessary libraries that must be called in order to run this program. The stdio.h, stdlib.h are common libraries that must be called in any C program. The math.h library is optional, in case you want to use math functions such as sin, cos, tan, sqrt, etc. After that, the library dsk6713.h is the library that allows the trainer to be interfaced with CCS. And finally, the dsk6713_aic23.h is the library for sound processing for the trainer.

**Pre-main code:**

First of all, a sample size is defined beforehand. This is because the FIR filter is a real-time filter. The sample size allows us to define the number of samples that are taken in every cycle of the code.
Once that is done, a buffer-in and buffer-out array is setup. These arrays are responsible for holding the 16000 samples that are taken in from the line in and are output to line out in each cycle respectfully.

**Void Main:**

First off, all the codec is setup with default settings. Then, code is written to allow audio to be read from the line-in and write to the line-out. After that, a sampling frequency of 48kHz is setup.
Once that is done, then some code, specific to the averaging filter is written. Here, you can write an algorithm of your choice, for any application that you are working on. But, once that is done the write command must be used to output samples to the line-out.

**Note:** Remember to introduce amplifications to the input samples since it isn’t of high enough amplitude to be heard by a headphone.

# Observations
The main observations that I undertook in this project was the effect of changing sampling frequency, averaging filter and amplification. When I removed the averaging filter, the output signal had a lot of noise with it. After that, when I implemented the averaging filter, but kept the sampling frequency small, the noise still remained, but rather appeared during high frequency components region of the song. Finally, when I increased the sampling frequency to 48kHz and placed the averaging filter, all noise vanished and I was able to successfully hear the input signal at the output.
