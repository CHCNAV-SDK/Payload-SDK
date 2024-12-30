
#include "chcnav_hlog.h"
#include <iostream>
#include <unistd.h>

static const char *long_string =
    "This is a very long string more than 256 chars. This is a very long "
    "string more than 256 chars. This is a very long string more than 256 "
    "chars. This is a very long string more than 256 chars. This is a very "
    "long string more than 256 chars. This is a very long string more than 256 "
    "chars. ";

int main(int argc, char *argv[]) {
  chcnav_hlog_init(argv[0], "hlog-example.conf");
  chcnav_hlog_dump_hlog_settings();

  const float kPI = 3.1415926f;
  CHCNAV_HLOG(module1, INFO, "%s: Hello, there. [PI = %f?]", argv[0], kPI);
  CHCNAV_HLOG(module2, WARN, "Bye!");
  CHCNAV_HLOG(module3, VERBOSE, "Can you see this log?");

  CHCNAV_HLOG(module1, WARN, "%s", long_string);

  return 0;
}