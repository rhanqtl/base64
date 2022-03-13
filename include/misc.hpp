#ifndef BASE64_MISC_H
#define BASE64_MISC_H

#include <cstdio>
#include <cstdlib>

#define UNIMPLEMENTED \
    _unimplemented(__FILE__, __LINE__, __FUNCTION__)

/* 
 * some (functional) programming languages defines a function that never 
 * returns (e.g., exit(3)) as "never type"
 */
using never_t = void;
inline never_t _unimplemented(const char *filename, const int lineno, const char *func) {
  std::fprintf(stderr, "function %s is not yet implemented (at %s:%d)\n", func, filename, lineno);
  std::exit(1);
}

#endif  // BASE64_MISC_H