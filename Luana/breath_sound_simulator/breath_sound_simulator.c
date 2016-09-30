/*
 *	Luana Okino Sawada - breath_sound_simulator.c
 *	https://github.com/simoesusp/PatientSimulator/tree/master/Luana/breath_sound_simulator
 *	To compile:
 *	gcc -O2 -o bss breath_sound_simulator.c -lmpg123 -lao
 *	To execute
 *	./breath_sound_simulator
 *	Reference: 
 *	http://hzqtc.github.io/2012/05/play-mp3-with-libmpg123-and-libao.html
 */
 
#include <stdio.h>
#include <ao/ao.h>
#include <mpg123.h>

#define BITS 8

int main(int argc, char *argv[])
{
	mpg123_handle *mh;
	unsigned char *buffer;
	size_t buffer_size;
	size_t done;
	int err;

	int driver;
	ao_device *dev;

	ao_sample_format format;
	int channels, encoding;
	long rate;
	
	char * s1 = "./sample1.mp3";
	char * s2 = "./sample2.mp3";
	char * s3 = "./sample3.mp3";
	char * s4 = "./sample4.mp3";
	int answer = -1;

	/* initializations */
	ao_initialize();
	driver = ao_default_driver_id();
	mpg123_init();
	mh = mpg123_new(NULL, &err);
	buffer_size = mpg123_outblock(mh);
	buffer = (unsigned char*) malloc(buffer_size * sizeof(unsigned char));
	
	while(answer != 0)
	{
		printf("Which sample do you want to play?\n");
		printf("enter a number: 1,2,3,4 or 0 to QUIT\n");
		scanf("%d", &answer);
		
		switch (answer)
		{
			case 1: //play sample1.mp3
			/* open the file and get the decoding format */
				mpg123_open(mh, s1);
				mpg123_getformat(mh, &rate, &channels, &encoding);
				
				/* set the output format and open the output device */
			format.bits = mpg123_encsize(encoding) * BITS;
			format.rate = rate;
			format.channels = channels;
			format.byte_format = AO_FMT_NATIVE;
			format.matrix = 0;
				dev = ao_open_live(driver, &format, NULL);
				
				/* decode and play */
				mpg123_getformat(mh, &rate, &channels, &encoding);
				while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
			ao_play(dev, buffer, done);         
				break;
				
			case 2: //play sample2.mp3
				/* open the file and get the decoding format */
				mpg123_open(mh, s2);
				mpg123_getformat(mh, &rate, &channels, &encoding);
	
				/* set the output format and open the output device */
			format.bits = mpg123_encsize(encoding) * BITS;
			format.rate = rate;
			format.channels = channels;
			format.byte_format = AO_FMT_NATIVE;
			format.matrix = 0;
				dev = ao_open_live(driver, &format, NULL);
	
				/* decode and play */
				mpg123_getformat(mh, &rate, &channels, &encoding);
				while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
				break;
				
			case 3: //play sample3.mp3
			/* open the file and get the decoding format */
				mpg123_open(mh, s3);
				mpg123_getformat(mh, &rate, &channels, &encoding);
				
				/* set the output format and open the output device */
			format.bits = mpg123_encsize(encoding) * BITS;
			format.rate = rate;
			format.channels = channels;
			format.byte_format = AO_FMT_NATIVE;
			format.matrix = 0;
				dev = ao_open_live(driver, &format, NULL);          
				
				/* decode and play */
				mpg123_getformat(mh, &rate, &channels, &encoding);
				while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
			ao_play(dev, buffer, done);         
				break;
				
			case 4:
				/* open the file and get the decoding format */
				mpg123_open(mh, s4);
				mpg123_getformat(mh, &rate, &channels, &encoding);
				
				/* set the output format and open the output device */
			format.bits = mpg123_encsize(encoding) * BITS;
			format.rate = rate;
			format.channels = channels;
			format.byte_format = AO_FMT_NATIVE;
			format.matrix = 0;
				dev = ao_open_live(driver, &format, NULL);          
				
				/* decode and play */
				mpg123_getformat(mh, &rate, &channels, &encoding);
				while (mpg123_read(mh, buffer, buffer_size, &done) == MPG123_OK)
			ao_play(dev, buffer, done);         
				break;
			}
	}

	/* clean up */
	free(buffer);
	ao_close(dev);
	mpg123_close(mh);
	mpg123_delete(mh);
	mpg123_exit();
	ao_shutdown();

	return 0;
}

