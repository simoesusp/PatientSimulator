# Breath Sound Simulator
It is a program developed in the language C that plays mp3 files that has different lung diseases in order that the medical/nursing student can listen the sound and diagnose the disease that the patient has. In this way the program simulates the breathing of a patient.

# Audio configuration
To configure the audio you want to use enter the corresponding command in the `terminal`:

**automatic:**
```
	$ amixer cset numid=3 0
```
**Analogue** (headphone jack):
```
	$ amixer cset numid=3 1
```
**HDMI:**
```
	$ amixer cset numid=3 2
```

P.S.: if it does not work try to follow the instructions from [Raspberry pi - Audio Configuration](https://www.raspberrypi.org/documentation/configuration/audio-config.md)


# Libraries installation
To install the libraries that are used in this program type these commands in the `terminal`.
```
	$ sudo apt-get install libao-dev

	$ sudo apt-get install libmpg123-dev
```

Optional to update the libraries. If you choose to follow the following commands reboot the computer after it is done.
```
	$ sudo apt-get update

	$ sudo apt-get upgrade -y
```


# Compile
To compile the code go to the directory you saved the `breath_sound_simulator.c` using the command `cd` then execute the line bellow.
```
	$ gcc -O2 -o bss breath_sound_simulator.c -lmpg123 -lao
```


# Execute
To execute the program `bss` just need to execute this line.
```
	$ ./bss
```


# Reference
The code used as reference the webpage (http://hzqtc.github.io/2012/05/play-mp3-with-libmpg123-and-libao.html)
