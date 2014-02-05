/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <algorithm>

#include <uhttp/util/Random.h>

uHTTP::Random::Random() {
  this->minRange = 0;
  this->minRange = RAND_MAX;

  srand((unsigned int)time(NULL));
}

uHTTP::Random::Random(unsigned int min, unsigned int max) {
  this->minRange = std::min(min, max);
  this->maxRange = std::max(min, max);

  srand((unsigned int)time(NULL));
}

uHTTP::Random::~Random() {
}

unsigned int uHTTP::Random::rand() {
  double doubleRand = (this->maxRange - this->minRange) * ((double)::rand() / (double)RAND_MAX);
  return ceil(doubleRand) + this->minRange;
}

