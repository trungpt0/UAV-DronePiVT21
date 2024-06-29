#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define LED_PIN "71"

void writeGPIO(const char* filename, const char* value)
{
	FILE* f = fopen(filename, "w");
	if (f == NULL) {
		printf("Can not open file: %s\n", filename);
		exit(1);
	}
	fprintf(f, "%s", value);
	fclose(f);
}

int main() {
    writeGPIO("/sys/class/gpio/export", LED_PIN);
    
    char direction_path[35];
    sprintf(direction_path, "/sys/class/gpio/gpio%s/direction", LED_PIN);
    writeGPIO(direction_path, "out");
    
    char value_path[35];
    sprintf(value_path, "/sys/class/gpio/gpio%s/value", LED_PIN);
    writeGPIO(value_path, "1");

    return 0;
}
