#pragma once

#include <iostream>
#include <ctime>
#include <sys/resource.h>

double clockTime();
double userTime( struct rusage *start, struct rusage *end );
double systemTime( struct rusage *start, struct rusage *end );
