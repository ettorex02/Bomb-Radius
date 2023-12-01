#include <stdio.h>
#include <math.h>

float volume(float r, float h);
float flash_cm3_to_g(float vol);

void main(){

    float r = 0.0;
    float h = 0.0;

    int choice = 0;

    printf("Scegli cosa vuoi fare: \n 1)Bomba su misura. \n 2)Varie misure in base all'altezza.\n 3)Varie misure in base al raggio \n");
    scanf("%d", &choice);

    switch (choice){
        
        case 1:
            printf("Inserire valore raggio: \n");
            scanf("%f", &r);
            printf("Inserire valore altezza: \n");
            scanf("%f", &h);

            float v = volume(r,h);
            float p = flash_cm3_to_g(v);

            printf("Volume del cilindro: %.2f\n", v);
            printf("Polvere da sparo in g: %.2f", p);
            break;
        
        case 2:
            printf("Seleziona un raggio per il cilindro: (DA 1 a 10)\n");
            scanf("%f", &r);

            for(int i = 1; i<21; i++)
            {
                float v = volume(r, (float) i);
                printf("Raggio = %.2f - Altezza = %.2f - Grammi = %.2f\n", r, (float) i, flash_cm3_to_g(v));
            }
            break;

        case 3:
            printf("Seleziona un'altezza per il cilindro: (DA 1 a 20)\n");
            scanf("%f", &h);

            for(int i = 1; i<11; i++)
            {
                float v = volume((float) i, h);
                printf("Raggio = %.2f - Altezza = %.2f - Grammi = %.2f\n", (float) i, h, flash_cm3_to_g(v));
            }
            break;

    } 

}

float volume(float r, float h)
{
    float volume = (r*r)*M_PI*h;
    return volume;
}

float flash_cm3_to_g(float vol)
{
    float powder = vol*0.68;
    return powder-(powder*0.12);
}

