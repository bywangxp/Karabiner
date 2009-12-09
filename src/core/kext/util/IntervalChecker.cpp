#include "IntervalChecker.hpp"
#include "RemapUtil.hpp"
#include <sys/systm.h>

namespace org_pqrs_KeyRemap4MacBook {
  void
  IntervalChecker::begin(void)
  {
    clock_get_system_microtime(&secs_, &microsecs_);
  }

  bool
  IntervalChecker::checkThreshold(uint32_t millisec)
  {
    clock_sec_t s;
    clock_usec_t m;
    clock_get_system_microtime(&s, &m);

    uint32_t interval = static_cast<int>(s - secs_) * 1000 + static_cast<int>(m - microsecs_) / 1000;
    //printf("checkThreshold interval %d\n", interval);
    return interval >= millisec;
  }
}
