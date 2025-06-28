#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include "library.h"
#include <string>
using namespace std;

void recommendByMood(Library& lib, const string mood);
void recommendByCharacter(Library& lib, const string character);
void recommendByPlot(Library& lib, const string plot);

#endif
