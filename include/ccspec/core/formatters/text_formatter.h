#ifndef CCSPEC_CORE_FORMATTERS_TEXT_FORMATTER_H_
#define CCSPEC_CORE_FORMATTERS_TEXT_FORMATTER_H_

#include <exception>
#include <list>
#include <ostream>
#include <ccspec/core/formatter.h>

namespace ccspec {
namespace core {
namespace formatters {

class TextFormatter : public Formatter {
  public:
    virtual void dumpFailures(std::list<const std::exception*> failures) const;

  protected:
    explicit TextFormatter(std::ostream&);
};

} // namespace formatters
} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_FORMATTERS_TEXT_FORMATTER_H_