// The Firmament project
// Copyright (c) 2011-2012 Malte Schwarzkopf <malte.schwarzkopf@cl.cam.ac.uk>
//
// Platform-independent coordinator class definition. This is subclassed by the
// platform-specific coordinator classes.

#ifndef FIRMAMENT_ENGINE_COORDINATOR_H
#define FIRMAMENT_ENGINE_COORDINATOR_H

#include <boost/thread.hpp>

#include "base/common.h"
#include "misc/messaging_interface.h"
#include "platforms/common.h"
#include "platforms/unix/messaging_streamsockets.h"

using namespace boost::posix_time;

namespace firmament {

class Coordinator {
 public:
  Coordinator(PlatformID platform_id);
  void Run();
  void AwaitNextMessage();
  inline PlatformID platform_id() {
    return platform_id_;
  }
 protected:
  PlatformID platform_id_;
  bool exit_;
  string coordinator_uri_;
  MessagingInterface* m_adapter_;
};

}  // namespace firmament

#endif  // FIRMAMENT_ENGINE_COORDINATOR_H
