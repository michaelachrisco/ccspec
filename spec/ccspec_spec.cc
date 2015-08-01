#include <iostream>

#include "ccspec/core.h"

using std::cout;
using ccspec::core::formatters::DocumentationFormatter;
using ccspec::core::ExampleGroup;
using ccspec::core::Reporter;

namespace spec {
namespace matchers {

extern ExampleGroup* eq_spec;
extern ExampleGroup* be_spec;
extern ExampleGroup* bead_sort;

}  // namespace matchers
}  // namespace spec

int main() {
  DocumentationFormatter formatter(cout);
  Reporter reporter(&formatter);

  ExampleGroup* example_groups[] = {
    spec::matchers::be_spec,
    spec::matchers::eq_spec,
    spec::matchers::bead_sort,
  };
  bool succeeded = true;
  for (auto example_group : example_groups) {
    succeeded = example_group->run(reporter) && succeeded;
    delete example_group;
  }

  return !succeeded;
}
