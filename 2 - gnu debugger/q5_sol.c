#include <stdio.h>
#include <stdlib.h>

int main()
{
	float x[7];
	char f[20];
	float load_average, percentage, new_percentage;
	float total_time = 0, idle_time = 0, total_value = 0;
	FILE *fp = fopen("/proc/stat", "r");
	fscanf(fp, "%s %f %f %f %f %f %f %f", f, &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6]);
	for (int i = 0; i < 7; i++)
	{
		total_time = x[i] + total_time;
	}
	idle_time = (x[3] + x[4]) / total_time;
	total_value = 1 - idle_time;
	percentage = total_value * 100;

	while (1)
	{

		total_time = 0, idle_time = 0, total_value = 0;
		fp = fopen("/proc/stat", "r");
		fscanf(fp, "%s %f %f %f %f %f %f %f", f, &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6]);
		for (int i = 0; i < 7; i++)
		{
			total_time = x[i] + total_time;
		}
		idle_time = (x[3] + x[4]) / total_time;
		total_value = 1 - idle_time;
		new_percentage = total_value * 100;
		load_average = (percentage + new_percentage) / 2;
		printf("The Average CPU Utilization Percentage is : %f\n", load_average);
		percentage = new_percentage;
		fclose(fp);
	}
	return 0;
}