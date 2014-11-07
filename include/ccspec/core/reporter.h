#ifndef CCSPEC_CORE_REPORTER_H_
#define CCSPEC_CORE_REPORTER_H_

#include <exception>
#include <list>
#include <vector>
#include "execution_result.h"
#include "formatter.h"

namespace ccspec {
namespace core {

class Reporter {
  public:
    explicit Reporter(const Formatter*);
    explicit Reporter(const std::vector<const Formatter*> formatters);

    void examplePassed(const ExecutionResult&);
    void exampleFailed(const ExecutionResult&);

  private:
    const std::vector<const Formatter*> formatters_;
    std::list<const std::exception*> failures_;
};

} // namespace core
} // namespace ccspec

#endif // CCSPEC_CORE_REPORTER_H_
