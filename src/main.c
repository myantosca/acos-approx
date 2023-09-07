#include "main.h"

int main(int argc, char *argv[])
{
  int rounds = 0;
  float step = 0.0;

  if (argc < 3) {
    fprintf(stderr, "Specify approximation rounds and step.\n");
    return -1;
  }
      
  if (sscanf(argv[1], "%u", &rounds) != 1) {
    fprintf(stderr, "Invalid rounds specification: %s\n", argv[1]);
    return -1;
  }

  if (sscanf(argv[2], "%f", &step) != 1) {
    fprintf(stderr, "Invalid step specification: %s\n", argv[2]);
    return -1;
  }

  float x = -1.0f;
  float a = 0.0f;
  float b = 0.0f;
  float c = 0.0f;
  float d = 0.0f;
  float e = 0.0f;
  float f = 0.0f;
  float g = 0.0f;
  float h = 0.0f;
  float i = 0.0f;
  fprintf(stdout,
	  "x\t"
	  "acos\t"
	  "binomial\t"
	  "nvidia0\t"
	  "nvidia1\t"
	  "nvidia2\t"
	  "nvidia3\t"
	  "nvidia4\t"
	  "nvidia5\t"
	  "d_binomial\t"
	  "d_nvidia0\t"
	  "d_nvidia1\t"
	  "d_nvidia2\t"
	  "d_nvidia3\n"
	  "d_nvidia4\n"
	  "d_nvidia5\n"
	  );
  while (x <= 1.0f) {
    a = acosf(x);
    b = acos_binomial(x, rounds);
    c = acos_nvidia0(x);
    d = acos_nvidia1(x);
    e = acos_nvidia2(x);
    f = acos_nvidia3(x);
    g = acos_nvidia4(x);
    h = acos_nvidia5(x);
    i = acos_nvidia6(x);
    fprintf(stdout, "%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",
	    x, a, b, c, d, e, f, g, h, i, a - b, a - c, a - d, a - e, a - f, a - g, a - h, a - i);
    x += step;
  }
  return 0;
}
