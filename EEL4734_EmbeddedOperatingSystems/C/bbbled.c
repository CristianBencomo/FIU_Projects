/*
 ============================================================================
 Name        : BeagleBoneLed.c
 Author      : Cristian
 =========================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{	
	int hightime = 5000;
	int lowtime = 5000;
	FILE *filehandle = NULL;
	const char *LEDBrightness = "/sys/class/leds/beaglebone:green:usr0/brightness";
	const char *LEDDelayOn = "/sys/class/leds/beaglebone:green:usr0/delay_on";
	const char *LEDDelayOff = "/sys/class/leds/beaglebone:green:usr0/delay_off";

	for (int i = 0; i < argc; i++)
	{
		
		if (strcmp(argv[i], "-h") == 0)
		{
			if (argv[i + 1])
			{
				hightime = atoi(argv[i + 1]);
			}
			else
			{
				printf ("Missing parameter... Using default value for the missing parameter\n");
			}
			
		}

		if (strcmp(argv[i], "-l") == 0)
		{
			if (argv[i + 1])
			{
				lowtime = atoi(argv[i + 1]);
			}
			else
			{
				printf ("Missing parameter... Using default value for the missing parameter\n");
			}
		}
	}

	if ((filehandle = fopen(LEDBrightness, "r+")) != NULL)
	{
		fprintf(filehandle, "1");
		fclose(filehandle);

		filehandle = fopen(LEDDelayOn, "r+");
		fprintf(filehandle, "%d", hightime);
		fclose(filehandle);

		filehandle = fopen(LEDDelayOff, "r+");
		fprintf(filehandle, "%d", lowtime);
		fclose(filehandle);
	}
}
