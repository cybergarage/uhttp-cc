/******************************************************************
 *
 * uHTTP for C++
 *
 * Copyright (C) Satoshi Konno 2002
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <uhttp/util/Semaphore.h>

uHTTP::Semaphore::Semaphore(size_t maxCount) {
  this->setCount = 0;
  this->isCanceled = false;

#if defined(__APPLE__)
#if defined(FRACTAL_USE_MACOSX_DISPATCH_SEMAPHORE)
  this->semId = dispatch_semaphore_create(maxCount);
#else
  MPCreateSemaphore(maxCount, 0, &this->semId);
#endif
#else
  sem_init(&semId, 0, maxCount);
#endif
}

uHTTP::Semaphore::~Semaphore() {
  cancel();
}

bool uHTTP::Semaphore::post() {
  bool isSuccess = true;
  
  this->semMutex.lock();
  this->setCount++;
  this->semMutex.unlock();

#if defined(__APPLE__)
#if defined(FRACTAL_USE_MACOSX_DISPATCH_SEMAPHORE)  
  dispatch_semaphore_signal(this->semId);
#else
  isSuccess = (MPSignalSemaphore(this->semId) == 0) ? true : false;
#endif
#else
  isSuccess = (sem_post(&semId) == 0)  ? true : false;
#endif


  return isSuccess;
}

bool uHTTP::Semaphore::wait(time_t timeoutSec) {
  bool isSuccess = true;
  
  this->semMutex.lock();
  this->setCount--;
  this->semMutex.unlock();
  
#if defined(__APPLE__)
#if defined(FRACTAL_USE_MACOSX_DISPATCH_SEMAPHORE)
  dispatch_time_t disPatchTimeout = dispatch_time(DISPATCH_TIME_NOW, (timeoutSec * NSEC_PER_SEC));
  isSuccess = (dispatch_semaphore_wait(this->semId, ((0 < timeoutSec) ? disPatchTimeout : DISPATCH_TIME_FOREVER)) == 0) ? true : false;
#else
  isSuccess = (MPWaitOnSemaphore(this->semId, ((0 < timeoutSec) ? kDurationMillisecond : kDurationForever)) == 0) ? true : false;
#endif
#else
  if (0 < timeoutSec) {
    timespec absTimeout;
    absTimeout.tv_sec = timeoutSec;
    absTimeout.tv_nsec = 0;
    isSuccess = (sem_timedwait(&semId, &absTimeout) == 0)  ? true : false;
  }
  else {
    isSuccess = (sem_wait(&semId) == 0)  ? true : false;
  }
#endif

  if (this->isCanceled)
    return false;
  
  return isSuccess;
}

void uHTTP::Semaphore::cancel() {
  this->isCanceled = true;
  
#if defined(__APPLE__)
#if defined(FRACTAL_USE_MACOSX_DISPATCH_SEMAPHORE)
  if (this->setCount < 0) {
    for (int n=0; n<(-this->setCount); n++)
      dispatch_semaphore_signal(this->semId);
  }
  if (0 < this->setCount) {
    for (int n=0; n<(-this->setCount); n++)
      dispatch_semaphore_wait(this->semId, DISPATCH_TIME_FOREVER);
  }
  dispatch_release(this->semId);
#else
  MPDeleteSemaphore(this->semId);
#endif
#else
  sem_destroy(&semId);
#endif
}
