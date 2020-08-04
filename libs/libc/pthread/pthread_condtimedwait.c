/****************************************************************************
 * libs/libc/pthread/pthread_condtimedwait.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <pthread.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: pthread_cond_timedwait
 *
 * Description:
 *   A thread can perform a timed wait on a condition variable.
 *
 * Input Parameters:
 *   cond    - the condition variable to wait on
 *   mutex   - the mutex that protects the condition variable
 *   abstime - wait until this absolute time
 *
 * Returned Value:
 *   OK (0) on success; A non-zero errno value is returned on failure.
 *
 * Assumptions:
 *   Timing is of resolution 1 msec, with +/-1 millisecond accuracy.
 *
 ****************************************************************************/

int pthread_cond_timedwait(FAR pthread_cond_t *cond,
                           FAR pthread_mutex_t *mutex,
                           FAR const struct timespec *abstime)
{
  return pthread_cond_clockwait(cond, mutex, CLOCK_REALTIME, abstime);
}
