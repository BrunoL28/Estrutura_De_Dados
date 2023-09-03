#pragma once

#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>

double userTime();
double systemTime();
double clockTime ( struct timespec ti, struct timespec tf );

