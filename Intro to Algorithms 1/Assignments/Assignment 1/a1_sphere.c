#include <stdio.h>

int main(void)
{
    int radius, volume;
    
    printf("Enter the radius of the sphere:\n");
    scanf("%d", &radius);
    volume= (4.0f/3.0f) * 3.14159 * radius * radius * radius;

    printf("A volume with a %d-meter radius is %.4d.\n", radius, volume);
    return 0;
}