# Audio configuration
[Raspberry pi - Audio Configuration](https://www.raspberrypi.org/documentation/configuration/audio-config.md)

To config the audio for:
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

# Libraries installation
To install the libraries that is used in this program.

```
	$ sudo apt-get install libao-dev
```
```
	$ sudo apt-get install libmpg123-dev
```

Optional to update the libraries. If you choose to follow the following commands reboot the computer after it is done.
```
	$ sudo apt-get update
```
```
	$ sudo apt-get upgrade -y
```

# Compile
To compile the code go to the directory you saved the `play.c` using the command `cd` then execute the line bellow.
```
	$ gcc -02 -o play play.c -lmpg123 -lao
```

# Execute
To execute the program `play`
```
	$ ./play /path/to/file.mp3
```

# Reference
The code used as reference the webpage (http://hzqtc.github.io/2012/05/play-mp3-with-libmpg123-and-libao.html)
